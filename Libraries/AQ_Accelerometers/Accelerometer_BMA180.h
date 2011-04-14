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

#ifndef _AEROQUAD_ACCELEROMETER_BMA180_H_
#define _AEROQUAD_ACCELEROMETER_BMA180_H_

#include <Accelerometer.h>

#define BMA180_ADDRESS              0x40  // page 54 and 61 of datasheet
#define BMA180_MEMORY_ADDRESS       0x02
#define BMA180_BUFFER_SIZE          6
#define BMA180_RESET_ADDRESS        0x10
#define BMA180_RESET_VALUE          0xB6
#define BMA180_ACCEL_X_LSB_ADDRESS  0x02
#define BMA180_ACCEL_X_MSB_ADDRESS  0x03
#define BMA180_ACCEL_Y_LSB_ADDRESS  0x04
#define BMA180_ACCEL_Y_MSB_ADDRESS  0x05
#define BMA180_ACCEL_Z_LSB_ADDRESS  0x06
#define BMA180_ACCEL_Z_MSB_ADDRESS  0x07
#define BMA180_CTRL_REG0_ADDRESS    0x0d
#define BMA180_CTRL_REG1_ADDRESS    0x0e
#define BMA180_CTRL_REG2_ADDRESS    0x0f
#define BMA180_BW_TCS_ADDRESS       0x20
#define BMA180_OFFSET_LSB1_ADDRESS  0x35

#define BMA180_EE_W_VALUE           0x10  // 7.10.3 [page 47]

// filter values here are pre-mapped onto the register
// they are set in, bits 4-7 of bw_tcs
// Section 7.7.2 [page 28]
#define BMA180_LOW_PASS_FILTER_10HZ_VALUE    0x0f
#define BMA180_LOW_PASS_FILTER_20HZ_VALUE    0x1f
#define BMA180_LOW_PASS_FILTER_40HZ_VALUE    0x2f
#define BMA180_LOW_PASS_FILTER_75HZ_VALUE    0x3f
#define BMA180_LOW_PASS_FILTER_150HZ_VALUE   0x4f
#define BMA180_LOW_PASS_FILTER_300HZ_VALUE   0x5f
#define BMA180_LOW_PASS_FILTER_600HZ_VALUE   0x6f
#define BMA180_LOW_PASS_FILTER_1200HZ_VALUE  0x7f

// range select is bits 1-3 of offset_lsb1
#define BMA180_RANGE_SELECT_MASK 0xf1

// range select values here are pre-mapped onto the register
// they are set in, bits 1-3 of offset_lsb1
#define BMA180_RANGE_SELECT_1G_VALUE  0x00 << 1
#define BMA180_RANGE_SELECT_15G_VALUE 0x01 << 1 // actually 1.5g, not 15g ;)
#define BMA180_RANGE_SELECT_2G_VALUE  0x02 << 1
#define BMA180_RANGE_SELECT_3G_VALUE  0x03 << 1
#define BMA180_RANGE_SELECT_4G_VALUE  0x04 << 1
#define BMA180_RANGE_SELECT_8G_VALUE  0x05 << 1
#define BMA180_RANGE_SELECT_16G_VALUE 0x06 << 1

// from section 7.7.1 [page 28]
#define BMA180_MG_PER_LSB_AT_1G  0.13
#define BMA180_MG_PER_LSB_AT_15G 0.19
#define BMA180_MG_PER_LSB_AT_2G  0.25
#define BMA180_MG_PER_LSB_AT_3G  0.38
#define BMA180_MG_PER_LSB_AT_4G  0.50
#define BMA180_MG_PER_LSB_AT_8G  0.99
#define BMA180_MG_PER_LSB_AT_16G 1.98

class Accelerometer_BMA180 : public Accelerometer {
public:
  Accelerometer_BMA180();
  void initialize(void);
  void measure(void);
  void calibrate(void);	
};

#endif