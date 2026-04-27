#include "st7735.h"
#include <string.h>

static void ST7735_WriteCommand(uint8_t cmd)
{
    HAL_GPIO_WritePin(ST7735_DC_PORT, ST7735_DC_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ST7735_CS_PORT, ST7735_CS_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2, &cmd, 1, 100);
    HAL_GPIO_WritePin(ST7735_CS_PORT, ST7735_CS_PIN, GPIO_PIN_SET);
}

static void ST7735_WriteData(uint8_t *data, uint16_t size)
{
    HAL_GPIO_WritePin(ST7735_DC_PORT, ST7735_DC_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ST7735_CS_PORT, ST7735_CS_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2, data, size, 100);
    HAL_GPIO_WritePin(ST7735_CS_PORT, ST7735_CS_PIN, GPIO_PIN_SET);
}

void ST7735_Reset(void)
{
    HAL_GPIO_WritePin(ST7735_RST_PORT, ST7735_RST_PIN, GPIO_PIN_RESET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(ST7735_RST_PORT, ST7735_RST_PIN, GPIO_PIN_SET);
    HAL_Delay(50);
}

void ST7735_Init(void)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
    HAL_Delay(50);

    ST7735_WriteCommand(0x01);
    HAL_Delay(150);

    ST7735_WriteCommand(0x11);
    HAL_Delay(150);

    ST7735_WriteCommand(0x3A);
    uint8_t data = 0x05;
    ST7735_WriteData(&data, 1);

    ST7735_WriteCommand(0x36);
    data = 0xC8;
    ST7735_WriteData(&data, 1);

    ST7735_WriteCommand(0x29);
}

void ST7735_FillScreen(uint16_t color)
{
    uint8_t data[2] = {color >> 8, color & 0xFF};

    ST7735_WriteCommand(0x2A);
    uint8_t colData[] = {0x00,0x00,0x00,0x7F};
    ST7735_WriteData(colData, 4);

    ST7735_WriteCommand(0x2B);
    uint8_t rowData[] = {0x00,0x00,0x00,0x9F};
    ST7735_WriteData(rowData, 4);

    ST7735_WriteCommand(0x2C);

    for(int i=0; i<128*160; i++)
    {
        ST7735_WriteData(data, 2);
    }
}

/* VERY SIMPLE TEXT (NO FONT LIB) */
void ST7735_WriteString(uint16_t x, uint16_t y, char* str, uint16_t color)
{
    // TEMP: just clear + indicate working
    ST7735_FillScreen(BLACK);
}
