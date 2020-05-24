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
const int DANCE_BUTTON_PIN = D6;


Thread random_sound_thread = Thread();
Thread dance_thread = Thread();
Thread left_arm_movement_thread = Thread();
Thread right_arm_movement_thread = Thread();

int button_state = 0;
int last_button_state = -1;

void setup(){
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(DANCE_BUTTON_PIN, INPUT);
  
  left_arm_servo.attach(LEFT_ARM_PIN);
  right_arm_servo.attach(RIGHT_ARM_PIN);

  // Thread configurations
  dance_thread.enabled = false;
  dance_thread.setInterval(5);
  dance_thread.onRun(dance);

  left_arm_movement_thread.setInterval(2000);
  left_arm_movement_thread.onRun(move_left_arm_random);
  right_arm_movement_thread.setInterval(2000);
  right_arm_movement_thread.onRun(move_right_arm_random);

  random_sound_thread.setInterval(1000);
  random_sound_thread.onRun(random_sound);

}

void loop(){
  button_state = digitalRead(DANCE_BUTTON_PIN);
  if (button_state != last_button_state && button_state == HIGH) {
    if (!is_dancing) {
      dance_thread.enabled = true;
    }
    else {
      stop_dance();
    }
  }
  last_button_state = button_state;

  if(dance_thread.shouldRun()){
    dance_thread.run();
  }

  if(random_sound_thread.shouldRun()){
    random_sound_thread.run();
    if (!is_sound) {
      random_sound_thread.enabled = true;
      int interval = random(3000, 7000);
      random_sound_thread.setInterval(interval);
    }
  }
 
  if(!is_dancing && left_arm_movement_thread.shouldRun()){
    left_arm_movement_thread.run();
    int interval = random(3000, 7000);
    left_arm_movement_thread.setInterval(interval);
  }

  if(!is_dancing && right_arm_movement_thread.shouldRun()){
    right_arm_movement_thread.run();
    int interval = random(3000, 7000);
    right_arm_movement_thread.setInterval(interval);
  }
}
