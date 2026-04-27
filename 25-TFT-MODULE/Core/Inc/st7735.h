#ifndef __ST7735_H
#define __ST7735_H

#include "main.h"

extern SPI_HandleTypeDef hspi2;

/* PINS */
#define ST7735_CS_PORT   GPIOB
#define ST7735_CS_PIN    GPIO_PIN_9

#define ST7735_DC_PORT   GPIOB
#define ST7735_DC_PIN    GPIO_PIN_8

#define ST7735_RST_PORT  GPIOB
#define ST7735_RST_PIN   GPIO_PIN_7

/* COLORS */
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0
#define BLUE    0x001F
#define YELLOW  0xFFE0
#define CYAN    0x07FF

void ST7735_Init(void);
void ST7735_FillScreen(uint16_t color);
void ST7735_WriteString(uint16_t x, uint16_t y, char* str, uint16_t color);

#endif
