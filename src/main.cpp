#include <Arduino.h>
#include <math.h>

const int numSamples = 256;
const int amplitude = 127;  // Amplitude of the sine wave
const int offset = 128;     // Offset to center the sine wave in the DAC range

const int X_DAC_PIN = 25;
const int Y_DAC_PIN = 26;

/*
settings

CH1 = 20mv per division
Then the span of the screen is 65% of 3.3v, or 2.2 volts. (DAC 0 - 166)

CH2 = 20mv per division
Then the span of the screen is 50% of 3.3v, or 1.65 volts. (DAC 0 - 128)

*/

void setX(int percentage) { dacWrite(X_DAC_PIN, percentage * 2.55); }
void setY(int percentage) { dacWrite(Y_DAC_PIN, percentage * 2.55); }
void setCoords(int x, int y) {
    setX(x);
    setY(y);
}

void setScaledCoords(int x, int y) { setCoords(x * 0.65, y * 0.5); }

void setup() {}

void loop() {
    setScaledCoords(0, 0);

    setScaledCoords(10, 0);

    setScaledCoords(20, 0);

    setScaledCoords(30, 0);

    setScaledCoords(40, 0);

    setScaledCoords(50, 0);

    setScaledCoords(60, 0);

    setScaledCoords(70, 0);

    setScaledCoords(80, 0);

    setScaledCoords(90, 0);

    setScaledCoords(100, 0);

    setScaledCoords(100, 10);

    setScaledCoords(100, 20);

    setScaledCoords(100, 30);

    setScaledCoords(100, 40);

    setScaledCoords(100, 50);

    setScaledCoords(100, 60);

    setScaledCoords(100, 70);

    setScaledCoords(100, 80);

    setScaledCoords(100, 90);

    setScaledCoords(100, 100);

    setScaledCoords(90, 100);

    setScaledCoords(80, 100);

    setScaledCoords(70, 100);

    setScaledCoords(60, 100);

    setScaledCoords(50, 100);

    setScaledCoords(40, 100);

    setScaledCoords(30, 100);

    setScaledCoords(20, 100);

    setScaledCoords(10, 100);

    setScaledCoords(0, 100);

    setScaledCoords(0, 90);

    setScaledCoords(0, 80);

    setScaledCoords(0, 70);

    setScaledCoords(0, 60);

    setScaledCoords(0, 50);

    setScaledCoords(0, 40);

    setScaledCoords(0, 30);

    setScaledCoords(0, 20);

    setScaledCoords(0, 10);
}
