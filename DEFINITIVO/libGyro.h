#include "MPU9250.h"

MPU9250 mpu;

void initMPU() {

  Wire.begin();
  if (!mpu.setup(0x68)) {  // change to your own address
    Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
  }
}


String getYPR() {
  mpu.update();
  return String(mpu.getYaw(), 2) + "," + String(mpu.getPitch(), 2) + "," + String(mpu.getRoll(), 2);
}
