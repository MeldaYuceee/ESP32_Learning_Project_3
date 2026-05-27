#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  // try to start the sensor
  if (!mpu.begin()) {
    Serial.println("Sensor not found or not connected");

    // stay here if it fails
    while (true) {
      delay(50);
    }
  }

  Serial.println("MPU ready, getting data...");
}

void loop() {

  sensors_event_t accelData, gyroData, tempData;

  // get data from sensor
  mpu.getEvent(&accelData, &gyroData, &tempData);

  // only printing acceleration for now
  float x = accelData.acceleration.x;
  float y = accelData.acceleration.y;
  float z = accelData.acceleration.z;

  Serial.print("x=");
  Serial.print(x);

  Serial.print("  y=");
  Serial.print(y);

  Serial.print("  z=");
  Serial.println(z);

  delay(400); // slow it down a bit
}