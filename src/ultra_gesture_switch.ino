#include "utils/sensor_functions.h"  // Inclui funções de A

// Outros includes se precisar
#include <Arduino.h>

// Defines extras (ex.: pinos LEDs)
const int ledPins[5] = {2, 3, 4, 5, 6};


void setup() {
  // Configura pinos (do header)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Sistema Iniciado - Funcoes Modulares");
}

void loop() {
  float rawDist = get_distance();  // Chama função de A
  float filtered = check_noise(rawDist);  // Usa em B
  handle_gesture(filtered);  // Processa

  delay(100);  // Loop responsivo
}

// Funções locais no main (ex.: outputs)
void turn_leds_on() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  
}

void turn_leds_off() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  
}