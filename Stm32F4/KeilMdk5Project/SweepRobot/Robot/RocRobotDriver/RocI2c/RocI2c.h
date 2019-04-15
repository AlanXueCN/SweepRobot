#ifndef __ROC_IIC_H
#define __ROC_IIC_H


#include <stdint.h>


#define SDA_IN()        {GPIOB->MODER&=~(3<<(11*2));GPIOB->MODER|=0<<11*2;}   //PB11����ģʽ
#define SDA_OUT()       {GPIOB->MODER&=~(3<<(11*2));GPIOB->MODER|=1<<11*2;}   //PB11���ģʽ

#define IIC_SCL(n)      (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET)) //SCL
#define IIC_SDA(n)      (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET)) //SDA
#define READ_SDA        HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)                //����SDA 

void IIC_Init(void);                                                        //��ʼ��IIC��IO��
void IIC_Start(void);                                                       //����IIC��ʼ�ź�
void IIC_Stop(void);                                                        //����IICֹͣ�ź�
void IIC_Send_Byte(uint8_t txd);                                                 //IIC����һ���ֽ�
uint8_t IIC_Read_Byte(unsigned char ack);                                        //IIC��ȡһ���ֽ�
uint8_t IIC_Wait_Ack(void);                                                      //IIC�ȴ�ACK�ź�
void IIC_Ack(void);                                                         //IIC����ACK�ź�
void IIC_NAck(void);                                                        //IIC������ACK�ź�
void IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);

#endif













