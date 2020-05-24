extern const int BUZZER_PIN;

extern Servo left_arm_servo;
extern Servo right_arm_servo;

extern Thread sound_thread;

int sequence_number = 0;
int chosen_sound = -1;

// Affirmative sound
// TODO: fix sequencing of this guy
void sound_0() {
  switch (sequence_number) {
    case 0:
      tone(BUZZER_PIN, 1000);
      sound_thread.setInterval(75);
      break;
    case 1:
      tone(BUZZER_PIN, 2000);
      sound_thread.setInterval(100);
      break;
    case 2:
      tone(BUZZER_PIN, 700);
      sound_thread.setInterval(40);
      break;
    case 3:
      tone(BUZZER_PIN, 1000);
      sound_thread.setInterval(90);
      break;
    case 4:
      tone(BUZZER_PIN, 1250);
      sound_thread.setInterval(75);
      break;
    case 5:
      tone(BUZZER_PIN, 2000);
      sound_thread.setInterval(100);
      break;
    case 6:
      tone(BUZZER_PIN, 1000);
      sound_thread.setInterval(150);
      break;
    case 7:
      noTone(BUZZER_PIN);
      sequence_number = 0;
      chosen_sound = -1;
      sound_thread.enabled = false;
      break;
  }
  sequence_number++;
}

// Happy sound
void sound_1() {
  switch (sequence_number) {
    case 0:
      tone(BUZZER_PIN, 2000);
      sound_thread.setInterval(175);
      break;
    case 1:
      tone(BUZZER_PIN, 1000);
      sound_thread.setInterval(50);
      break;
    case 2:
      tone(BUZZER_PIN, 750);
      sound_thread.setInterval(60);
      break;
    case 3:
      tone(BUZZER_PIN, 800);
      sound_thread.setInterval(90);
      break;
    case 4:
      tone(BUZZER_PIN, 1250);
      sound_thread.setInterval(75);
      break;
    case 5:
      tone(BUZZER_PIN, 1500);
      sound_thread.setInterval(200);
      break;
    case 6:
      noTone(BUZZER_PIN);
      sequence_number = 0;
      sound_thread.enabled = false;
      chosen_sound = -1;
      break;
  }
  sequence_number++;
}

// Sad sound
void sound_2() {
  switch (sequence_number) {
    case 0:
      tone(BUZZER_PIN, 2000);
      sound_thread.setInterval(100);
      break;
    case 1:
      tone(BUZZER_PIN, 1800);
      sound_thread.setInterval(60);
      break;
    case 2:
      tone(BUZZER_PIN, 1700);
      sound_thread.setInterval(60);
      break;
    case 3:
      tone(BUZZER_PIN, 1600);
      sound_thread.setInterval(60);
      break;
    case 4:
      tone(BUZZER_PIN, 1500);
      sound_thread.setInterval(60);
      break;
    case 5:
      tone(BUZZER_PIN, 1400);
      sound_thread.setInterval(60);
      break;
    case 6:
      noTone(BUZZER_PIN);
      sequence_number = 0;
      sound_thread.enabled = false;
      chosen_sound = -1;
      break;
  }
  sequence_number++;
}

// Attentive sound
void sound_3() {
  switch (sequence_number) {
    case 0:
      tone(BUZZER_PIN, 2000);
      sound_thread.setInterval(400);
      break;
    case 1:
      tone(BUZZER_PIN, 1500);
      sound_thread.setInterval(150);
      break;
    case 2:
      noTone(BUZZER_PIN);
      sequence_number = 0;
      sound_thread.enabled = false;
      chosen_sound = -1;
      break;
  }
  sequence_number++;
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
    chosen_sound = rand() % 4;
  }

  switch (random_chosen_sound) {
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
