# Club Velocistas 2026

¡Hola!

Este repositorio es para ustedes. Aquí van a encontrar todo lo que vamos viendo en las sesiones del club: los códigos y las presentaciones de cada clase.

La idea es que sea su lugar de apoyo. Si se les olvidó cómo se conectaba algo, qué hacía una función o cómo iba el código de la clase, ven aquí a revisarlo con calma. No pasa nada por no acordarse de todo: para eso está este espacio. <3

---

## ¿Qué hay en este repositorio?

| Carpeta | ¿Qué contiene? |
|---|---|
| [`PDF sesiones/`](PDF%20sesiones/) | Las presentaciones (PPT en PDF) de cada sesión. |
| [`Sesion 1/`](Sesion%201/) | Motores con puente H: cómo moverlos y probarlos. |
| [`Sesion 2/`](Sesion%202/) | Calibración y lectura del sensor de línea QTR-8A. |
| [`Sesion 3/`](Sesion%203/) | Seguidor de línea con control **Proporcional (P)**. |
| [`Sesion 4/`](Sesion%204/) | Seguidor de línea con control **PID**. |
| [`Sesion 7/`](Sesion%207/) | Seguidor PID que detecta las **marcas laterales** (hitos). |

---

## Resumen de las sesiones

### Sesión 1: Motores y puente H
- Presentación: [Club-CYT-S01-Velocistas.pdf](PDF%20sesiones/Club-CYT-S01-Velocistas.pdf)
- Aprendimos a controlar los motores con un puente H y a variar su velocidad con PWM.
- Carpeta: [`Sesion 1/TestsMotores/`](Sesion%201/TestsMotores/) (o descarga [`TestsMotores.zip`](Sesion%201/TestsMotores.zip))
- Archivos:
  - `TestsMotores.ino`: al apretar el botón, acelera y frena la rueda izquierda, luego la derecha y después ambas juntas. Sirve para comprobar que los motores giran bien.
  - `motores.ino`: funciones para mover los motores. `motorSetup()` prepara los pines y `motores(velIzq, velDer)` mueve cada rueda (valores de -255 a 255; los negativos van hacia atrás).
  - `variables.h`: los pines de los motores.

### Sesión 2: Sensor de línea QTR-8A
- Presentación: [Club-CYT-S02-Velocistas.pdf](PDF%20sesiones/Club-CYT-S02-Velocistas.pdf)
- Conocimos el sensor QTR-8A, cómo calibrarlo y cómo leer la posición de la línea.
- Carpeta: [`Sesion 2/LectorLinea/`](Sesion%202/LectorLinea/) (o descarga [`LectorLinea.zip`](Sesion%202/LectorLinea.zip))
- Archivos:
  - `LectorLinea.ino`: calibra el sensor y muestra en el **Monitor Serie** (a 9600 baudios) la posición de la línea, de -255 a 255. Si aprietas el botón, cambia a mostrar el valor de cada sensor.
  - `seguidorLinea.ino`: funciones del sensor: `calibrar()`, `botonInicio()` y `leerPosicion()`.
  - `motores.ino`: las mismas funciones de motores de la Sesión 1.
  - `variables.h`: los pines de los motores, del botón y del buzzer.

### Sesión 3: Control Proporcional
- Presentación: [Club-CYT-S03-Velocistas.pdf](PDF%20sesiones/Club-CYT-S03-Velocistas.pdf)
- El robot corrige su giro según qué tan lejos está de la línea (el **error**).
- Carpeta: [`Sesion 3/SeguidorLinea_Proporcional_S3/`](Sesion%203/SeguidorLinea_Proporcional_S3/) (o descarga [`SeguidorLinea_Proporcional_S3.zip`](Sesion%203/SeguidorLinea_Proporcional_S3.zip))
- Archivos:
  - `SeguidorLinea_Proporcional_S3.ino`: el seguidor de línea. Calcula `giro = Kp * error` y se lo suma a una rueda y se lo resta a la otra.
  - `seguidorLinea.ino`, `motores.ino` y `variables.h`: las funciones del sensor, de los motores y los pines.

### Sesión 4: Control PID
- Presentación: [Club-CYT-S04-Velocistas.pdf](PDF%20sesiones/Club-CYT-S04-Velocistas.pdf)
- Le sumamos la parte **Integral** y **Derivativa** para que el robot siga la línea más rápido y más estable.
- Carpeta: [`Sesion 4/SeguidorLinea_PID_S4/`](Sesion%204/SeguidorLinea_PID_S4/) (o descarga [`SeguidorLinea_PID_S4.zip`](Sesion%204/SeguidorLinea_PID_S4.zip))
- Archivos:
  - `SeguidorLinea_PID_S4.ino`: el seguidor de línea con `giro = Kp * error + Ki * integral + Kd * derivada`. Suena el buzzer al empezar y al terminar la calibración.
  - `seguidorLinea.ino`, `motores.ino` y `variables.h`: las funciones del sensor, de los motores y los pines.

### Sesión 6: Marcas laterales y buzzer
- Presentación: [Club-CYT-S06-Velocistas.pdf](PDF%20sesiones/Club-CYT-S06-Velocistas.pdf)
- Conocimos las **marcas laterales** de la pista:
  - **Izquierdas:** avisan que viene un cambio de curvatura.
  - **Derechas:** solo hay 2, una al inicio y otra al final. Sirven para que el robot sepa cuándo detenerse.
- Para verlas usamos los sensores **QTR-1A** (izquierdo en `A7` y derecho en `A6`). Se leen con `analogRead()`, sin librería.
- También usamos el **buzzer** (pin `10`) con `tone(BUZZER, frecuencia, duración)`.
- Esta sesión fue de desafíos en clase, así que no tiene código en el repositorio.

### Sesión 7: Detección de hitos (huella digital)
- Presentación: [Club-CYT-S07-Velocistas.pdf](PDF%20sesiones/Club-CYT-S07-Velocistas.pdf)
- Usamos los sensores laterales para reconocer las marcas mientras el robot sigue la línea. Según lo que ven, el robot está en un estado `geo`:

  | `geo` | Izquierdo | Derecho | Significa |
  |---|---|---|---|
  | 0 | No | No | Sin marca |
  | 1 | Sí | No | Marca a la izquierda |
  | 2 | No | Sí | Marca a la derecha |
  | 3 | Sí | Sí | Cruce |

- El robot guarda los últimos estados (`l_geo`, `ll_geo`, `lll_geo`), su **huella digital**, para saber qué marca acaba de pasar.
- Carpeta: [`Sesion 7/SeguidorLinea_PID_Hitos_S7/`](Sesion%207/SeguidorLinea_PID_Hitos_S7/) (o descarga [`SeguidorLinea_PID_Hitos_S7.zip`](Sesion%207/SeguidorLinea_PID_Hitos_S7.zip))
- Archivos:
  - `SeguidorLinea_PID_Hitos_S7.ino`: el seguidor PID de la Sesión 4 más los hitos. Al encenderlo, el robot gira sobre sí mismo para calibrarse solo.
  - `hitos.ino`: la función `hitos()`, que detecta las marcas. Suena un tono distinto en cada tipo de marca, y en la **segunda marca derecha** el robot se detiene hasta que aprietes el botón.
  - `seguidorLinea.ino`, `motores.ino` y `variables.h`: las funciones del sensor, de los motores y los pines (ahora también los de `HIZ` y `HDE`).
- Si los sensores laterales no detectan bien las marcas, prueba cambiando la variable `umbral`.

---

## ¿Cómo uso los códigos?

1. Instala el [Arduino IDE](https://www.arduino.cc/en/software).
2. Instala la versión 3.1.0 de la librería **QTRSensors** (desde *Herramientas → Administrar bibliotecas*). Se usa desde la Sesión 2.
3. Descarga este repositorio (botón verde **Code → Download ZIP**), o descarga solo el `.zip` de la sesión que necesites y descomprímelo.
4. Entra a la carpeta de la sesión (por ejemplo `Sesion 4/SeguidorLinea_PID_S4/`) y abre el archivo `.ino` que tiene el mismo nombre que la carpeta.
   > Todos los archivos de una misma carpeta (`.ino` y `variables.h`) trabajan juntos, así que no los separes!! Arduino los abre como pestañas del mismo programa.
5. Conecta tu robot, selecciona la placa y el puerto, y ¡súbelo! ദ്ദി(˵ •̀ ᴗ - ˵ )
---

## Consejos

- **Antes de cambiar algo, guarda una copia.** Así siempre puedes volver a lo que funcionaba.
- **Prueba de a poco.** Cambia una cosa, súbela y observa qué pasa.
- **Ajustar las constantes (`Kp`, `Ki`, `Kd`, `Tp`) es parte del juego.** Cada robot es distinto, así que experimenta.
- **Equivocarse es parte de aprender.** Si algo no funciona, revisa las conexiones, lee los comentarios del código y pregunta sin miedo.

---

## Un mensaje para ustedes

Este repositorio está hecho con mucho cariño, pensando en cada uno de ustedes. Es lindo verlos aprender, equivocarse, intentarlo de nuevo y ver sus avances en cada sesión.

Sigan siendo curiosos, compartan lo que saben con sus compañeros y, sobre todo, disfruten aprendiendo!

Con cariño,
Ao y Mauri ♡

