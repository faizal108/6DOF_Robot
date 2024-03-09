void calibration() {
  
  digitalWrite(DIR1_PIN, LOW);
  digitalWrite(DIR2_PIN, LOW);
  digitalWrite(DIR3_PIN, LOW);

  while (digitalRead(JOINT1HOME) != HIGH) {
    digitalWrite(PUL1_PIN, HIGH);
    digitalWrite(PUL1_PIN, LOW);
    delay(2);
  }
  Serial.println("Joint-1 : Calibration Done");

  while (digitalRead(JOINT2HOME) != HIGH) {
    digitalWrite(PUL2_PIN, HIGH);
    digitalWrite(PUL2_PIN, LOW);
    delay(2);
  }
  Serial.println("Joint-2 : Calibration Done");
//  while (digitalRead(JOINT3HOME) != HIGH) {
//    digitalWrite(PUL3_PIN, HIGH);
//    digitalWrite(PUL3_PIN, LOW);
//    delay(2);
//  }
  Serial.println("Joint-3 : Calibration Done");
  
  curPos1 = 0.0;
  curPos2 = 0.0;
  curPos3 = 0.0;

  calibrationStatus = true;
}
