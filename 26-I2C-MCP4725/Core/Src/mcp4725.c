#include "mcp4725.h"

HAL_StatusTypeDef MCP4725_SetValue(I2C_HandleTypeDef *hi2c, uint16_t value)
{
    uint8_t buf[3];

    if (value > 4095) value = 4095;

    buf[0] = MCP4725_CMD_WRITEDAC;
    buf[1] = (value >> 4) & 0xFF;
    buf[2] = (value & 0x0F) << 4;

    return HAL_I2C_Master_Transmit(hi2c, MCP4725_ADDR, buf, 3, 1000);
}

HAL_StatusTypeDef MCP4725_SetVoltage(I2C_HandleTypeDef *hi2c, float voltage, float vref)
{
    if (voltage > vref) voltage = vref;
    if (voltage < 0.0f) voltage = 0.0f;

    uint16_t raw = (uint16_t)((voltage / vref) * 4095.0f);
    return MCP4725_SetValue(hi2c, raw);
}
