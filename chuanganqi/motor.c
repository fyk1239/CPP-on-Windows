//�������Ĵ��룺

/***********************
����STC15F2K60S2ϵ�е�Ƭ��C���Ա��ʵ��
ʹ������ͷ�ļ������������ٰ���"REG51.H"
***********************/
#include <STC15F2K60S2.H>
#define uint unsigned int
#define uchar unsigned char
uchar code table[] = {0x02, 0x04, 0x08, 0x10}; //���Ƶ��ת������
/**********************
���ű�������
***********************/
sbit beep = P3 ^ 4; //������
bit flag;			//���Ʒ���������
uchar timeh, timel; //���嶨ʱ������װֵ
uint time_counter;	//��ʱ���жϼ���
uchar quzi_index;	//quzi������±���ƣ����жϷ���������õ�

uchar quzi[] = {
	//����������Ϊ���������ڶ�ʱ���е���װֵ����һ���Ǹ�λ���ڶ����ǵ�λ
	0xf8, 0x8c, //�Ͱ˶ȣ���1
	0xf9, 0x5b,
	0xfa, 0x15, //��3
	0xfa, 0x67,
	0xfb, 0x04, //��5
	0xfb, 0x90,
	0xfc, 0x0c, //��7
	0xfc, 0x44, //����C��
	0xfc, 0xac, //��2
	0xfd, 0x09,
	0xfd, 0x34, //��4
	0xfd, 0x82,
	0xfd, 0xc8, //��6
	0xfe, 0x06,
	0xfe, 0x22, //�߰˶ȣ���1
	0xfe, 0x56,
	0xfe, 0x6e, //��3
	0xfe, 0x9a,
	0xfe, 0xc1, //��5
	0xfe, 0xe4,
	0xff, 0x03 //��7
};

sbit stepMotor_A = P4 ^ 1;
sbit stepMotor_B = P4 ^ 2;
sbit stepMotor_C = P4 ^ 3;
sbit stepMotor_D = P4 ^ 4; //�����ĸ��ܽŶ�����δ�õ���
//ֻ����ʾ����λ�ǲ���������ƹܽ�

sbit HALL = P1 ^ 2;
//sbit KEY1=P3^2;

/**********************
�������ƣ�void delay()
������������ʱ
��ڲ�����xms��������ʱʱ��
���ڲ�������
��ע��

***********************/
void delay(unsigned int xms)
{
	uint i, j;
	for (i = xms; i > 0; i--)
		for (j = 124; j > 0; j--)
			;
}

/**********************
�������ƣ�void init_sys()
����������ϵͳ��ʼ��������������IO��
��ڲ�������
���ڲ�������
��ע��

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

	P0M1 = 0x00;
	P0M0 = 0xff;
	P2M1 = 0x10;
	P2M0 = 0x00; //vibrate = P2.4 ��Ϊ���� cyh
	P3M1 = 0x00;
	P3M0 = 0x00; //beep = P3.4 ׼˫��� cyh
	//IO�˿�����

	beep = 0; //��������ʼ��Ϊ�͵�ƽ
	TH0 = 0x00;
	TL0 = 0x00;	 //��ʼ����ʱ��������ʼֵ
	TMOD = 0x01; //��ʱ��0����ʽ1 16λ������װģʽ
	EA = 1;		 //���ж�ʹ��
	ET0 = 1;	 //��ʱ��0�ж�ʹ��
	TR0 = 0;	 //��ʱ�رն�ʱ��0
}
void main()
{
	char i;
	int stepCount;
	init_sys();
	flag = 0;
	time_counter = 0;
	quzi_index = 0; //������ʼ��

	P4 = 0x00;
	P0M1 = 0x00;
	P0M0 = 0xff; //����P0Ϊ׼˫����������
	while (HALL == 1)
	{
		P0 = 0x01; //��ʼ��ʱ��һ������
		for (i = 0; i < 8; i++)
		{
			P0 = P0 << 1; //ÿ�������ƶ�1λ
		}
	}
	while (1)
	{

		while (HALL == 1)
			; //���û��С����������һֱ�ȴ�

		//������δ���ʵ�ֵĹ�������ת300��
		stepCount = 0;
		while (stepCount < 300)
		{
			for (i = 0; i < 4; i++)
			{
				P4 = table[i]; ///���Ƶ��ת��

				delay(20); //��ʱ�Կ��Ƶ��ת��
			}
			stepCount++;
		}

		flag = 1; //����־λ��1
		TR0 = 1;  //������ʱ��

		P4 = 0x00;

		while (HALL == 1)
			; //���û��С����������һֱ�ȴ�

		//������δ���ʵ�ֵĹ����Ƿ�ת300��
		stepCount = 0;
		while (stepCount < 300)
		{
			for (i = 3; i >= 0; i--)
			{
				P4 = table[i]; ///���Ƶ��ת��
				delay(20);	   //��ʱ�Կ��Ƶ��ת��
			}
			stepCount++;
		}

		flag = 1; //����־λ��1
		TR0 = 1;  //������ʱ��

		P4 = 0x00;
	}
}
void tim1() interrupt 1 //��ʱ������Ƶ��
{
	if (flag)
	{
		quzi_index = (quzi_index + 2) % 14;
		
		timeh = quzi[quzi_index];
		timel = quzi[quzi_index + 1];
		TH0 = timeh;
		TL0 = timel;

		beep = ~beep; //beep�ܽ�ȡ��
		
	}
}