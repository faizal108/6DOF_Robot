void checkButtons() {
  boolean j1_upstate = digitalRead(j1_up);
  boolean j1_downstate = digitalRead(j1_down);
  boolean j2_upstate = digitalRead(j2_up);
  boolean j2_downstate = digitalRead(j2_down);
  boolean j3_upstate = digitalRead(j3_up);
  boolean j3_downstate = digitalRead(j3_down);
  boolean j4_upstate = digitalRead(j4_up);
  boolean j4_downstate = digitalRead(j4_down);

  boolean recordBtnState = digitalRead(recordBtn);
  boolean playBtnState = digitalRead(playBtn);

  // #Joint-1
  if (j1_upstate == HIGH) {
    digitalWrite(DIR1_PIN, HIGH);
    while (j1_upstate == HIGH) {
      digitalWrite(PUL1_PIN, HIGH);
      digitalWrite(PUL1_PIN, LOW);
      delay(5);
      curPos1 = curPos1 + dl1;
      prevFlag = 1;
      j1_upstate = digitalRead(j1_up);
      Serial.println(curPos1);
    }
  }

  if (j1_downstate == HIGH) {
    digitalWrite(DIR1_PIN, LOW);
    while (j1_downstate == HIGH) {
      digitalWrite(PUL1_PIN, HIGH);
      digitalWrite(PUL1_PIN, LOW);
      delay(5);
      curPos1 = curPos1 - dl1;
      prevFlag = 1;
      j1_downstate = digitalRead(j1_down);
      Serial.println(curPos1);
    }
  }

  // #Joint-2
  if (j2_upstate == HIGH) {
    digitalWrite(DIR2_PIN, HIGH);
    while (j2_upstate == HIGH) {
      digitalWrite(PUL2_PIN, HIGH);
      digitalWrite(PUL2_PIN, LOW);
      delay(5);
      curPos2 = curPos2 + dl2;
      prevFlag = 1;
      j2_upstate = digitalRead(j2_up);
      Serial.println(curPos2);
    }
  }

  if (j2_downstate == HIGH) {
    digitalWrite(DIR2_PIN, LOW);
    while (j2_downstate == HIGH) {
      digitalWrite(PUL2_PIN, HIGH);
      digitalWrite(PUL2_PIN, LOW);
      delay(5);
      curPos2 = curPos2 - dl2;
      prevFlag = 1;
      j2_downstate = digitalRead(j2_down);
      Serial.println(curPos2);
    }
  }

  // #Joint 3
  if (j3_upstate == HIGH) {
    digitalWrite(DIR3_PIN, LOW);
    while (j3_upstate == HIGH) {
      digitalWrite(PUL3_PIN, HIGH);
      digitalWrite(PUL3_PIN, LOW);
      delay(5);
      curPos3 = curPos3 + dl3;
      prevFlag = 1;
      j3_upstate = digitalRead(j3_up);
      Serial.print("j3 : ");
      Serial.println(curPos3);
    }
  }

  if (j3_downstate == HIGH) {
    digitalWrite(DIR3_PIN, HIGH);
    while (j3_downstate == HIGH) {
      digitalWrite(PUL3_PIN, HIGH);
      digitalWrite(PUL3_PIN, LOW);
      delay(5);
      curPos3 = curPos3 - dl3;
      prevFlag = 1;
      j3_downstate = digitalRead(j3_down);
      Serial.println(curPos3);
    }
  }

  // #Joint-4
  while (j4_upstate == HIGH) {
    futPos4 = curPos4 + 1;
    float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
    float Jfinal[6] = {curPos1, curPos2, curPos3, futPos4, curPos5, curPos6};
    goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
    j4_upstate = digitalRead(j4_up);
    prevFlag = 1;
    Serial.println("j4");
  }
  while (j4_downstate == HIGH) {
    futPos4 = curPos4 - 1;
    float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
    float Jfinal[6] = {curPos1, curPos2, curPos3, futPos4, curPos5, curPos6};
    goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
    j4_downstate = digitalRead(j4_down);
    prevFlag = 1;
    Serial.println("j4");
  }

  // Record and Play
  if (recordBtnState == HIGH && prevFlag == 1) {
    String dataInS = dataIn.substring(4, dataIn.length());
    InSpeed[index] = curFinalSpeed;
    curFinalSpeed = (dataInS.toFloat() / 100) * 0.5e-4;
    Joint1[index] = curPos1;  // save position into the array
    Joint2[index] = curPos2;
    Joint3[index] = curPos3;
    Joint4[index] = curPos4;
    Joint5[index] = curPos5;
    Joint6[index] = curPos6;
    MaxSpeed[index] = curSpeed;
    FinSpeed[index] = curFinalSpeed;
    index++;                        // Increase the array index
    Serial.print("r1 : ");
    Serial.println(curPos1);
    Serial.println(Joint1[index - 1]);
    Serial.print("r2 : ");
    Serial.println(curPos2);
    Serial.println(Joint2[index - 1]);

    prevFlag = 0;
  }

  if (playBtnState == HIGH) {
    Serial.println("::::::::::::  PLAY  :::::::::::::::");
    float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
    float Jfinal[6] = {Joint1[0], Joint2[0], Joint3[0], Joint4[0], Joint5[0], Joint6[0]};
    goStrightLine(Jinitial, Jfinal, MaxSpeed[0], 0.75e-10, 0.0, 0.0);
    Serial.print("joint-1 : ");
    Serial.println(curPos1);
    for (int i = 0; i <= index - 2; i++) {  // Run through all steps(index)
      float Jinitial[6] = {Joint1[i], Joint2[i], Joint3[i], Joint4[i], Joint5[i], Joint6[i]};
      float Jfinal[6] = {Joint1[i + 1], Joint2[i + 1], Joint3[i + 1], Joint4[i + 1], Joint5[i + 1], Joint6[i + 1]};
      goStrightLine(Jinitial, Jfinal, MaxSpeed[i + 1], 0.75e-10, InSpeed[i + 1], FinSpeed[i + 1]);
      Serial.print("joint-1 : ");
      Serial.println(curPos1);
    }
    delay(2000);
    //test
//    float Jinitial2[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
//    float Jfinal2[6] = {0, 0, 0, 0, 0, 0};
//    goStrightLine(Jinitial2, Jfinal2, MaxSpeed[0], 0.3e-10, 0.0, 0.0);

    //end test

    if (curPos1 > 0) {
      digitalWrite(DIR1_PIN, LOW);

      while (digitalRead(JOINT1HOME) != HIGH) {
        digitalWrite(PUL1_PIN, HIGH);
        digitalWrite(PUL1_PIN, LOW);
        delay(10);
        curPos1 = curPos1 - dl1;
      }
      Serial.print("Joint-1 : ");
      Serial.println(curPos1);
      curPos1 = 0.0;
    }
//    if (curPos2 > 0) {
//      digitalWrite(DIR2_PIN, LOW);
//
//      while (digitalRead(JOINT2HOME) != HIGH) {
//        digitalWrite(PUL2_PIN, HIGH);
//        digitalWrite(PUL2_PIN, LOW);
//        delay(10);
//        curPos2 = curPos2 - dl2;
//      }
//      Serial.print("Joint-2 : ");
//      Serial.println(curPos2);
//      curPos2 = 0.0;
//    }
    if (curPos3 < 0) {
      digitalWrite(DIR3_PIN, LOW);

      while (digitalRead(JOINT3HOME) != HIGH) {
        digitalWrite(PUL3_PIN, HIGH);
        digitalWrite(PUL3_PIN, LOW);
        delay(2);
        curPos3 = curPos3 - dl3;
      }
      Serial.print("Joint-3 : ");
      Serial.println(curPos3);
      curPos3 = 0.0;
    }
  }

}
