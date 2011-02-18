/*
  AeroQuad v2.2 - Feburary 2011
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

#include "FlightAngleProcessor.h"  
  
FlightAngleProcessor::FlightAngleProcessor(void) 
{
  _angle[ROLL] = 0;
  _angle[PITCH] = 0;
  _angle[YAW] = 0;
  _gyroAngle[ROLL] = 0;
  _gyroAngle[PITCH] = 0;
}
  
void FlightAngleProcessor::initialize() {}
void FlightAngleProcessor::calculate(float G_Dt) {}
float FlightAngleProcessor::getGyroUnbias(byte axis) {}
void FlightAngleProcessor::calibrate() {}
 
const float FlightAngleProcessor::getData(byte axis) 
{
  return _angle[axis];
}
  
const byte FlightAngleProcessor::getType(void) 
{
  // This is set in each subclass to identify which algorithm used
  return _type;
}


void FlightAngleProcessor::setGyroscope(Gyroscope *gyro)
{
  _gyro = gyro;
}

void FlightAngleProcessor::setAccelerometer(Accelerometer *accel)
{
  _accel = accel;
}
  
  
  
  