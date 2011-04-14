/*
  AeroQuad v3.0 - March 2011
  www.AeroQuad.com
  Copyright (c) 2011 Ted Carancho.  All rights reserved.
  An Open Source Arduino based multicopter.
 
  This program is free software: you can redistribute it and/or modify 
  it under the terms of the GNU General Public License as published by 
  the Free Software Foundation, either version 3 of the License, or 
  (at your option) any later version. 

  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  GNU General Public License for more details. 

  You should have received a copy of the GNU General Public License 
  along with this program. If not, see <http://www.gnu.org/licenses/>. 
*/

#include <Accelerometer_BMA180.h>

#include <Wire.h>

#include <AQMath.h>
#include <Axis.h>
#include <Device_I2C.h>

unsigned long timer;

Accelerometer_BMA180 accel;

void setup()
{
  Serial.begin(115200);
  Serial.println("Accelerometer library test (BMA180)");

  accel.initialize();
  accel.calibrate();
  timer = millis();
}

void loop(void) 
{
  if((millis() - timer) > 10) { // 100Hz
    timer = millis();
    accel.measure();

    Serial.print("X: ");
    // Serial.print(accel.getData(XAXIS));
    Serial.print(" Y: ");
    // Serial.print(accel.getData(YAXIS));
    Serial.print(" Z: ");
    // Serial.print(accel.getData(ZAXIS));
    Serial.println();
  }
}