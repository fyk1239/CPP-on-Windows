#include "STC15F2K60S2.H"

/**************************
���ű����������£�
**************************/

sbit UART_TXD=P3^1;


/**************************
����������£�
**************************/
#define uint unsigned int

unsigned char timer1_interrupt_flag=0;
unsigned char ADC_interrupt_flag=0;
//�ֱ����ù�ı���



void InitADC_light();

void delay_ms(uint x)//����ȷ��ʱ
{
	uint i;
	for(;x>0;x--)
		for(i=0;i<500;i++)
			;
}

//��ʼ����ADC
void InitADC_light()
{
	P1ASF=0x10;	//ʹ�õ�4ͨ��
	ADC_RES=0;//����Ĵ�������
	ADC_RESL=0;
	ADC_CONTR=0X8C;	 //0x8C= 1000 1100b,��ADCת����Դ��ת���ٶ�����Ϊÿ540������ת��һ��
					//����ADCת����	P1.4��ΪAD������Դ
	CLK_DIV=0X20;
}

void BitDelay()	//���ڴ���ͨ�ŵľ�ȷ��ʱ
{
	
	while(timer1_interrupt_flag==0);
	timer1_interrupt_flag=0;
}

void UartSendByte(unsigned char Data)
{
     unsigned char i, temp;
	 TR1=1;//������ʱ��
	 UART_TXD=0; //UART_TXD��ʼλ��ʼ
	 BitDelay();
	 temp=0x01;
	 for(i=0;i<8;i++)//���еؽ�Data��ÿλ���͵�UART_TXD��
	 	{
			if(Data&temp)
				  UART_TXD=1;
			else 
				  UART_TXD=0;
			temp=temp<<1;
			BitDelay();	
		}
     UART_TXD=1; //UART_TXDֹͣλ��ʼ
	 BitDelay();
	 TH1=(65535-1666)/256;
	 TL1=(65535-1666)%256;
	 TR1=0;//�رն�ʱ��

}

void main()
{
	int light;
	P3M1=0x00; //P3M1 | 0x00;
	P3M0=0x00; //P3M0 | 0x00;

	UART_TXD=1;	//����UARTʱ��ͼ������ʱTXD���ָߵ�ƽ

	//ʹ�ö�ʱ��T1
	TMOD=0x10;

	IE=0xa8;	
 	TH1=(65535-1666)/256;
	TL1=(65535-1666)%256;//��������600bps���ж�ʱ��Ӧ����1666��

	timer1_interrupt_flag=0;
	ADC_interrupt_flag=0;

	while(1)
	{
	   	delay_ms(200);	//��ʱ
		InitADC_light(); //��ʼ�����������ģ�
		while(ADC_interrupt_flag==0);//�ȴ�ת�����
		 ADC_interrupt_flag=0; //ADC�жϱ�־���㣬Ϊ�´�ADCת����׼��
		 light=ADC_RES*256+ADC_RESL;
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
		 UartSendByte('0'+light/100);
		 UartSendByte('0'+(light/10)%10);
		 UartSendByte('0'+light%10);
		 UartSendByte('\r');
		 UartSendByte('\n');
		 /*UartSendByte(ADC_RES);
		 UartSendByte(ADC_RESL);//ͨ�����ڷ��ͽ����PC		 */
		
	}
}


//���嶨ʱ��1�ж�
void Timer1_Routine() interrupt 3
{

	TH1=(65535-1666)/256;
	TL1=(65535-1666)%256;
	timer1_interrupt_flag=1;

}

//AD�ж�
void adc_isr() interrupt 5 using 1
{
	IE=0x00;
	ADC_interrupt_flag=1;
    //��ɺ�ADC_FLAG����
	ADC_CONTR&=~0X10;
	IE=0xa8;
}



