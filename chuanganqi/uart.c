#include "STC15F2K60S2.H"

/**************************
引脚别名定义如下：
**************************/

sbit UART_TXD = P3 ^ 1;

/**************************
定义变量如下：
**************************/
#define uint unsigned int

unsigned char timer1_interrupt_flag = 0;
unsigned char ADC_interrupt_flag = 0;
//分别设置光的变量

void InitADC_light();

void delay_ms(uint x) //不精确延时
{
	uint i;
	for (; x > 0; x--)
		for (i = 0; i < 500; i++)
			;
}

//初始化光ADC
void InitADC_light()
{
	P1ASF = 0x10; //使用第4通道
	ADC_RES = 0;  //结果寄存器清零
	ADC_RESL = 0;
	ADC_CONTR = 0X8C; //0x8C= 1000 1100b,打开ADC转换电源，转换速度设置为每540个周期转换一次
		//启动ADC转换，	P1.4作为AD输入来源
	CLK_DIV = 0X20;
}

void BitDelay() //用于串口通信的精确延时
{

	while (timer1_interrupt_flag == 0)
		;
	timer1_interrupt_flag = 0;
}

void UartSendByte(unsigned char Data)
{
	unsigned char i, temp;
	TR1 = 1;	  //启动定时器
	UART_TXD = 0; //UART_TXD起始位开始
	BitDelay();
	temp = 0x01;
	for (i = 0; i < 8; i++) //串行地将Data的每位发送到UART_TXD上
	{
		if (Data & temp)
			UART_TXD = 1;
		else
			UART_TXD = 0;
		temp = temp << 1;
		BitDelay();
	}
	UART_TXD = 1; //UART_TXD停止位开始
	BitDelay();
	TH1 = (65535 - 1666) / 256;
	TL1 = (65535 - 1666) % 256;
	TR1 = 0; //关闭定时器
}

void main()
{
	int light;
	P3M1 = 0x00; //P3M1 | 0x00;
	P3M0 = 0x00; //P3M0 | 0x00;

	UART_TXD = 1; //按照UART时序图，空闲时TXD保持高电平

	//使用定时器T1
	TMOD = 0x10;

	IE = 0xa8;
	TH1 = (65535 - 1666) / 256;
	TL1 = (65535 - 1666) % 256; //波特率是600bps，中断时间应该是1666，

	timer1_interrupt_flag = 0;
	ADC_interrupt_flag = 0;

	while (1)
	{
		delay_ms(200);	 //延时
		InitADC_light(); //初始化并启动ＡＤＣ
		while (ADC_interrupt_flag == 0)
			;					//等待转换完毕
		ADC_interrupt_flag = 0; //ADC中断标志清零，为下次ADC转换做准备
		light = ADC_RES * 256 + ADC_RESL;
		UartSendByte('T');
		UartSendByte('h');
		UartSendByte('e');
		UartSendByte(' ');
		UartSendByte('C');
		UartSendByte('u');
		UartSendByte('r');
		UartSendByte('r');
		UartSendByte('e');
		UartSendByte('n');
		UartSendByte('t');
		UartSendByte(' ');
		UartSendByte('L');
		UartSendByte('i');
		UartSendByte('g');
		UartSendByte('h');
		UartSendByte('t');
		UartSendByte(' ');
		UartSendByte('i');
		UartSendByte('n');
		UartSendByte('t');
		UartSendByte('e');
		UartSendByte('n');
		UartSendByte('s');
		UartSendByte('i');
		UartSendByte('t');
		UartSendByte('y');
		UartSendByte(' ');
		UartSendByte('i');
		UartSendByte('s');
		UartSendByte(':');
		UartSendByte('0' + light / 100);
		UartSendByte('0' + (light / 10) % 10);
		UartSendByte('0' + light % 10);
		UartSendByte('\r');
		UartSendByte('\n');
		/*UartSendByte(ADC_RES);
		 UartSendByte(ADC_RESL);//通过串口发送结果到PC		 */
	}
}

//定义定时器1中断
void Timer1_Routine() interrupt 3
{

	TH1 = (65535 - 1666) / 256;
	TL1 = (65535 - 1666) % 256;
	timer1_interrupt_flag = 1;
}

//AD中断
void adc_isr() interrupt 5 using 1
{
	IE = 0x00;
	ADC_interrupt_flag = 1;
	//完成后，ADC_FLAG清零
	ADC_CONTR &= ~0X10;
	IE = 0xa8;
}
