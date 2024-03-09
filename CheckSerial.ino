void checkSerial(){
  if (Serial.available() > 0) {
    dataIn = Serial.readString();  // Read the data as string
    Serial.println(dataIn);
    //Serial.println(dataIn);
    if (dataIn == "enable") {
      digitalWrite(EN321_PIN, LOW);
      digitalWrite(EN4_PIN, LOW);
      digitalWrite(EN5_PIN, LOW);
      digitalWrite(EN6_PIN, LOW);
      Serial.println("All joint are enabled");
    }

    if (dataIn == "disable") {
      digitalWrite(EN321_PIN, HIGH);
      digitalWrite(EN4_PIN, HIGH);
      digitalWrite(EN5_PIN, HIGH);
      digitalWrite(EN6_PIN, HIGH);
      Serial.println("All joint are enabled");
    }

    if (dataIn.startsWith("s6")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      futPos6 = dataInS.toFloat();
      float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      float Jfinal[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, futPos6};
      goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
    }

    if (dataIn.startsWith("s5")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      futPos5 = dataInS.toFloat();
      float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      float Jfinal[6] = {curPos1, curPos2, curPos3, curPos4, futPos5, curPos6};
      Serial.println(futPos5);
      goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
    }

    if (dataIn.startsWith("s4")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      futPos4 = dataInS.toFloat();
      float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      float Jfinal[6] = {curPos1, curPos2, curPos3, futPos4, curPos5, curPos6};
      Serial.println(futPos4);
      goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
    }

    if (dataIn.startsWith("s3")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      futPos3 = dataInS.toFloat();
      float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      float Jfinal[6] = {curPos1, curPos2, futPos3, curPos4, curPos5, curPos6};
      Serial.println(futPos3);
      goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
    }

    if (dataIn.startsWith("s2")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      futPos2 = dataInS.toFloat();
      float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      float Jfinal[6] = {curPos1, futPos2, curPos3, curPos4, curPos5, curPos6};
      Serial.println(futPos2);
      goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
    }

    if (dataIn.startsWith("s1")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      futPos1 = dataInS.toFloat();
      float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      float Jfinal[6] = {futPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      Serial.println(futPos1);
      goStrightLine(Jinitial, Jfinal, curSpeed, 0.75e-10, 0.0, 0.0);
      prevFlag = 1;
    }

    // set the maximum speed for the move
    if (dataIn.startsWith("ss")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      curSpeed = (dataInS.toFloat() / 100) * 0.5e-4;
      Serial.print("curSpeed : ");
      Serial.println(curSpeed);
    }

    // If button "SAVE" is pressed
    if (dataIn.startsWith("save")) {
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
      Serial.print("curFinalSpeed : ");
      Serial.println(curFinalSpeed);
      Serial.print("curSpeed : ");
      Serial.println(curSpeed);
    }

    if ( dataIn == "reset") {
      index = 0;  // Index to 0
    }

    if (dataIn.startsWith("run")) {

      float Jinitial[6] = {curPos1, curPos2, curPos3, curPos4, curPos5, curPos6};
      float Jfinal[6] = {Joint1[0], Joint2[0], Joint3[0], Joint4[0], Joint5[0], Joint6[0]};
      goStrightLine(Jinitial, Jfinal, MaxSpeed[0], 0.75e-10, 0.0, 0.0);
      for (int i = 0; i <= index - 2; i++) {  // Run through all steps(index)
        float Jinitial[6] = {Joint1[i], Joint2[i], Joint3[i], Joint4[i], Joint5[i], Joint6[i]};
        float Jfinal[6] = {Joint1[i + 1], Joint2[i + 1], Joint3[i + 1], Joint4[i + 1], Joint5[i + 1], Joint6[i + 1]};
        goStrightLine(Jinitial, Jfinal, MaxSpeed[i + 1], 0.75e-10, InSpeed[i + 1], FinSpeed[i + 1]);
      }
    }

  }

}
