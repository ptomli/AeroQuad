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

/* ----------- */

                                               // MSB -> LSB
#define BMA180_OFFSET_Z_ADDRESS           0x3a // offset_z<11:4> (msb)
#define BMA180_OFFSET_Y_ADDRESS           0x39 // offset_y<11:4> (msb)
#define BMA180_OFFSET_X_ADDRESS           0x38 // offset_x<11:4> (msb)
#define BMA180_OFFSET_T_ADDRESS           0x37 // offset_t<6:0> (msb), readout_12bit
#define BMA180_OFFSET_LSB2_ADDRESS        0x36 // offset_z<3:0> (lsb), offset_y<3:0> (lsb)
#define BMA180_OFFSET_LSB1_ADDRESS        0x35 // offset_x<3:0> (lsb), range<2:0>, smp_skip
#define BMA180_GAIN_Z_ADDRESS             0x34 // gain_z<6:0>, wake_up
#define BMA180_GAIN_Y_ADDRESS             0x33 // gain_y<6:0>, shadow_dis
#define BMA180_GAIN_X_ADDRESS             0x32 // gain_x<6:0>, dis_reg
#define BMA180_GAIN_T_ADDRESS             0x31 // gain_t<4:0>, tapsens_dur<2:0>
#define BMA180_TCO_Z_ADDRESS              0x30 // tco_z<5:0>, mode_config<1:0>
#define BMA180_TCO_Y_ADDRESS              0x2f // tco_y<5:0>, wake_up_dur<1:0>
#define BMA180_TCO_X_ADDRESS              0x2e // tco_x<5:0>, slope_dur<1:0>
#define BMA180_TCO_CD2_ADDRESS            0x2d // customer_data2<7:0>
#define BMA180_TCO_CD1_ADDRESS            0x2c // customer_data1<7:0>
#define BMA180_SLOPE_TH_ADDRESS           0x2b // slope_th<7:0>
#define BMA180_HIGH_TH_ADDRESS            0x2a // high_th<7:0>
#define BMA180_LOW_TH_ADDRESS             0x29 // low_th<7:0>
#define BMA180_TAPSENS_TH_ADDRESS         0x28 // tapsens_th<7:0>
#define BMA180_HIGH_DUR_ADDRESS           0x27 // hish_dur<6:0>, dis_i2c
#define BMA180_LOW_DUR_ADDRESS            0x26 // low_dur<6:0>, tco_range
#define BMA180_HIGH_LOG_INFO_ADDRESS      0x25 // 
#define BMA180_SLOPE_TAPSENS_INFO_ADDRESS 0x24 // 
#define BMA180_HY_ADDRESS                 0x23 // high_hy<4:0>, low_hy<4:2>
#define BMA180_CTRL_REG4_ADDRESS          0x22 // 
#define BMA180_CTRL_REG3_ADDRESS          0x21 //slope_alert, slope_int, high_int, low_int, tapsens_int, adv_int, new_data_int, lat_int
#define BMA180_BW_TCS_ADDRESS             0x20 // bw<3:0>, tcs<3:0>
#define BMA180_SOFT_RESET_ADDRESS         0x10 // soft_reset
#define BMA180_TEMP_ADDRESS               0x08 // temp<7:0>
#define BMA180_ACC_Z_MSB_ADDRESS          0x07 // acc_z<13:6> (msb)
#define BMA180_ACC_Z_LSB_ADDRESS          0x06 // acc_z<5:0> (lsb), 0, new_data_z
#define BMA180_ACC_Y_MSB_ADDRESS          0x05 // acc_y<13:6> (msb)
#define BMA180_ACC_Y_LSB_ADDRESS          0x04 // acc_y<5:0> (lsb), 0, new_data_y
#define BMA180_ACC_X_MSB_ADDRESS          0x03 // acc_x<13:6> (msb)
#define BMA180_ACC_X_LSB_ADDRESS          0x02 // acc_x<5:0> (lsb), 0, new_data_x

// § 7.7.1 range<2:0>
// these need to be bit-shifted left and mapped into BMA180_OFFSET_LSB1_ADDRESS
// NOTE: after changing to 8g or 16g range, a 400mg offset might occur, refer to datasheet
#define BMA180_RANGE_1_0G_VALUE  0x00
#define BMA180_RANGE_1_5G_VALUE  0x01
#define BMA180_RANGE_2_0G_VALUE  0x02
#define BMA180_RANGE_3_0G_VALUE  0x03
#define BMA180_RANGE_4_0G_VALUE  0x04
#define BMA180_RANGE_8_0G_VALUE  0x05
#define BMA180_RANGE_16_0G_VALUE 0x06

// resolutionin g/LSB at ranges defined above
#define BMA180_RESOLUTION_1_0G_VALUE  0.00013
#define BMA180_RESOLUTION_1_5G_VALUE  0.00019
#define BMA180_RESOLUTION_2_0G_VALUE  0.00025
#define BMA180_RESOLUTION_3_0G_VALUE  0.00038
#define BMA180_RESOLUTION_4_0G_VALUE  0.00050
#define BMA180_RESOLUTION_8_0G_VALUE  0.00099
#define BMA180_RESOLUTION_16_0G_VALUE 0.00198

// § 7.7.2 bw<3:0>
// bandwidth
#define BMA180_BANDWIDTH_10HZ_LOWPASS_VALUE   0x00
#define BMA180_BANDWIDTH_20HZ_LOWPASS_VALUE   0x01
#define BMA180_BANDWIDTH_40HZ_LOWPASS_VALUE   0x02
#define BMA180_BANDWIDTH_75HZ_LOWPASS_VALUE   0x03
#define BMA180_BANDWIDTH_150HZ_LOWPASS_VALUE  0x04
#define BMA180_BANDWIDTH_300HZ_LOWPASS_VALUE  0x05
#define BMA180_BANDWIDTH_600HZ_LOWPASS_VALUE  0x06
#define BMA180_BANDWIDTH_1200HZ_LOWPASS_VALUE 0x07
#define BMA180_BANDWIDTH_1HZ_HIGHPASS_VALUE   0x08
#define BMA180_BANDWIDTH_BANDPASS_VALUE       0x09

// § 7.7.3 mode_config
#define BMA180_MODE_CONFIG_LOW_NOISE_VALUE 0x00
#define BMA180_MODE_CONFIG_LOW_POWER_VALUE 0x03

// § 7.7.4 readout_12bit
#define BMA180_READOUT_12BIT_OFF_VALUE 0x00
#define BMA180_READOUT_12BIT_ON_VALUE  0x01

// § 7.7.5 smp_skip (sample skipping)
#define BMA180_SMP_SKIP_OFF_VALUE 0x00
#define BMA180_SMP_SKIP_ON_VALUE  0x01

// § 7.7.6 shadow_dis
// protection from mixing conversion cycles when reading MSB/LSB
#define BMA180_SHADOW_DIS_OFF_VALUE 0x00
#define BMA180_SHADOW_DIS_ON_VALUE  0x01

// § 7.10.6
// write this to BMA180_SOFT_RESET_ADDRESS and then wait 10 micro-S
#define BMA180_SHOFT_RESET_VALUE 0xb6

// § 7.12.3
#define BMA180_CHIP_ID_VALUE 0x03

// § 8.3.1
#define BMA180_SDO_VSS_ADDRESS   0x40
#define BMA180_SDO_VDDIO_ADDRESS 0x41

class Accelerometer_BMA180 : public Accelerometer {
public:
  Accelerometer_BMA180();
  void initialize(void);
  void measure(void);
  void calibrate(void);	
};

#endif