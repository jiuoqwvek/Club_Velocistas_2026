#include "variables.h"
#include <QTRSensors.h>
#define NUM_SENSORS 6             // Número sensores usados
#define NUM_SAMPLES_PER_SENSOR 4  // Muestras por sensor (DEJAR EN 4)
#define EMITTER_PIN 11            // Pin del emisor

// Se crea la variable que representa al sensor
QTRSensorsAnalog qtra((unsigned char[]){ 5, 4, 3, 2, 1, 0 }, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS];  // Lista para guardar las lecturas

bool mostrando_posicion = true, flag_posicion = false;

void setup() {
  // Inicializar los pines del motor
  motorSetup();

  Serial.begin(9600);

  // Indicadores de INICIO de calibracion
  tone(BUZZER, 440, 250);
  Serial.println("Iniciando Calibracion...");

  //Se calibra el sensor
  calibrar();
  
  // Indicadores de TERMINO de calibracion
  tone(BUZZER, 880, 200);
  Serial.println("Calibracion terminada...");

  //Espera a que se apriete el botón para continuar
  botonInicio();
}

void loop() {
  // Leemos la posicion, con valores entre -255 y 255
  int posicion = leerPosicion();

  // Selector para intercambiar entre mostrar la POSICION o el ARREGLO "sensorValues" 
  if (digitalRead(BOTON) == 1) {
    if (flag_posicion == false) {
      mostrando_posicion = !mostrando_posicion;
    }
    flag_posicion = true;
  } else {
    flag_posicion = false;
  }
  
  // Imprimir los valores segun la configuracion seleccionada
  if (mostrando_posicion) {
    Serial.println("Pos: " + String(posicion));
  } else {
    Serial.print("Valores: ");
    for (int i = 0; i < NUM_SENSORS; i++) {
      Serial.print("[" + String(sensorValues[i]) + "]");
      if (i < NUM_SENSORS - 1) {
        Serial.print(", ");
      }
    }
    Serial.println();
  }

  delay(250);
}