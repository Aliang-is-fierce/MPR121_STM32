#ifndef __DRIVER_MPR121_H
#define __DRIVER_MPR121_H
#include "i2c.h"
#include <stdint.h>

#include "stm32f1xx_hal.h"

// I2C Handle
extern I2C_HandleTypeDef hi2c2; // 确保 I2C 配置与实际使用的通道一致

// MPR121 I2C Address
#define MPR121_I2C_ADDR    (0x5A << 1) // 默认地址，修改为实际连接的地址

// MPR121 Registers
#define MPR121_TOUCH_STATUS_L   0x00 // 触摸状态寄存器低字节
#define MPR121_TOUCH_STATUS_H   0x01 // 触摸状态寄存器高字节

// 函数接口
uint8_t MPR121_Init(void);
uint8_t MPR121_IsTouched(void);

#endif /* __DRIVER_MPR121_H */

