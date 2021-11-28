#include "STC15F2K60S2.H"

/**************************
���ű����������£�
**************************/

//�����λѡ�ܽŶ���
sbit SEL0 = P2 ^ 0;
sbit SEL1 = P2 ^ 1;
sbit SEL2 = P2 ^ 2;

sbit SEL3 = P2 ^ 3;

/**************************
����������£�
**************************/
#define uint unsigned int

//�洢��ADC��ȡ���Ĳ������
uint datelight = 0;

//�������ù����ʾ�ĸ�λ��ʮλ����λ
uint lightbaiwei = 0;
uint lightshiwei = 0;
uint lightgewei = 0;

char weixuan_count;

//�洢��0-f����ʾ����
// ��ѡ��ĳ������ܣ� ������������Ԫ����������ܵĶ�ѡ
//�ڣ���P0��ʱ������ܾͻ���ʾ��Ӧ�����֡���������
// 0x3f�ͻ���ʾ0.

char segtable[] =
	{
		0x3f,
		0x06,
		0x5b,
		0x4f,
		0x66,
		0x6d,
		0x7d,
		0x07,
		0x7f,
		0x6f,
		0x77,
		0x7c,
		0x39,
		0x5e,
		0x79,
		0x71};

void SEG_Display();			  // �������ʾ��������
void InitAndStartADC_light(); // ϵͳ��ʼ��
void date_processlight();	  // ��ADC�����õ������ݴ����Է�������ܵ���ʾ

// ��ʼ����ADC
void InitAndStartADC_light()
{
	P1ASF = 0x10; // ʹ�õ�4ͨ������Ϊ���մ������������
	// ������P1.4�ܽ�
	ADC_RES = 0; // ����Ĵ�������ADC_RES��ADC_RESL���ADC��ȡ���Ľ��
	ADC_RESL = 0;

	// 0x8C= 1000 1100b,��ADCת����Դ��ת���ٶ�
	// ����Ϊÿ540������ת��һ��
	// ����ADCת����	P1.4��ΪAD������Դ
	// �������ݲο������ֲ��������
	ADC_CONTR = 0X8C;
	CLK_DIV = 0X20; // ת����Ľ����10bit�ģ�
}

// ��ʱ����
void delay(unsigned int xms)
{
	uint i, j;
	for (i = xms; i > 0; i--)
		for (j = 124; j > 0; j--)
			;
}

void main()
{
	int timeInterruptCounter = 0; // ADC�ɼ�ʱ�����

	// ����
	P0M1 = 0x00;
	P0M0 = 0xff;

	P2M1 = 0x00;
	P2M0 = 0x08;

	SEL3 = 0; // LED�ƹرգ���Զ�رգ�

	EA = 1;	  // ʹ��(enable)���ж�Դ
	EADC = 1; // ʹ��ADC�жϣ�EA=1 ���� EADC=1 ADC����
	// �жϺ��жϺ������ܱ�����
	weixuan_count = 0;
	timeInterruptCounter = 0;
	InitAndStartADC_light();

	while (1)
	{
		SEG_Display();
		timeInterruptCounter++;
		if (timeInterruptCounter > 200)
		{

			InitAndStartADC_light(); //ÿ��ת��֮ǰ��Ҫ��ʼ��ADC��ؼĴ���

			timeInterruptCounter = 0;
		}
	}
}

// ��Ӧ�ⲿ�ֵĴ�������
void date_processlight()
{
	lightbaiwei = datelight % 1000 / 100;
	lightshiwei = datelight % 100 / 10;
	lightgewei = datelight % 10;
}

// AD�ж�
void adc_isr() interrupt 5
{
	EADC = 0;
	datelight = ADC_RES * 256 + ADC_RESL; // �ӼĴ����ж�ȡת�����
	date_processlight();
	// ת����ɺ�ADC_FLAG����
	ADC_CONTR &= ~0X10;
	EADC = 1;
}

// �����������ʾ��λѡѡ��
void weixuan(char i)
{
	SEL2 = i % 8 / 4;
	SEL1 = i % 4 / 2;
	SEL0 = i % 2;
}

// ��������ʾ���������
void SEG_Display()
{

	int weixuan_count;
	weixuan_count = 0;
	while (weixuan_count < 3)
	{

		weixuan(weixuan_count);
		switch (weixuan_count)
		{
		case 0:
			P0 = segtable[lightbaiwei];
			break;
		case 1:
			P0 = segtable[lightshiwei];
			break;
		default:
			P0 = segtable[lightgewei];
			break;
		}

		delay(5); //��ʱ5ms

		weixuan_count++;
	}
}
