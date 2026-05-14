// ---- Definición de pines ----
const int PIN_RX          = 5;  // Recibe la línea RS232
const int PIN_LED_DATO    = 6;  // LED: refleja cada bit de datos
const int PIN_LED_PARIDAD = 7;  // LED: ON=OK, parpadeo=error

const unsigned long BIT_DURATION = 1000;
const unsigned long HALF_BIT     = 500;  // Muestreo al centro del bit

byte bitsRecibidos[8];

byte calcularParidad(byte* bits, int longitud) {
  int contadorUnos = 0;
  for (int i = 0; i < longitud; i++) {
    if (bits[i] == 1) contadorUnos++;
  }
  return (contadorUnos % 2 == 0) ? 0 : 1;
}

void recibirTrama() {
  // Start bit ya detectado — alinearse al primer bit de datos
  delay(HALF_BIT);

  // Leer 8 bits de datos
  for (int i = 0; i < 8; i++) {
    bitsRecibidos[i] = digitalRead(PIN_RX);
    digitalWrite(PIN_LED_DATO, bitsRecibidos[i]);  // LED refleja el bit
    delay(BIT_DURATION);
  }

  // Leer y verificar paridad
  byte paridadRecibida  = digitalRead(PIN_RX); delay(BIT_DURATION);
  byte paridadCalculada = calcularParidad(bitsRecibidos, 8);

  if (paridadCalculada == paridadRecibida) {
    digitalWrite(PIN_LED_PARIDAD, HIGH);  // OK
    delay(2000);
    digitalWrite(PIN_LED_PARIDAD, LOW);
  } else {
    for (int i = 0; i < 5; i++) {        // Parpadeo = error
      digitalWrite(PIN_LED_PARIDAD, HIGH); delay(200);
      digitalWrite(PIN_LED_PARIDAD, LOW);  delay(200);
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RX, INPUT);
  pinMode(PIN_LED_DATO, OUTPUT);
  pinMode(PIN_LED_PARIDAD, OUTPUT);
}

void loop() {
  if (digitalRead(PIN_RX) == LOW) {  // Flanco ALTO→BAJO = start bit
    if (digitalRead(PIN_RX) == LOW) recibirTrama();
  }
}