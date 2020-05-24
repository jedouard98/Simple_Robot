extern Servo left_arm_servo;
extern Servo right_arm_servo;

extern Thread dance_thread;


const int LEFT_ARM_DANCE_STARTING_POSITON = 0;
const int RIGHT_ARM_DANCE_STARTING_POSITON = 180;

int left_arm_position = 0;
int right_arm_position = 0;

bool is_forward_dance = true;
bool is_dancing = false;

void move_left_arm(int position) {
  left_arm_position = position;
  left_arm_servo.write(left_arm_position);
}

void move_left_arm_random() {
  int random_position = random(181);
  move_left_arm(random_position);
}

void move_right_arm(int position) {
  right_arm_position = position;
  right_arm_servo.write(right_arm_position);
}

void move_right_arm_random() {
  int random_position = random(181);
  move_right_arm(random_position);
}

void dance() {
  if (!is_dancing) {
    left_arm_position = LEFT_ARM_DANCE_STARTING_POSITON;
    right_arm_position = RIGHT_ARM_DANCE_STARTING_POSITON;
    is_dancing = true;
  }

  if (is_forward_dance) {
    move_left_arm(++left_arm_position);
    move_right_arm(--right_arm_position);
  }
  else {
    move_left_arm(--left_arm_position);
    move_right_arm(++right_arm_position);
  }

  if (left_arm_position > 180) {
    is_forward_dance = false;
  }

  if (left_arm_position < 0) {
    is_forward_dance = true;
  }
}

void stop_dance() {
  dance_thread.enabled = false;
  is_dancing = false;
}
