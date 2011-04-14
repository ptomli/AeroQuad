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

#include <Accelerometer.h>
#include <Axis.h>

Accelerometer::Accelerometer() {
  // for (byte axis = XAXIS; axis < LASTAXIS; axis++) {
  //   accelVector[axis] = 0;
  //   accelRaw[axis] = 0;
  //   accelZero[axis] = 0;
  // }
  // accelOneG = 0.0;
  // accelScaleFactor = 1.0;
  // smoothFactor = 1.0;
}

// const int Accelerometer::getData(byte axis)  {
//   return accelVector[axis];
// }
// 
// void Accelerometer::setZero(byte axis, int value)  {
//   accelZero[axis] = value;
// }
// 
// const int Accelerometer::getZero(byte axis)  {
//   return accelZero[axis];
// }
// 
// void Accelerometer::setOneG(float value)  {
//   accelOneG = value;
// }
// 
// const float Accelerometer::getOneG(void) {
//   return accelOneG;
// }
// 
// void Accelerometer::setSmoothFactor(float value)  {
//   smoothFactor = value;
// }
//  
// //Thanks ala42! Post: http://aeroquad.com/showthread.php?1369-The-big-enhancement-addition-to-2.0-code/page5
// int Accelerometer::findMedian(int *data, int arraySize) { 
//   int temp;
//   boolean done = 0;
//   byte i;
//   
//    // Sorts numbers from lowest to highest
//   while (done != 1) {        
//     done = 1;
//     for (i=0; i<(arraySize-1); i++) {
//       if (data[i] > data[i+1]) {     // numbers are out of order - swap
//         temp = data[i+1];
//         data[i+1] = data[i];
//         data[i] = temp;
//         done = 0;
//       }
//     }
//   }
//   
//   return data[arraySize/2]; // return the median value
// }
