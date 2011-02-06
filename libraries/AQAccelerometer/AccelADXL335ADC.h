/*
  AeroQuad v2.1 - January 2011
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

#ifndef _ACCEL_ADXL335_ADC_H_
#define _ACCEL_ADXL335_ADC_H_

#include <Accelerometer.h>
#include <AQADC.h>

class AccelADXL335ADC : public Accelerometer {
private:
  int findZero[FINDZERO];
  int rawADC;
  AQADC* _aqAdc;

public:
  AccelADXL335ADC(AQADC aqAdc);
  
  void initialize(void);
  
  void measure(void);

  const int getFlightData(byte axis);
  
  // Allows user to zero accelerometers on command
  void calibrate(void);

  void calculateAltitude(void);
};

#endif