/*
  AeroQuad v3.0 - February 2011
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

#include "Accelerometer_BMA180.h"

#include <Wire.h>

#include <AQMath.h>
#include <Axis.h>
#include <Device_I2C.h>

Accelerometer_BMA180::Accelerometer_BMA180() {
  // accelScaleFactor = G_2_MPS2(BMA180_MG_PER_LSB_AT_2G / 1000.0);
}

void Accelerometer_BMA180::initialize() {
  // soft reset and wait for at least 10 micro-S
  updateRegisterI2C(BMA180_SDO_VSS_ADDRESS, BMA180_SOFT_RESET_ADDRESS, BMA180_SOFT_RESET_VALUE);
  delay(10);

  // byte data;
  // 
  // updateRegisterI2C(BMA180_ADDRESS, BMA180_RESET_ADDRESS, BMA180_RESET_VALUE); // reset device
  // delay(10); // sleep 10 ms after reset (page 25)
  // 
  // updateRegisterI2C(BMA180_ADDRESS, BMA180_CTRL_REG0_ADDRESS, BMA180_EE_W_VALUE);  // enable writing to control registers
  // sendByteI2C(BMA180_ADDRESS, BMA180_BW_TCS_ADDRESS); // register bw_tcs (bits 4-7)
  // data = readByteI2C(BMA180_ADDRESS); // get current register value
  // updateRegisterI2C(BMA180_ADDRESS, BMA180_BW_TCS_ADDRESS, data & BMA180_LOW_PASS_FILTER_10HZ_VALUE); // set low pass filter to 10Hz (value = 0000xxxx)
  // 
  // sendByteI2C(BMA180_ADDRESS, BMA180_OFFSET_LSB1_ADDRESS); // Register offset_lsb1 (bits 1-3)
  // data = readByteI2C(BMA180_ADDRESS);
  // data &= BMA180_RANGE_SELECT_MASK;  // Clear range select bits
  // data |= BMA180_RANGE_SELECT_2G_VALUE;  // Set range select bits for +/-2g
  // updateRegisterI2C(BMA180_ADDRESS, BMA180_OFFSET_LSB1_ADDRESS, data);  // (value = xxxx010x)
}

void Accelerometer_BMA180::measure() {
  // sendByteI2C(BMA180_ADDRESS, BMA180_MEMORY_ADDRESS);
  // Wire.requestFrom(BMA180_ADDRESS, BMA180_BUFFER_SIZE);
  // 
  // // The following 3 lines read the accelerometer and assign it's data to accelVectorBits
  // // in the correct order and phase to suit the standard shield installation
  // // orientation.  See TBD for details.  If your shield is not installed in this
  // // orientation, this is where you make the changes.
  // // @todo ptomli the various supported shield installation orientations should be configurable
  // accelRaw[XAXIS] = ((Wire.receive()|(Wire.receive() << 8)) >> 2) - accelZero[XAXIS];
  // accelRaw[YAXIS] = accelZero[YAXIS] - ((Wire.receive()|(Wire.receive() << 8)) >> 2);
  // accelRaw[ZAXIS] = accelZero[ZAXIS] - ((Wire.receive()|(Wire.receive() << 8)) >> 2);
  // 
  // //for (byte axis = XAXIS; axis < LASTAXIS; axis++)
  //   //accelVector[axis] = smooth(accelRaw[axis] * accelScaleFactor, accelVector[axis], smoothFactor);
}

void Accelerometer_BMA180::calibrate() {
  // int findZero[FINDZERO];
  // int dataAddress;
  // 
  // for (byte calAxis = XAXIS; calAxis < LASTAXIS; calAxis++) {
  //   if (calAxis == XAXIS) {
  //     dataAddress = BMA180_ACCEL_X_LSB_ADDRESS;
  //   }
  //   else if (calAxis == YAXIS) {
  //     dataAddress = BMA180_ACCEL_Y_LSB_ADDRESS;
  //   }
  //   else if (calAxis == ZAXIS) {
  //     dataAddress = BMA180_ACCEL_Z_LSB_ADDRESS;
  //   }
  //   else {
  //     continue;
  //   }
  //   for (int i = 0; i < FINDZERO; i++) {
  //     sendByteI2C(BMA180_ADDRESS, dataAddress);
  //     findZero[i] = readReverseWordI2C(BMA180_ADDRESS) >> 2; // last two bits are not part of measurement
  //     delay(10);
  //   }
  //   accelZero[calAxis] = findMedian(findZero, FINDZERO);
  // }
  // 
  // // replace with estimated Z axis 0g value
  // accelZero[ZAXIS] = (accelZero[XAXIS] + accelZero[YAXIS]) / 2;
  // 
  // // store accel value that represents 1g
  // measure();
  // accelOneG = -accelVector[ZAXIS];
}