void calibrar(){
  for (int i = 0; i < 200; i++) {
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
  // Actualizar los valores del sensor QTR-8A
  qtra.read(sensorValues);

  // Línea blanca sobre fondo negro
  int pos = qtra.readLine(sensorValues, true, true);
  // Línea negra sobre fondo blanco
  //int posicion = qtra.readLine(sensorValues, true, false);

  // Transformar la lectura de estar entre 0 y 5000 a -255 y 255
  pos = map(pos, 0, 5000, -255, 255);
  return pos;
}

void imprimirInfo(){
  Serial.println("Pos: " + String(posicion) + ", giro: " + String(giro) + ", velIzq: " + String(velIzq) + ", velDer: " + String(velDer));
}
