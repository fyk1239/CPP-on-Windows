//根据PPT的图片自己写的代码，2021.11.16 14:55

#include <STC15F2K60S2.h>
#define uint unsigned int
#define uchar unsigned char
uchar table[] = {0x02, 0x04, 0x08, 0x10}; //控制电机转动数组

//引脚别名定义

sbit stepMotor_A = P4 ^ 1;
sbit stepMotor_B = P4 ^ 2;
sbit stepMotor_C = P4 ^ 3;
sbit stepMotor_D = P4 ^ 4;

sbit HALL = P1 ^ 2;
//sbit KEY1 = P3 ^ 2;

/**********************
*函数名称：void delay()
*功能描述：延时
*入口参数：xms：输入延时时间
*出口参数：无
*备注：无
***********************/
void delay(unsigned int xms)
{
	uint i, j;
	for (i = xms; i > 0; i--)
		for (j = 124; j > 0; j--)
			;
}

/**********************
*函数名称：void init_sys()
*功能描述：系统初始化，功能是配置IO口
*入口参数：无
*出口参数：无
*备注：
***********************/
void init_sys()
{
	//步进电机控制管脚推挽输出
	P4M0 = 0xff;
	P4M1 = 0x00;

	//0x04的二进制是0000 0100
	//霍尔传感器管脚P1.2设置成输入
	P1M1 = 0x04;
	P1M0 = 0x00;
}

void main()
{
	char i;
	int stepCount;
	init_sys();
	P4 = 0x00;
	while (1)
	{
		while (HALL == 1)
			; //如果没有小磁铁靠近就一直等待

		//实现功能：正转300步
		stepCount = 0;
		while (stepCount < 300)
		{
			for (i = 0; i < 4; i++)
			{
				P4 = table[i]; //控制电机转动
				delay(20);	   //延时以控制电机转速
			}
			stepCount++;
		}
		P4 = 0x00;

		while (HALL == 1)
			; //如果没有小磁铁靠近就一直等待

		//实现功能：反转300步
		stepCount = 0;
		while (stepCount < 300)
		{
			for (i = 3; i >= 0; i--)
			{
				P4 = table[i]; //控制电机转动
				delay(20);	   //延时以控制电机转速
			}
			stepCount++;
		}
		P4 = 0x00;
	}
}