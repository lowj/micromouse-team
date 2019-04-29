// header file for motor controls

#ifndef MOTORS
#define MOTORS

#include "macros.h"

void motorSetup(motor m);

void motorMovement(motor m, int speed,int fv, int rv);

void runTillThresholdForward(int& encoderVal, int threshold);

void runTillThresholdBackward(int& encoderVal, int threshold);

void forward(int speed);

void forwardTillRotation(int speed, float rotations);

void reverse(int speed);

void turnLeft(int speed, int degrees);

void turnRight(int speed, int degrees);

void off();

#endif