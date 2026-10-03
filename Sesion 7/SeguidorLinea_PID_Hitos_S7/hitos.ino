void hitos() {
  
  // Sección para definir valores a "Hiz" y "Hde" -----------------------------
  int Hiz = analogRead(HIZ);  //Leemos el estado de ambos sensores
  int Hde = analogRead(HDE);

  if (Hiz < umbral) {
    Hiz = 1;  //El hito izquierdo está activado
  } else {
    Hiz = 0;  //El hito izquierdo no está activado
  }

  if (Hde < umbral) {
    Hde = 1;  //El hito derecho está activado
  } else {
    Hde = 0;  //El hito derecho no está activado
  }

  // Sección para definir valores a "geo" -----------------------------------
  if (Hiz == 0 && Hde == 0) {
    geo = 0;
  }
  if (Hiz == 0 && Hde == 0) {
    geo = 1;
  }
  if (Hiz == 0 && Hde == 0) {
    geo = 2;
  }
  if (Hiz == 0 && Hde == 0) {
    geo = 3;
  }


  // Sección para definir valores ejecutar acciones de hitos ----------------

  if (geo != l_geo) {  // Hubo un cambio del geo actual y el anterior?

    if (geo == 0 && l_geo == 1 && ll_geo == 0) {
      funcionHitoIz();  //Acciones para hito izquierdo
    }
    if (geo == 0 && l_geo == 2 && ll_geo == 0) {
      funcionHitoDe();  //Acciones para hito derecho
    }
    if (geo == 0 && ((l_geo == 3) || (ll_geo == 3) || (lll_geo == 3))) {
      funcionCruce();  //Acciones para hito de cruce
    }
    //Actualizar historial de los últimos 3 geos detectados
    lll_geo = ll_geo;
    ll_geo = l_geo;
    l_geo = geo;
  }
}

void funcionHitoIz(){
  tone(BUZZER, 660, 200);
}
void funcionHitoDe(){
  tone(BUZZER, 880, 200);
}
void funcionCruce(){
  tone(BUZZER, 440, 200);
}
