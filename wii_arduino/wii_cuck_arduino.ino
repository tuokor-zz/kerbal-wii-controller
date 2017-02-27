#include <Wire.h>
#include "nunchuk.h"

const unsigned int BAUD_RATE = 19200;

Nunchuk nunchuk;

typedef struct {
  uint8_t joyX;
  uint8_t joyY;
  int accelX;
  int accelY;
  int accelZ;
  uint8_t buttonZ : 1;
  uint8_t buttonC : 1;
} ChuckValues;

ChuckValues vals;

void setup() {
  Serial.begin(BAUD_RATE);
  nunchuk.initialize();
  calibrate();
}
void calibrate() {
  vals.accelX = nunchuk.x_acceleration();
  vals.accelY = nunchuk.y_acceleration();
  vals.accelZ = nunchuk.z_acceleration();
  vals.buttonZ = nunchuk.z_button();
  vals.buttonC = nunchuk.c_button();
  
}

void loop() {
  if (nunchuk.update()) {
    if(nunchuk.z_button() == 1) {
      calibrate();
    }
    int x = nunchuk.x_acceleration() - vals.accelX;
    int y = nunchuk.y_acceleration() - vals.accelY;
    int z = nunchuk.z_acceleration() - vals.accelZ;
    Serial.println(String(x)+","+String(y)+","+String(z));
    delay(50);
  }
}

