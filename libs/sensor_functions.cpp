#include "sensor_functions.h"  // Inclui o header pra defines/pinos

float get_distance() {
  // Envia pulso Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê duração Echo
  unsigned long duration = pulseIn(echoPin, HIGH, 30000);  // Timeout 30ms
  if (duration == 0) {
    return 0;  // Erro: Sem eco
  }

  // Calcula distância
  float distance = (duration * SOUND_SPEED) / 2;
  return distance;
}

float check_noise(float dist) {
  // Média de NUM_READINGS pra filtro simples
  float sum = 0;
  for (int i = 0; i < NUM_READINGS; i++) {
    float reading = get_distance();
    if (reading < 2 || reading > 400) {  // Inválido (muito perto/longe)
      reading = dist;  // Usa anterior como fallback
    }
    sum += reading;
    delay(10);  // Pequeno delay pra amostra
  }
  return sum / NUM_READINGS;
}

void handle_gesture(float filtered_dist) {
  static bool currentState = false;  // Estado local (ou global no main)
  static float previousDist = 0;

  if (!currentState && filtered_dist < 20) {  // Threshold ON
    currentState = true;
    // Chame turn_leds_on() aqui (implemente no main ou outro .cpp)
    Serial.println("Gesture: ON - LEDs e Buzzer ativados");
  } else if (currentState && filtered_dist > 25) {  // Hysteresis OFF
    currentState = false;
    // Chame turn_leds_off()
    Serial.println("Gesture: OFF");
  }

  previousDist = filtered_dist;
}