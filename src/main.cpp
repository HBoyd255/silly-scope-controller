#include <Arduino.h>

class node {
   public:
    int x;
    int y;
    node* next;
    node* prev;
    node(int x, int y) {
        this->x = x;
        this->y = y;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
   public:
    node* head;
    node* tail;
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
};

LinkedList* pointList = new LinkedList();

// Add a node so that all the points are in the list in x order
void addNode(LinkedList* list, int x, int y) {
    node* newNode = new node(x, y);
    if (list->head == NULL) {
        // If list is empty, both head and tail point to the new node
        list->head = newNode;
        list->tail = newNode;
    } else {
        node* iterativeNode = list->head;

        // Find the node that is greater than the new node
        while (iterativeNode != NULL) {
            if (iterativeNode->x > newNode->x) {
                break;
            }
            iterativeNode = iterativeNode->next;
        }

        if (iterativeNode == NULL) {
            // If the new node is greater than all the nodes in the list
            // Append the new node to the end of the list
            newNode->prev = list->tail;
            list->tail->next = newNode;
            list->tail = newNode;
            return;
        } else {
            newNode->next = iterativeNode;
            newNode->prev = iterativeNode->prev;
            newNode->next->prev = newNode;
            newNode->prev->next = newNode;
        }
    }
}

const int X_DAC_PIN = 25;
const int Y_DAC_PIN = 26;

/*
settings

CH1 = 20mv per division
Then the span of the screen is 65% of 3.3v, or 2.2 volts. (DAC 0 - 166)

CH2 = 20mv per division
Then the span of the screen is 50% of 3.3v, or 1.65 volts. (DAC 0 - 128)

This gives a resolution of 166 by 128 pixels.

*/

void setPixels(int x, int y) {
    dacWrite(Y_DAC_PIN, y);
    dacWrite(X_DAC_PIN, x);
}

void setPercentages(int x, int y) { setPixels(x * 1.66, y * 1.28); }

void setup() {
    Serial.begin(9600);
    addNode(pointList, 0, 0);
    addNode(pointList, 10, 0);
    addNode(pointList, 20, 0);
    addNode(pointList, 30, 0);
    addNode(pointList, 40, 0);
    addNode(pointList, 50, 0);
    addNode(pointList, 60, 0);
    addNode(pointList, 70, 0);
    addNode(pointList, 80, 0);
    addNode(pointList, 90, 0);
    addNode(pointList, 100, 0);
    addNode(pointList, 100, 10);
    addNode(pointList, 100, 20);
    addNode(pointList, 100, 30);
    addNode(pointList, 100, 40);
    addNode(pointList, 100, 50);
    addNode(pointList, 100, 60);
    addNode(pointList, 100, 70);
    addNode(pointList, 100, 80);
    addNode(pointList, 100, 90);
    addNode(pointList, 100, 100);
    addNode(pointList, 90, 100);
    addNode(pointList, 80, 100);
    addNode(pointList, 70, 100);
    addNode(pointList, 60, 100);
    addNode(pointList, 50, 100);
    addNode(pointList, 40, 100);
    addNode(pointList, 30, 100);
    addNode(pointList, 20, 100);
    addNode(pointList, 10, 100);
    addNode(pointList, 0, 100);
    addNode(pointList, 0, 90);
    addNode(pointList, 0, 80);
    addNode(pointList, 0, 70);
    addNode(pointList, 0, 60);
    addNode(pointList, 0, 50);
    addNode(pointList, 0, 40);
    addNode(pointList, 0, 30);
    addNode(pointList, 0, 20);
    addNode(pointList, 0, 10);
    addNode(pointList, 15, 15);
}

void loop() {
    if (Serial.available() > 0) {
        // Read the serial command
        String serialCommand = Serial.readStringUntil('\n');

        // Example command format: "ADD_POINT 50 50"
        if (serialCommand.startsWith("ADD_POINT")) {
            int x, y;
            sscanf(serialCommand.c_str(), "ADD_POINT %d %d", &x, &y);
            addNode(pointList, x, y);
        }
    }

    // Serial.println("Points:");

    node* current = pointList->head;
    while (current != NULL) {
        setPercentages(current->x, current->y);
        delayMicroseconds(10);
        // Serial.print(" x:");
        // Serial.print(current->x);
        // Serial.print(" y:");
        // Serial.println(current->y);
        current = current->next;
    }
}
