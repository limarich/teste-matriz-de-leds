#include "buzzer.h"

// Inicializa o buzzer no modo PWM
void initialize_buzzer()
{
    gpio_set_function(BUZZER_GPIO_A, GPIO_FUNC_PWM);
    uint slice_a = pwm_gpio_to_slice_num(BUZZER_GPIO_A); // Obtém o número do slice associado ao pino
    pwm_set_enabled(slice_a, false);                     // Inicialmente desativado
}

// Função para gerar o som correspondente a uma frequência
void play_tone(uint frequency, uint duration_ms)
{
    if (frequency == 0)
        return; // Não gera som se a frequência for 0 (sem som)

    // Obtém o número do slice do pino PWM
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_GPIO_A);

    // Calcula o valor do TOP do PWM baseado na frequência
    uint32_t clock_freq = clock_get_hz(clk_sys); // Frequência do sistema
    uint32_t top = (uint32_t)((double)clock_freq / frequency) - 1;

    // Define o TOP do PWM para a frequência desejada
    pwm_set_wrap(slice_num, top);

    // Define o ciclo de trabalho para 50% (som constante)
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(BUZZER_GPIO_A), top / 2);

    // Ativa o PWM
    pwm_set_enabled(slice_num, true);

    // Espera o tempo especificado em milissegundos
    sleep_ms(duration_ms);

    // Desativa o PWM após a duração
    pwm_set_enabled(slice_num, false);
}
