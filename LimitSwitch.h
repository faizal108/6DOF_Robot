#ifndef LIMITSWITCH
#define LIMITSWITCH

#define JOINT1HOME 46
#define JOINT2HOME 48
#define JOINT3HOME 47

void setupLimitSwitch() {
  pinMode(JOINT1HOME, INPUT);
  pinMode(JOINT2HOME, INPUT);
  pinMode(JOINT3HOME, INPUT);
}

#endif
