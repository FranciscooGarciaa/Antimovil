const int trigPin = 11;
const int echoPin = 10;
const int buzzPin = 9;

long duracion;
int distancia;
unsigned long lastTimeDetected = 0;
unsigned long timerDuration = 1800000;  // 10 segundos
bool ObjectDetected = false;
bool timerStarted = false;
bool tramposo = false;

// Melodía del principio
int melodyStart[] = {
  523, 523, 587, 587, 659, 659, 698, 698, 784, 880, 988, 1047
};

// Duración de las notas principio
int noteDurationsStart[] = {
  200, 200, 200, 200, 200, 200, 200, 200, 300, 500, 500, 700
};

// Melodía de logro (victoria)
int melodyVictory[] = {
  523, 587, 659, 698, 784, 880, 988, 1047, 0, 1047, 988, 880, 784, 698, 659, 523
};

// Duración de las notas de logro (en milisegundos)
int noteDurationsVictory[] = {
  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 600
};

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Medición de la distancia con el sensor ultrasónico
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);  

  // Medir el tiempo que tarda en recibir el eco
  duracion = pulseIn(echoPin, HIGH);  

  // Calcular la distancia en cm (sonido viaja a 343 m/s, 0.034 cm/μs)
  distancia = duracion * 0.034 / 2;  

  // Mostrar la distancia en el monitor serie para pruebas
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Si el objeto está a menos de 5 cm, iniciamos la secuencia
  if (distancia < 5 && !ObjectDetected) {
    Serial.println("Objeto detectado");
    delay(5000);

    // Reproducir la melodía al comenzar
    playStartMelody();
    delay(1000);

    // Iniciar el temporizador
    lastTimeDetected = millis();
    ObjectDetected = true;
    timerStarted = true;
  }

  // Si el temporizador ya ha comenzado, verificamos la distancia
  if (ObjectDetected && timerStarted) {
    // Verificar si el objeto se aleja a más de 25 cm
    if (distancia > 25 && distancia != 1192) {
      digitalWrite(buzzPin, HIGH);
      tramposo = true;  // El buffer pita continuamente si te has llevado el movil.
    }

    // Si han pasado el tiempo, terminar la espera
    if (millis() - lastTimeDetected >= timerDuration) {
      // Reproducir la melodía de logro al finalizar
      if (!tramposo) {
        playVictoryMelody();
        delay(1000);
        digitalWrite(buzzPin, LOW);
      }

      Serial.println("Tiempo de espera completado");
      delay(5000);

      // Resetear el estado
      ObjectDetected = false;
      timerStarted = false;
    }
  }

  delay(100);
}

// Función para reproducir la melodía
void playStartMelody() {
  for (int thisNote = 0; thisNote < 12; thisNote++) {
    tone(buzzPin, melodyStart[thisNote], noteDurationsStart[thisNote]);  // Reproducir la nota
    delay(noteDurationsStart[thisNote] * 1.30);  // Ajuste de tiempo para evitar solapamiento de notas
  }
}

// Función para reproducir la melodía de logro (victoria)
void playVictoryMelody() {
  for (int thisNote = 0; thisNote < 16; thisNote++) {
    if (melodyVictory[thisNote] == 0) {
      noTone(buzzPin);  // Si es 0, hacer que el buzzer se detenga
    } else {
      tone(buzzPin, melodyVictory[thisNote], noteDurationsVictory[thisNote]);  // Reproducir la nota
    }
    delay(noteDurationsVictory[thisNote] * 1.30);  // Ajuste de tiempo para evitar solapamiento de notas
  }
}

