#include "mbed.h"
#include "LIS3DSH.h"

// Initialize the serial interface
Serial pc(USBTX, USBRX);

// Initialize the I2C interface for the accelerometer
I2C i2c(I2C_SDA, I2C_SCL);

// Initialize the accelerometer
LIS3DSH acc(i2c);

// Function to compute the pitch angle from accelerometer data
float computeAngle(float x, float y, float z) {
    // Calculate the pitch angle in degrees
    float angle = atan2(y, sqrt(x * x + z * z)) * 180.0 / M_PI;
    return angle;
}

int main() {
    pc.printf("Starting accelerometer pitch calculation...\n");

    while (true) {
        // Read the accelerometer values
        float x = acc.readX();
        float y = acc.readY();
        float z = acc.readZ();

        // Compute the pitch angle
        float pitch = computeAngle(x, y, z);

        // Print the pitch angle
        pc.printf("Pitch angle: %.2f degrees\n", pitch);

        // Wait for 2 seconds
        wait(2.0);
    }
}