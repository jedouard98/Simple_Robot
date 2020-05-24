extern Servo left_arm_servo;
extern Servo right_arm_servo;

extern Thread movement_thread;


int left_arm_dance_position = 0;
int right_arm_dance_position = 180;
bool is_forward_dance = true;

void move_left_arm(int position) {
  left_arm_servo.write(position);
}

void move_right_arm(int position) {
  right_arm_servo.write(position);
}

void dance() {
  // move arms a little bit because of callback usage
  if (is_forward_dance) {
    move_left_arm(++left_arm_dance_position);
    move_right_arm(--right_arm_dance_position);
  }
  else {
    move_left_arm(--left_arm_dance_position);
    move_right_arm(++right_arm_dance_position);
  }

  if (left_arm_dance_position > 180) {
    is_forward_dance = false;
  }

  if (left_arm_dance_position < 0) {
    is_forward_dance = true;
  }
}

void stop_dance() {
  movement_thread.enabled = false;
}
