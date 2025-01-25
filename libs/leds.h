#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include "hardware/pio.h" // Necessário para trabalhar com PIO no Raspberry Pi Pico

#define PIXELS 25       // Defina a quantidade de pixels na matriz
extern float intensity; // Intensidade de cor (deve ser inicializada em algum ponto)

typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

typedef pixel frame[PIXELS];

// Função para definir a intensidade das cores
uint32_t matrix_rgb(uint r, uint g, uint b, float intensity);

// Função para acionar a matriz de LEDs WS2812B
void draw_pio(pixel *draw, PIO pio, uint sm, float intensity);

#endif
