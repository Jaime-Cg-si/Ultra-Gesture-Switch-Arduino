#ifndef SENSOR_FUNCTIONS_H  // Guard para evitar includes duplicados
#define SENSOR_FUNCTIONS_H

#include <Arduino.h>  // Built-in pra pinMode, etc.

// Defines globais (compartilhados)
const int trigPin = 9;
const int echoPin = 10;
const float SOUND_SPEED = 0.034;  // cm/μs
const int NUM_READINGS = 3;

// Declarações de funções (protótipos)
float get_distance();  // Função 1: Lê sensor
float check_noise(float dist);  // Função 2: Filtra ruído
void handle_gesture(float filtered_dist);  // Função 3: Decide ação

#endif