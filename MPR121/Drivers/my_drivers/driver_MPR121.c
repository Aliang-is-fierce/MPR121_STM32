#include "driver_MPR121.h"

// ��ʼ�� MPR121
uint8_t MPR121_Init(void) {
    // ���üĴ��������Ը�����Ҫ���ò�ͬ�ĳ�ʼ������
    uint8_t config[][2] = {
        {0x2B, 0x01}, // Example: ���ô���������ã�����ļĴ�����ַ���������ֲ������
        {0x2C, 0x01}, // ���ù��˲���������ʵ����Ҫ���ã�
        // ... ���������ֲ����������ʼ������
    };

    for (uint8_t i = 0; i < sizeof(config) / 2; i++) {
        if (HAL_I2C_Mem_Write(&hi2c2, MPR121_I2C_ADDR, config[i][0], I2C_MEMADD_SIZE_8BIT, &config[i][1], 1, HAL_MAX_DELAY) != HAL_OK) {
            return 0; // ��ʼ��ʧ��
        }
    }

    return 1; // ��ʼ���ɹ�
}

// ����Ƿ��д�������
uint8_t MPR121_IsTouched(void) {
    uint8_t touchStatus[2] = {0};

    // ��ȡ����״̬�Ĵ���
    if (HAL_I2C_Mem_Read(&hi2c2, MPR121_I2C_ADDR, MPR121_TOUCH_STATUS_L, I2C_MEMADD_SIZE_8BIT, touchStatus, 2, HAL_MAX_DELAY) != HAL_OK) {
        return 0; // ��ȡʧ�ܣ������޴���
    }

    // ����Ƿ��д����������ֽ��е�����һ���з���ֵ��ʾ������
    uint16_t touchData = (touchStatus[1] << 8) | touchStatus[0];
    return (touchData != 0) ? 1 : 0;
}