#include <Servo.h>
#include <Thread.h>

#include "sounds.h"
#include "movements.h"

Servo left_arm_servo;
Servo right_arm_servo;

// Initialize pin constants
const int BUZZER_PIN = D1;
const int LEFT_ARM_PIN = D2;
const int RIGHT_ARM_PIN = D3;

Thread sound_thread = Thread();
Thread movement_thread = Thread();



void setup(){
  pinMode(BUZZER_PIN, OUTPUT);
  left_arm_servo.attach(LEFT_ARM_PIN);
  right_arm_servo.attach(RIGHT_ARM_PIN);

  // Thread configuration
  movement_thread.setInterval(20);
  movement_thread.onRun(dance);

  sound_thread.setInterval(2000);
  sound_thread.onRun(sound_0);

}

void loop(){
  // First check if our Thread should be run
  if(sound_thread.shouldRun()){
    // Yes, the Thread should run, let's run it
    sound_thread.run();
  }

   if(movement_thread.shouldRun()){
    // Yes, the Thread should run, let's run it
    movement_thread.run();
  }
}


