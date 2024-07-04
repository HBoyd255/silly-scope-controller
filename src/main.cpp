#include <Arduino.h>
#include <math.h>

const int numSamples = 256;
const int amplitude = 127;  // Amplitude of the sine wave
const int offset = 128;     // Offset to center the sine wave in the DAC range

const int X_DAC_PIN = 25;
const int Y_DAC_PIN = 26;

// Define a struct to hold the coordinates
struct Point {
    int x;
    int y;
};

/*
settings

CH1 = 20mv per division
Then the span of the screen is 65% of 3.3v, or 2.2 volts. (DAC 0 - 166)

CH2 = 20mv per division
Then the span of the screen is 50% of 3.3v, or 1.65 volts. (DAC 0 - 128)

This gives a resolution of 166 by 128 pixels.

*/

void setPixels(int x, int y) {
    dacWrite(X_DAC_PIN, x);
    dacWrite(Y_DAC_PIN, y);
}

void setPercentages(int x, int y) { setPixels(x * 1.66, y * 1.28); }

void setup() {}

Point points[] = {{0, 0},     {10, 0},   {20, 0},   {30, 0},   {40, 0},
                  {50, 0},    {60, 0},   {70, 0},   {80, 0},   {90, 0},
                  {100, 0},   {100, 10}, {100, 20}, {100, 30}, {100, 40},
                  {100, 50},  {100, 60}, {100, 70}, {100, 80}, {100, 90},
                  {100, 100}, {90, 100}, {80, 100}, {70, 100}, {60, 100},
                  {50, 100},  {40, 100}, {30, 100}, {20, 100}, {10, 100},
                  {0, 100},   {0, 90},   {0, 80},   {0, 70},   {0, 60},
                  {0, 50},    {0, 40},   {0, 30},   {0, 20},   {0, 10}};

void loop() {
    for (int i = 0; i < sizeof(points) / sizeof(points[0]); ++i) {
        setPercentages(points[i].x, points[i].y);
    }
}
