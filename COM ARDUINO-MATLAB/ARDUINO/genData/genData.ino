#include <math.h>

float y;
float t = 0;

void envia_datos(float x, float y) {
    Serial.print(y);
    Serial.print(" ");
    Serial.println(x);
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    y = sin(t);
    envia_datos(t, y);
    t = t + 0.01;
    delay(10);
}