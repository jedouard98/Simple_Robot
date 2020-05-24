extern const int BUZZER_PIN;

extern Servo left_arm_servo;
extern Servo right_arm_servo;

extern Thread random_sound_thread;

int sequence_number = 0;
int chosen_sound = -1;
bool is_sound = false;

// Affirmative sound
void sound_0() {
  switch (sequence_number) {
    case 0:
      is_sound = true;
      sequence_number++;
      tone(BUZZER_PIN, 1000);
      random_sound_thread.setInterval(75);
      break;
    case 1:
      sequence_number++;
      tone(BUZZER_PIN, 2000);
      random_sound_thread.setInterval(100);
      break;
    case 2:
      sequence_number++;
      tone(BUZZER_PIN, 700);
      random_sound_thread.setInterval(40);
      break;
    case 3:
      sequence_number++;
      tone(BUZZER_PIN, 1000);
      random_sound_thread.setInterval(90);
      break;
    case 4:
      sequence_number++;
      tone(BUZZER_PIN, 1250);
      random_sound_thread.setInterval(75);
      break;
    case 5:
      sequence_number++;
      tone(BUZZER_PIN, 2000);
      random_sound_thread.setInterval(100);
      break;
    case 6:
      sequence_number++;
      tone(BUZZER_PIN, 1000);
      random_sound_thread.setInterval(150);
      break;
    case 7:
      is_sound = false;
      noTone(BUZZER_PIN);
      sequence_number = 0;
      chosen_sound = -1;
      random_sound_thread.enabled = false;
      break;
  }
}

// Happy sound
void sound_1() {
  switch (sequence_number) {
    case 0:
      is_sound = true;
      sequence_number++;
      tone(BUZZER_PIN, 2000);
      random_sound_thread.setInterval(175);
      break;
    case 1:
      sequence_number++;
      tone(BUZZER_PIN, 1000);
      random_sound_thread.setInterval(50);
      break;
    case 2:
      sequence_number++;
      tone(BUZZER_PIN, 750);
      random_sound_thread.setInterval(60);
      break;
    case 3:
      sequence_number++;
      tone(BUZZER_PIN, 800);
      random_sound_thread.setInterval(90);
      break;
    case 4:
      sequence_number++;
      tone(BUZZER_PIN, 1250);
      random_sound_thread.setInterval(75);
      break;
    case 5:
      sequence_number++;
      tone(BUZZER_PIN, 1500);
      random_sound_thread.setInterval(200);
      break;
    case 6:
      is_sound = false;
      noTone(BUZZER_PIN);
      sequence_number = 0;
      random_sound_thread.enabled = false;
      chosen_sound = -1;
      break;
  }
}

// Sad sound
void sound_2() {
  switch (sequence_number) {
    case 0:
      is_sound = true;
      sequence_number++;
      tone(BUZZER_PIN, 2000);
      random_sound_thread.setInterval(100);
      break;
    case 1:
      sequence_number++;
      tone(BUZZER_PIN, 1800);
      random_sound_thread.setInterval(60);
      break;
    case 2:
      sequence_number++;
      tone(BUZZER_PIN, 1700);
      random_sound_thread.setInterval(60);
      break;
    case 3:
      sequence_number++;
      tone(BUZZER_PIN, 1600);
      random_sound_thread.setInterval(60);
      break;
    case 4:
      sequence_number++;
      tone(BUZZER_PIN, 1500);
      random_sound_thread.setInterval(60);
      break;
    case 5:
      sequence_number++;
      tone(BUZZER_PIN, 1400);
      random_sound_thread.setInterval(60);
      break;
    case 6:
      is_sound = false;
      noTone(BUZZER_PIN);
      sequence_number = 0;
      random_sound_thread.enabled = false;
      chosen_sound = -1;
      break;
  }
}

// Attentive sound
void sound_3() {
  switch (sequence_number) {
    case 0:
      is_sound = true;
      sequence_number++;
      tone(BUZZER_PIN, 2000);
      random_sound_thread.setInterval(400);
      break;
    case 1:
      sequence_number++;
      tone(BUZZER_PIN, 1500);
      random_sound_thread.setInterval(150);
      break;
    case 2:
      is_sound = false;
      noTone(BUZZER_PIN);
      sequence_number = 0;
      random_sound_thread.enabled = false;
      chosen_sound = -1;
      break;
  }
}

void affirm_sound() {
  sound_0();
}

void happy_sound() {
  sound_1();
}

void sad_sound() {
  sound_2();
}

void attentive_sound() {
  sound_3();
}

void random_sound() {
  if (chosen_sound == -1) {
    chosen_sound = random(4);
  }

  switch (chosen_sound) {
    case 0:
      sound_0();
      break;
    case 1:
      sound_1();
      break;
    case 2:
      sound_2();
      break;
    case 3:
      sound_3();
      break;
  }
}
