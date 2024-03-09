#ifndef DRIVERS
#define DRIVERS

//driver for the axis 1
#define PUL1_PIN 22
#define DIR1_PIN 23
//driver for the axis 2
#define PUL2_PIN 24
#define DIR2_PIN 25
//driver for the axis 3
#define PUL3_PIN 26
#define DIR3_PIN 27
//driver for the axis 4
#define PUL4_PIN 28
#define DIR4_PIN 29
//driver for the axis 5
#define PUL5_PIN A6
#define DIR5_PIN A7
//driver for the axis 6
#define PUL6_PIN A0
#define DIR6_PIN A1

//enable pin for the axis 3, 2 and 1
#define EN321_PIN 32
#define EN4_PIN A8
#define EN5_PIN A2
#define EN6_PIN 38

boolean PULstat1 = 0;
boolean PULstat2 = 0;
boolean PULstat3 = 0;
boolean PULstat4 = 0;
boolean PULstat5 = 0;
boolean PULstat6 = 0;


void setupDrivers() {
  pinMode(PUL1_PIN, OUTPUT);
  pinMode(DIR1_PIN, OUTPUT);
  pinMode(PUL2_PIN, OUTPUT);
  pinMode(DIR2_PIN, OUTPUT);
  pinMode(PUL3_PIN, OUTPUT);
  pinMode(DIR3_PIN, OUTPUT);
  pinMode(PUL4_PIN, OUTPUT);
  pinMode(DIR4_PIN, OUTPUT);
  pinMode(PUL5_PIN, OUTPUT);
  pinMode(DIR5_PIN, OUTPUT);
  pinMode(PUL6_PIN, OUTPUT);
  pinMode(DIR6_PIN, OUTPUT);

  pinMode(EN321_PIN, OUTPUT);
  pinMode(EN4_PIN, OUTPUT);
  pinMode(EN5_PIN, OUTPUT);
  pinMode(EN6_PIN, OUTPUT);

  digitalWrite(PUL1_PIN, LOW); // gear ratio = 96/20 = 4.8
  digitalWrite(DIR1_PIN, LOW); //LOW = negative direction

  digitalWrite(PUL2_PIN, LOW); // gear ratio = 4
  digitalWrite(DIR2_PIN, LOW); //LOW = positive direction

  digitalWrite(PUL3_PIN, LOW); // gear ratio = 5
  digitalWrite(DIR3_PIN, LOW); //LOW = negative direction

  digitalWrite(PUL4_PIN, LOW); // gear ratio = 56/20 = 2.8
  digitalWrite(DIR4_PIN, LOW); //LOW = positive direction

  digitalWrite(PUL5_PIN, LOW); // gear ratio = 42/20 = 2.1
  digitalWrite(DIR5_PIN, LOW); //LOW = positive direction

  digitalWrite(PUL6_PIN, LOW); // gear ratio = 1
  digitalWrite(DIR6_PIN, LOW); //LOW = positive direction

  // all joints disabled!
  digitalWrite(EN321_PIN, HIGH);
  digitalWrite(EN4_PIN, HIGH);
  digitalWrite(EN5_PIN, HIGH);
  digitalWrite(EN6_PIN, HIGH);
}

#endif
