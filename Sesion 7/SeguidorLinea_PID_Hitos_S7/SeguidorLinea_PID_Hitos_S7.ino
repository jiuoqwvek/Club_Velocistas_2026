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
float Kp = 0.14;
float Ki = 0;
float Kd = 0.1;

int integral = 0, ultimoError = 0, derivada = 0, contDer = 0;

int geo = 0;                             //Variable de estado que indica nuestro modo de geo
int l_geo = 0, ll_geo = 0, lll_geo = 0;  //Guardan nuestra huella digital
int umbral = 700;                        //umbral que consideraremos como negro

void setup() {
  // Inicializar los pines del motor
  motorSetup();

  // Inicializar los sensores QTR-1A
  pinMode(HIZ, INPUT);
  pinMode(HDE, INPUT);

  // Delay para dar tiempo a poner el Hermes en la pista
  delay(1000);

  // Indicadores de INICIO de calibracion
  tone(BUZZER, 440, 50);

  motores(30, -30);  // Gira solo mientras se calibra
  calibrar();        // Se calibra el sensor
  motores(0, 0);     // Deja de girar cuando termina

  // Indicador de final de calibracion
  tone(BUZZER, 880, 500);

  // Espera a que se apriete el botón para continuar
  botonInicio();

  // Delay para dar tiempo a poner soltar el Hermes antes de que avance
  delay(1000);
}

void loop() {
  // Llamamos a la funcion que maneja los hitos
  hitos();

  // Leemos la posicion, con valores entre -255 y 255
  int posicion = leerPosicion();

  int error = posicion - ref;

  integral = integral + error;

  derivada = error - ultimoError;

  int giro = (Kp * error) + (Ki * integral) + (Kd * derivada);

  int velIzq = Tp + giro;
  int velDer = Tp - giro;

  motores(velIzq, velDer);

  ultimoError = error;
}
