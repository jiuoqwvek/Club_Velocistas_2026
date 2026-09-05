void calibrar(){
  for (int i = 0; i < 400; i++) {
    qtra.calibrate();
  }
}

void botonInicio(){
  while (true) {
    if (digitalRead(BOTON) == 1) {
      break;
    }
  }
}

int leerPosicion(){
  //CODIGO SIN RESUMIR
  // Actualizar los valores del sensor QTR-8A
  qtra.read(sensorValues);

  // Línea blanca sobre fondo negro
  int posicion = qtra.readLine(sensorValues, true, true);
  // Línea negra sobre fondo blanco
  int posicion = qtra.readLine(sensorValues, true, false);

  // Transformar la lectura de estar entre 0 y 5000 a -255 y 255
  return map(posicion, 0, 5000, -255, 255);
}