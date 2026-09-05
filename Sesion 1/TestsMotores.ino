#include "variables.h"

#define maxVel 180  // Maxima teorica es 255

void setup() {
  motorSetup();
  while (digitalRead(12) == 0)
    ;
}

void loop() {
  if (digitalRead(12) == 1) {

    // Rueda Izquierda
    for (int i = 0; i <= maxVel; i++) {
      motores(i, 0);
      delay(11);
    }
    for (int i = maxVel; i >= 0; i--) {
      motores(i, 0);
      delay(11);
    }

    motores(0, 0);
    delay(1000);

    // Rueda Derecha
    for (int i = 0; i <= maxVel; i++) {
      motores(0, i);
      delay(11);
    }
    for (int i = maxVel; i >= 0; i--) {
      motores(0, i);
      delay(11);
    }

    motores(0, 0);
    delay(1000);

    // Ambas ruedas
    for (int i = 0; i <= maxVel; i++) {
      motores(i, i);
      delay(11);
    }

    motores(0, 0);

  } else {
    motores(0, 0);
  }
}
