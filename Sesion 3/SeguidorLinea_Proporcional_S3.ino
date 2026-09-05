#include "variables.h"
#include <QTRSensors.h>
#define NUM_SENSORS 6             // Número sensores usados
#define NUM_SAMPLES_PER_SENSOR 4  // Muestras por sensor (DEJAR EN 4)
#define EMITTER_PIN 11            // Pin del emisor

// Se crea la variable que representa al sensor
QTRSensorsAnalog qtra((unsigned char[]){ 5, 4, 3, 2, 1, 0 }, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS];  // Lista para guardar las lecturas

int ref = 0;
int Tp = 20;
float Kp = 0.15;

int posicion = 0, error = 0, velIzq = 0, velDer = 0, giro = 0;

void setup() {
  // Inicializar los pines del motor
  motorSetup();

  // Se calibra el sensor
  calibrar();

  // Espera a que se apriete el botón para continuar
  botonInicio();
}

void loop() {
  // Leemos la posicion, con valores entre -255 y 255
  posicion = leerPosicion();

  error = posicion;

  giro = Kp * error;

  velIzq = Tp + giro;
  velDer = Tp - giro;

  motores(velIzq, velDer);
}



