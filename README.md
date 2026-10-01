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
| [`Sesion 2/`](Sesion%202/) | Lectura del sensor de línea QTR-8A y primer seguidor de línea. |
| [`Sesion 3/`](Sesion%203/) | Seguidor de línea con control **Proporcional (P)**. |
| [`Sesion 4/`](Sesion%204/) | Seguidor de línea con control **PID**. |

---

## Resumen de las sesiones

### Sesión 1: Motores y puente H
- Presentación: [Club-CYT-S01-Velocistas.pdf](PDF%20sesiones/Club-CYT-S01-Velocistas.pdf)
- Aprendimos a controlar los motores con un puente H y a variar su velocidad con PWM.
- Carpeta: [`Sesion 1/TestsMotores/`](Sesion%201/TestsMotores/) (o descarga [`TestsMotores.zip`](Sesion%201/TestsMotores.zip))
- Archivos:
  - `TestsMotores.ino`: programa para probar que ambos motores funcionan.
  - `motores.ino`: funciones para mover los motores (`motorSetup()`, `motores(izq, der)`).
  - `variables.h`: los pines del robot (motores, botón y buzzer).

### Sesión 2: Sensor de línea QTR-8A
- Presentación: [Club-CYT-S02-Velocistas.pdf](PDF%20sesiones/Club-CYT-S02-Velocistas.pdf)
- Conocimos el sensor QTR-8A, cómo calibrarlo y cómo leer la posición de la línea.
- Carpeta: [`Sesion 2/LectorLinea/`](Sesion%202/LectorLinea/) (o descarga [`LectorLinea.zip`](Sesion%202/LectorLinea.zip))
- Archivos:
  - `LectorLinea.ino`: programa para leer el sensor y ver los valores.
  - `seguidorLinea.ino`: funciones del sensor (calibrar, leer posición, botón de inicio).

### Sesión 3: Control Proporcional
- Presentación: [Club-CYT-S03-Velocistas.pdf](PDF%20sesiones/Club-CYT-S03-Velocistas.pdf)
- El robot corrige su giro según qué tan lejos está de la línea (el **error**).
- Carpeta: [`Sesion 3/SeguidorLinea_Proporcional_S3/`](Sesion%203/SeguidorLinea_Proporcional_S3/) (o descarga [`SeguidorLinea_Proporcional_S3.zip`](Sesion%203/SeguidorLinea_Proporcional_S3.zip))
- Archivo principal: `SeguidorLinea_Proporcional_S3.ino`

### Sesión 4: Control PID
- Presentación: [Club-CYT-S04-Velocista.pdf](PDF%20sesiones/Club-CYT-S04-Velocista.pdf)
- Le sumamos la parte **Integral** y **Derivativa** para que el robot siga la línea más rápido y más estable.
- Carpeta: [`Sesion 4/SeguidorLinea_PID_S4/`](Sesion%204/SeguidorLinea_PID_S4/) (o descarga [`SeguidorLinea_PID_S4.zip`](Sesion%204/SeguidorLinea_PID_S4.zip))
- Archivo principal: `SeguidorLinea_PID_S4.ino`

---

## ¿Cómo uso los códigos?

1. Instala el [Arduino IDE](https://www.arduino.cc/en/software).
2. Instala la versión 3.1.0 de la librería **QTRSensors** (desde *Herramientas → Administrar bibliotecas*). Se usa desde la Sesión 2.
3. Descarga este repositorio (botón verde **Code → Download ZIP**), o descarga solo el `.zip` de la sesión que necesites.
4. Entra a la carpeta de la sesión (por ejemplo `Sesion 4/SeguidorLinea_PID_S4/`) y abre el archivo `.ino` que tiene el mismo nombre que la carpeta.
   > Todos los archivos de una misma carpeta (`.ino` y `variables.h`) trabajan juntos, así que no los separes!! Arduino los abre como pestañas del mismo programa.
5. Conecta tu robot, selecciona la placa y el puerto, y ¡súbelo!

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

Ao y Mauri
