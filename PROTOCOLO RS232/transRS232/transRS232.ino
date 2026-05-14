// ---- Definición de pines ----
const int PIN_TX      = 4;   // Pin de transmisión (línea RS232 emulada)
const int PIN_RX      = 5;   // Pin de recepción (bidireccional)
const int PIN_BOTON   = 3;   // Pulsador: activa la transmisión
const int PIN_LED_TX  = 13;  // LED indicador de transmisión activa

const unsigned long BIT_DURATION = 1000; // 1 bit por segundo = 1000 ms

// Arreglo de 8 bits — Ejemplo: 'A' (0x41) LSB primero
byte datos[8] = {1, 0, 1, 0, 1, 0, 1, 0};

byte calcularParidad(byte* bits, int longitud) {
  int contadorUnos = 0;
  for (int i = 0; i < longitud; i++) {
    if (bits[i] == 1) contadorUnos++;
  }
  return (contadorUnos % 2 == 0) ? 0 : 1;  // Paridad PAR
}

void transmitirTrama() {
  digitalWrite(PIN_LED_TX, HIGH);

  // 1. START BIT — transición 1→0
  digitalWrite(PIN_TX, LOW);
  delay(BIT_DURATION);

  // 2. 8 BITS DE DATOS (LSB primero)
  for (int i = 0; i < 8; i++) {
    digitalWrite(PIN_TX, datos[i]);
    delay(BIT_DURATION);
  }

  // 3. BIT DE PARIDAD
  byte paridad = calcularParidad(datos, 8);
  digitalWrite(PIN_TX, paridad);
  delay(BIT_DURATION);

  // 4. STOP BIT — línea regresa a ALTO (idle)
  digitalWrite(PIN_TX, HIGH);
  delay(BIT_DURATION);

  digitalWrite(PIN_LED_TX, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TX, OUTPUT);
  pinMode(PIN_BOTON, INPUT_PULLUP);  // Pull-up interno
  digitalWrite(PIN_TX, HIGH);
}

void loop() {
  if (digitalRead(PIN_BOTON) == LOW) {  // Pulsado = LOW con INPUT_PULLUP
    if (digitalRead(PIN_BOTON) == LOW) {
      transmitirTrama();
      while (digitalRead(PIN_BOTON) == LOW);
    }
  }
}