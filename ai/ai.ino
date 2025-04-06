#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);
unsigned long lastTime = 0;  // Biến lưu thời gian trước đó

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  unsigned long currentTime = millis();
  
  // Kiểm tra nếu đã đủ 10 giây (10000 ms)
  if (currentTime - lastTime >= 10000) {
    lastTime = currentTime;  // Cập nhật thời gian trước đó
    
    mpu6050.update();
    Serial.print(millis()); Serial.print(",");
    Serial.print(mpu6050.getAccX()); Serial.print(",");
    Serial.print(mpu6050.getAccY()); Serial.print(",");
    Serial.println(mpu6050.getAccZ());
  }
}
