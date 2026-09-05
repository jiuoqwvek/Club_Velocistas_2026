void motorSetup() {
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void motores(int velIzq, int velDer) {
  // MOTOR 1
  if (velIzq > 0) {
    digitalWrite(pinA1, HIGH);
    digitalWrite(pinA2, LOW);
  } else if (velIzq < 0) {
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    velIzq = -velIzq;
  } else if (velIzq == 0){
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, LOW);
  }
  analogWrite(PWMA, constrain(velIzq,0,255));

  // MOTOR 2
  if (velDer > 0) {
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
  } else if (velDer < 0) {
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, HIGH);
    velDer = -velDer;
  } else if (velDer == 0){
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, LOW);
  }
  analogWrite(PWMB, constrain(velDer,0,255));
}
