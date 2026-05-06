#ifndef MCP4725_H
#define MCP4725_H

#include "stm32f4xx_hal.h"

#define MCP4725_ADDR         (0x60 << 1)
#define MCP4725_CMD_WRITEDAC  0x40

HAL_StatusTypeDef MCP4725_SetValue(I2C_HandleTypeDef *hi2c, uint16_t value);
HAL_StatusTypeDef MCP4725_SetVoltage(I2C_HandleTypeDef *hi2c, float voltage, float vref);

#endif
