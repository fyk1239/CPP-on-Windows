//����PPT��ͼƬ�Լ�д�Ĵ��룬2021.11.16 14:55

#include <STC15F2K60S2.h>
#define uint unsigned int
#define uchar unsigned char
uchar table[] = {0x02, 0x04, 0x08, 0x10}; //���Ƶ��ת������

//���ű�������

sbit stepMotor_A = P4 ^ 1;
sbit stepMotor_B = P4 ^ 2;
sbit stepMotor_C = P4 ^ 3;
sbit stepMotor_D = P4 ^ 4;

sbit HALL = P1 ^ 2;
//sbit KEY1 = P3 ^ 2;

/**********************
*�������ƣ�void delay()
*������������ʱ
*��ڲ�����xms��������ʱʱ��
*���ڲ�������
*��ע����
***********************/
void delay(unsigned int xms)
{
	uint i, j;
	for (i = xms; i > 0; i--)
		for (j = 124; j > 0; j--)
			;
}

/**********************
*�������ƣ�void init_sys()
*����������ϵͳ��ʼ��������������IO��
*��ڲ�������
*���ڲ�������
*��ע��
***********************/
void init_sys()
{
	//����������ƹܽ��������
	P4M0 = 0xff;
	P4M1 = 0x00;

	//0x04�Ķ�������0000 0100
	//�����������ܽ�P1.2���ó�����
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
			; //���û��С����������һֱ�ȴ�

		//ʵ�ֹ��ܣ���ת300��
		stepCount = 0;
		while (stepCount < 300)
		{
			for (i = 0; i < 4; i++)
			{
				P4 = table[i]; //���Ƶ��ת��
				delay(20);	   //��ʱ�Կ��Ƶ��ת��
			}
			stepCount++;
		}
		P4 = 0x00;

		while (HALL == 1)
			; //���û��С����������һֱ�ȴ�

		//ʵ�ֹ��ܣ���ת300��
		stepCount = 0;
		while (stepCount < 300)
		{
			for (i = 3; i >= 0; i--)
			{
				P4 = table[i]; //���Ƶ��ת��
				delay(20);	   //��ʱ�Կ��Ƶ��ת��
			}
			stepCount++;
		}
		P4 = 0x00;
	}
}