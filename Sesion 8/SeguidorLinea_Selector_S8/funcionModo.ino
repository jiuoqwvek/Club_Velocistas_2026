void funcionModo(int valor){
  Tp = Tp + valor;
  if (valor > 0) {
    tone(BUZZER, 523, 200);
    delay(200);
    tone(BUZZER, 783, 200);
    delay(200);
  } else {
    tone(BUZZER, 783, 200);
    delay(200);
    tone(BUZZER, 523, 200);
    delay(200);
  }
}

void selectorModo(){
  while (seguidor == false){
    hitos();
    if (digitalRead(BOTON) == 1){
      seguidor = true;
    }
  }
  tone(BUZZER, 880, 500);
  delay(500);
}