// methods to move the robot around

#include <Arduino.h>
#include "../inc/motors.h"
#include "../inc/marcros.h"

// Sets up a motor's pins
void motorSetup(motor m)
{
    pinMode(m.motorEN,OUTPUT);
    pinMode(m.motorForward,OUTPUT);
    pinMode(m.motorReverse,OUTPUT);
}

// Moves a motor with a speed <speed>
// <fv> of 1 with <rv> of 0 moves motor forward
// <rv> of 1 with <fv> of 0 moves motor backward
void motorMovement(motor m, int speed,int fv, int rv)
{
    if (m.reverse == true and speed > 0)
    {
        analogWrite(m.motorEN,speed);
        digitalWrite(m.motorForward,1-fv);
        digitalWrite(m.motorReverse,1-rv);
    }
    else
    {
        analogWrite(m.motorEN,speed);
        digitalWrite(m.motorForward,fv);
        digitalWrite(m.motorReverse,rv);
    }
}

// Stops the robot when <encoderVal> > <threshold>
void runTillThresholdForward(int& encoderVal, int threshold)
{
    int initEnc = encoderVal
    while(encoderVal-initEnc < threshold)
    {
        continue;
    }
    off();
}

// Stops the robot when <encoderVal> < <threshold>
void runTillThresholdBackward(int& encoderVal, int threshold)
{
    int initEnc = encoderVal
    while(encoderVal-initEnc > threshold)
    {
        continue;
    }
    off();
}

// Moves robot forward with speed <speed>
void forward(int speed)
{
    for (int i = 0; i <= 3; i++)
    {
        motorMovement(motors[i],speed,1,0);
    }
}

// Moves robot forward at speed <speed> for <rotations> amount of wheel revolutions
void forwardTillRotation(int speed, float rotations)
{
    forward(speed);
    runTillThresholdForward(FL_enc.ticks,static_cast<int>(CM_TO_STEP * rotations));
}

// Moves robot backward with speed <speed>
void reverse(int speed)
{
    for (int i = 0; i <= 3; i++)
    {
        motorMovement(motors[i],speed,0,1);
    }
}

// Moves robot forward at speed <speed> for <rotations> amount of wheel revolutions
void reverseTillRotation(int speed, float rotations)
{
    reverse(speed);
    runTillThresholdBackward(FL_enc.ticks,static_cast<int>(CM_TO_STEP * rotations));
}

// Turns robot left, counterclockwise, at speed <speed>
void turnLeft(int speed, int degrees)
{
    motorMovement(FL,speed,0,1);
    motorMovement(BL,speed,0,1);
    motorMovement(FR,speed,1,0);
    motorMovement(BR,speed,1,0);

    runTillThresholdForward(FR_enc.ticks,static_cast<int>(DEG_TO_STEP * rotations));
}

// Turns robot right, clockwise, at speed <speed>
void turnRight(int speed,int degrees)
{
    motorMovement(FL,speed,1,0);
    motorMovement(BL,speed,1,0);
    motorMovement(FR,speed,0,1);
    motorMovement(BR,speed,0,1);

    runTillThresholdForward(FL_enc.ticks,static_cast<int>(DEG_TO_STEP * rotations));
}

// Stops all robot motors
void off()
{
    for (int i = 0; i <= 3; i++)
    {
        motorMovement(motors[i],0,0,0);
    }
}