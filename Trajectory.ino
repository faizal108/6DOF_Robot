void goTrajectory(float* Jf) {
  //execution
  int delF = 2;
  // joint #1
  if (Jf[0] - curPos1 > 0.0) { // positive direction of rotation
    digitalWrite(DIR1_PIN, HIGH);
    while (Jf[0] - curPos1 > dl1 / 2.0) {
      if (PULstat1 == 0) {
        digitalWrite(PUL1_PIN, HIGH);
        PULstat1 = 1;
      } else {
        digitalWrite(PUL1_PIN, LOW);
        PULstat1 = 0;
      }
      //curPos1 = Jf[0];
      curPos1 = curPos1 + dl1 / 2.0;
      if (Jf[0] - curPos1 > dl1 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  } else {
    digitalWrite(DIR1_PIN, LOW);
    while (-Jf[0] + curPos1 > dl1 / 2.0) {
      if (PULstat1 == 0) {
        digitalWrite(PUL1_PIN, HIGH);
        PULstat1 = 1;
      } else {
        digitalWrite(PUL1_PIN, LOW);
        PULstat1 = 0;
      }
      //curPos1 = Jf[0];
      curPos1 = curPos1 - dl1 / 2.0;
      if (-Jf[0] + curPos1 > dl1 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  }
  // joint #2
  if (Jf[1] - curPos2 > 0.0) { // positive direction of rotation
    digitalWrite(DIR2_PIN, HIGH);
    while (Jf[1] - curPos2 > dl2 / 2.0) {
      if (PULstat2 == 0) {
        digitalWrite(PUL2_PIN, HIGH);
        PULstat2 = 1;
      } else {
        digitalWrite(PUL2_PIN, LOW);
        PULstat2 = 0;
      }
      //curPos2 = Jf[1];
      curPos2 = curPos2 + dl2 / 2.0;
      if (Jf[1] - curPos2 > dl2 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  } else {
    digitalWrite(DIR2_PIN, LOW);
    while (-Jf[1] + curPos2 > dl2 / 2.0) {
      if (PULstat2 == 0) {
        digitalWrite(PUL2_PIN, HIGH);
        PULstat2 = 1;
      } else {
        digitalWrite(PUL2_PIN, LOW);
        PULstat2 = 0;
      }
      //curPos2 = Jf[1];
      curPos2 = curPos2 - dl2 / 2.0;
      if (-Jf[1] + curPos2 > dl2 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  }
  // joint #3
  if (Jf[2] - curPos3 > 0.0) { // positive direction of rotation
    digitalWrite(DIR3_PIN, LOW);
    while (Jf[2] - curPos3 > dl3 / 2.0) {
      if (PULstat3 == 0) {
        digitalWrite(PUL3_PIN, HIGH);
        PULstat3 = 1;
      } else {
        digitalWrite(PUL3_PIN, LOW);
        PULstat3 = 0;
      }
      //curPos3 = Jf[2];
      curPos3 = curPos3 + dl3 / 2.0;
      if (Jf[2] - curPos3 > dl3 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  } else {
    digitalWrite(DIR3_PIN, HIGH);
    while (-Jf[2] + curPos3 > dl3 / 2.0) {
      if (PULstat3 == 0) {
        digitalWrite(PUL3_PIN, HIGH);
        PULstat3 = 1;
      } else {
        digitalWrite(PUL3_PIN, LOW);
        PULstat3 = 0;
      }
      //curPos3 = Jf[2];
      curPos3 = curPos3 - dl3 / 2.0;
      if (-Jf[2] + curPos3 > dl3 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  }
  // joint #4
  if (Jf[3] - curPos4 > 0.0) { // positive direction of rotation
    digitalWrite(DIR4_PIN, HIGH);
    while (Jf[3] - curPos4 > dl4 / 2.0) {
      if (PULstat4 == 0) {
        digitalWrite(PUL4_PIN, HIGH);
        PULstat4 = 1;
      } else {
        digitalWrite(PUL4_PIN, LOW);
        PULstat4 = 0;
      }
      //curPos4 = Jf[3];
      curPos4 = curPos4 + dl4 / 2.0;
      if (Jf[3] - curPos4 > dl4 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  } else {
    digitalWrite(DIR4_PIN, LOW);
    while (-Jf[3] + curPos4 > dl4 / 2.0) {
      if (PULstat4 == 0) {
        digitalWrite(PUL4_PIN, HIGH);
        PULstat4 = 1;
      } else {
        digitalWrite(PUL4_PIN, LOW);
        PULstat4 = 0;
      }
      //curPos4 = Jf[3];
      curPos4 = curPos4 - dl4 / 2.0;
      if (-Jf[3] + curPos4 > dl4 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  }
  // joint #5
  if (Jf[4] - curPos5 > 0.0) { // positive direction of rotation
    digitalWrite(DIR5_PIN, HIGH);
    while (Jf[4] - curPos5 > dl5 / 2.0) {
      if (PULstat5 == 0) {
        digitalWrite(PUL5_PIN, HIGH);
        PULstat5 = 1;
      } else {
        digitalWrite(PUL5_PIN, LOW);
        PULstat5 = 0;
      }
      //curPos5 = Jf[4];
      curPos5 = curPos5 + dl5 / 2.0;
      if (Jf[4] - curPos5 > dl5 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  } else {
    digitalWrite(DIR5_PIN, LOW);
    while (-Jf[4] + curPos5 > dl5 / 2.0) {
      if (PULstat5 == 0) {
        digitalWrite(PUL5_PIN, HIGH);
        PULstat5 = 1;
      } else {
        digitalWrite(PUL5_PIN, LOW);
        PULstat5 = 0;
      }
      //curPos5 = Jf[4];
      curPos5 = curPos5 - dl5 / 2.0;
      if (-Jf[4] + curPos5 > dl5 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  }
  // joint #6
  if (Jf[5] - curPos6 > 0.0) { // positive direction of rotation
    digitalWrite(DIR6_PIN, HIGH);
    while (Jf[5] - curPos6 > dl6 / 2.0) {
      if (PULstat6 == 0) {
        digitalWrite(PUL6_PIN, HIGH);
        PULstat6 = 1;
      } else {
        digitalWrite(PUL6_PIN, LOW);
        PULstat6 = 0;
      }
      //curPos6 = Jf[5];
      curPos6 = curPos6 + dl6 / 2.0;
      if (Jf[5] - curPos6 > dl6 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  } else {
    digitalWrite(DIR6_PIN, LOW);
    while (-Jf[5] + curPos6 > dl6 / 2.0) {
      if (PULstat6 == 0) {
        digitalWrite(PUL6_PIN, HIGH);
        PULstat6 = 1;
      } else {
        digitalWrite(PUL6_PIN, LOW);
        PULstat6 = 0;
      }
      //curPos6 = Jf[5];
      curPos6 = curPos6 - dl6 / 2.0;
      if (-Jf[5] + curPos6 > dl6 / 2.0) {
        delayMicroseconds(delF);
      }
    }
  }
}
