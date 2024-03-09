void goStrightLine(float* xfi, float* xff, float vel0, float acc0, float velini, float velfin) {
  //
  float lmax = max(abs(xff[0] - xfi[0]), abs(xff[1] - xfi[1]));
  lmax = max(lmax, abs(xff[2] - xfi[2]));
  lmax = max(lmax, abs(xff[3] - xfi[3]));
  lmax = max(lmax, abs(xff[4] - xfi[4]));
  lmax = max(lmax, abs(xff[5] - xfi[5]));
  unsigned long preMil = micros();
  double l = 0.0;
  vel0 = min(vel0, sqrt(lmax * acc0 + 0.5 * velini * velini + 0.5 * velfin * velfin));
  unsigned long curMil = micros();
  unsigned long t = 0;
  double tap = vel0 / acc0 - velini / acc0;
  double lap = velini * tap + acc0 * tap * tap / 2.0;
  double lcsp = lmax - (vel0 * vel0 / 2.0 / acc0 - velfin * velfin / 2.0 / acc0);
  double tcsp = (lcsp - lap) / vel0 + tap;
  double tfin = vel0 / acc0 - velfin / acc0 + tcsp;
  while (curMil - preMil <= tfin) {
    t = curMil - preMil;
    //acceleration phase
    if (t <= tap) {
      l = velini * t + acc0 * t * t / 2.0;
    }
    //contant maximum speed phase
    if (t > tap && t <= tcsp) {
      l = lap + vel0 * (t - tap);
    }
    //deceleration phase
    if (t > tcsp) {
      l = lcsp + vel0 * (t - tcsp) - acc0 * (t - tcsp) * (t - tcsp) / 2.0;
    }

    //trajectory x and y as a function of l
    float Xx[6];
    Xx[0] = xfi[0] + (xff[0] - xfi[0]) / lmax * l;
    Xx[1] = xfi[1] + (xff[1] - xfi[1]) / lmax * l;
    Xx[2] = xfi[2] + (xff[2] - xfi[2]) / lmax * l;
    Xx[3] = xfi[3] + (xff[3] - xfi[3]) / lmax * l;
    Xx[4] = xfi[4] + (xff[4] - xfi[4]) / lmax * l;
    Xx[5] = xfi[5] + (xff[5] - xfi[5]) / lmax * l;

    goTrajectory(Xx);
    curMil = micros();
  }
}
