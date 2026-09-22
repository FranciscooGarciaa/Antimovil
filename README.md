# Antimóvil — Arduino phone-detox box

A box where you put your phone to disconnect for a while. An ultrasonic
sensor detects the phone inside, a 30-minute timer starts and, if you take
the phone out early, the buzzer keeps beeping until you put it back. If you
hold on, a victory melody plays.

## How it works

1. Put the phone in the box. When the sensor detects it closer than 5 cm,
   it waits 5 seconds and plays the start melody.
2. The 30-minute timer starts.
3. If the sensor stops seeing the phone (farther than 25 cm) during that
   time, the buzzer stays on and you are flagged as a cheater.
4. When the time is up, if you did not cheat, the victory melody plays and
   the box resets for the next session.

The duration is set in `timerDuration` (in milliseconds) inside the sketch.

## Components

| Component | Notes |
|---|---|
| Arduino (UNO or Nano) | Any board with 3 free digital pins |
| HC-SR04 ultrasonic sensor | Detects whether the phone is inside |
| Passive buzzer | Melodies and alarm |
| Wires and power | USB or battery |

### Wiring

| Arduino pin | Component |
|---|---|
| 11 | HC-SR04 `TRIG` |
| 10 | HC-SR04 `ECHO` |
| 9 | Buzzer |

## Files

- `código/caja_antimovil.ino` — Arduino sketch.
- `3D models/caja.stl` — box body.
- `3D models/cama-movil.stl` — bed where the phone rests.

## Build

1. Print both STL models.
2. Wire the sensor and the buzzer following the pin table.
3. Upload `caja_antimovil.ino` from the Arduino IDE.
4. Point the sensor at the phone bed and close the box.
