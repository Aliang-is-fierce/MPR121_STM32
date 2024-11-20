#ifndef __DRIVER_MPR121_H
#define __DRIVER_MPR121_H
#include "i2c.h"
#include <stdint.h>

#include "stm32f1xx_hal.h"

// I2C Handle
extern I2C_HandleTypeDef hi2c2; // ȷ�� I2C ������ʵ��ʹ�õ�ͨ��һ��

// MPR121 I2C Address
#define MPR121_I2C_ADDR    (0x5A << 1) // Ĭ�ϵ�ַ���޸�Ϊʵ�����ӵĵ�ַ

// MPR121 Registers
#define MPR121_TOUCH_STATUS_L   0x00 // ����״̬�Ĵ������ֽ�
#define MPR121_TOUCH_STATUS_H   0x01 // ����״̬�Ĵ������ֽ�

// �����ӿ�
uint8_t MPR121_Init(void);
uint8_t MPR121_IsTouched(void);

#endif /* __DRIVER_MPR121_H */

