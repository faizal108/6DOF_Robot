#ifndef INITIALCONFIG
#define INITIALCONFIG

double curPos1 = 0.0;
double curPos2 = 0.0;
double curPos3 = 0.0;
double curPos4 = 0.0;
double curPos5 = 0.0;
double curPos6 = 0.0;


int prevFlag = 1; //no joint moved

//SoftwareSerial Bluetooth(29, 31); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)
String dataIn = ""; //variable to store the bluetooth command
double futPos1 = 0.0;
double futPos2 = 0.0;
double futPos3 = 0.0;
double futPos4 = 0.0;
double futPos5 = 0.0;
double futPos6 = 0.0;
double curSpeed = 5 * 0.5e-4; // high speed : .6 , .7 , .8   LOW speed : .5, .4, .3, .2
double curFinalSpeed = 0.0;


float Joint1[50], Joint2[50], Joint3[50], Joint4[50], Joint5[50], Joint6[50], MaxSpeed[50], InSpeed[50], FinSpeed[50];

int index = 0; //index corresonding to the robot position

#endif
