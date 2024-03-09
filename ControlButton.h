#ifndef CONTROLBUTTON
#define CONTROLBUTTON

//joints
const int j1_up = 34;
const int j1_down =  35;
const int j2_up = 36;
const int j2_down =  37;
const int j3_up = 38;
const int j3_down =  39;
const int j4_up = 40;
const int j4_down =  41;
//record&play
const int recordBtn = 44;
const int playBtn = 45;

void setupControlButton() {
  //  button configuration
  pinMode(j1_up, INPUT);
  digitalWrite(j1_up, LOW);
  pinMode(j1_down, INPUT);
  digitalWrite(j1_down, LOW);
  pinMode(j2_up, INPUT);
  digitalWrite(j2_up, LOW);
  pinMode(j2_down, INPUT);
  digitalWrite(j2_down, LOW);
  pinMode(j3_up, INPUT);
  digitalWrite(j3_up, LOW);
  pinMode(j3_down, INPUT);
  digitalWrite(j3_down, LOW);
  pinMode(j4_up, INPUT);
  digitalWrite(j4_up, LOW);
  pinMode(j4_down, INPUT);
  digitalWrite(j4_down, LOW);
  
  //record and play
  pinMode(recordBtn, INPUT);
  digitalWrite(recordBtn, LOW);
  pinMode(playBtn, INPUT);
  digitalWrite(playBtn, LOW);
}

#endif
