#include "driver_MPR121.h"

// 初始化 MPR121
uint8_t MPR121_Init(void) {
    // 配置寄存器：可以根据需要设置不同的初始化参数
    uint8_t config[][2] = {
        {0x2B, 0x01}, // Example: 设置触摸检测配置（这里的寄存器地址根据数据手册调整）
        {0x2C, 0x01}, // 设置过滤参数（根据实际需要配置）
        // ... 根据数据手册添加其他初始化配置
    };

    for (uint8_t i = 0; i < sizeof(config) / 2; i++) {
        if (HAL_I2C_Mem_Write(&hi2c2, MPR121_I2C_ADDR, config[i][0], I2C_MEMADD_SIZE_8BIT, &config[i][1], 1, HAL_MAX_DELAY) != HAL_OK) {
            return 0; // 初始化失败
        }
    }

    return 1; // 初始化成功
}

// 检查是否有触摸输入
uint8_t MPR121_IsTouched(void) {
    uint8_t touchStatus[2] = {0};

    // 读取触摸状态寄存器
    if (HAL_I2C_Mem_Read(&hi2c2, MPR121_I2C_ADDR, MPR121_TOUCH_STATUS_L, I2C_MEMADD_SIZE_8BIT, touchStatus, 2, HAL_MAX_DELAY) != HAL_OK) {
        return 0; // 读取失败，返回无触摸
    }

    // 检查是否有触摸（两个字节中的任意一个有非零值表示触摸）
    uint16_t touchData = (touchStatus[1] << 8) | touchStatus[0];
    return (touchData != 0) ? 1 : 0;
}