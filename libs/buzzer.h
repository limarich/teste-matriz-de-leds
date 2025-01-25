#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Definição do GPIO para o buzzer
#define BUZZER_GPIO_A 21

/**
 * @brief Inicializa o buzzer no modo PWM
 * Configura o pino do buzzer para função PWM, desativando-o inicialmente.
 */
void initialize_buzzer();

/**
 * @brief Reproduz um tom no buzzer por um tempo específico.
 *
 * @param frequency A frequência do som em Hz.
 * @param duration_ms A duração do som em milissegundos.
 */
void play_tone(uint frequency, uint duration_ms);

#endif // BUZZER_H
