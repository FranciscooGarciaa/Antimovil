# Antimóvil — caja anti-móvil con Arduino

Una caja donde guardas el teléfono para desconectar un rato. Un sensor
ultrasónico detecta que el móvil está dentro, arranca un temporizador de
30 minutos y, si lo sacas antes de tiempo, el buzzer pita hasta que lo
devuelves. Si aguantas, suena una melodía de victoria.

## Cómo funciona

1. Metes el móvil en la caja. Cuando el sensor lo detecta a menos de 5 cm,
   espera 5 segundos y suena la melodía de inicio.
2. Empieza el temporizador de 30 minutos.
3. Si durante ese tiempo el sensor deja de ver el móvil (más de 25 cm),
   el buzzer se queda pitando y quedas marcado como tramposo.
4. Al terminar el tiempo, si no has hecho trampa, suena la melodía de logro
   y la caja se reinicia para la siguiente sesión.

La duración se ajusta en `timerDuration` (en milisegundos) dentro del sketch.

## Componentes

| Componente | Notas |
|---|---|
| Arduino (UNO o Nano) | Cualquier placa con 3 pines digitales libres |
| Sensor ultrasónico HC-SR04 | Detecta si el móvil está dentro |
| Buzzer pasivo | Melodías y alarma |
| Cables y alimentación | USB o pila |

### Conexiones

| Pin Arduino | Componente |
|---|---|
| 11 | HC-SR04 `TRIG` |
| 10 | HC-SR04 `ECHO` |
| 9 | Buzzer |

## Archivos

- `código/caja_antimovil.ino` — sketch de Arduino.
- `3D models/caja.stl` — cuerpo de la caja.
- `3D models/cama-movil.stl` — cama donde se apoya el móvil.

## Montaje

1. Imprime los dos modelos STL.
2. Conecta el sensor y el buzzer según la tabla de pines.
3. Carga `caja_antimovil.ino` desde el IDE de Arduino.
4. Coloca el sensor apuntando a la cama del móvil y cierra la caja.
