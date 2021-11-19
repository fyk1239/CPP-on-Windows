/**********************
*�ļ����ƣ�beeplayer.c
*���ߣ�
*˵�����񶯴������ܵ���ʱ������������  
*�޸ļ�¼��
***********************/

/**********************
����STC15F2K60S2ϵ�е�Ƭ��C���Ա��ʵ��
***********************/
#include "STC15F2K60S2.h"
#define uint unsigned int
#define uchar unsigned char
sbit vibrate=P2^4;		  //�񶯴�����
sbit beep=P3^4;			  //������
bit flag;				  //���Ʒ���������
uchar timeh,timel;		  //���嶨ʱ������װֵ
uint time_counter;        //��ʱ���жϼ���
uchar quzi_index;	      //quzi������±���ƣ����жϷ���������õ�
																						
uchar quzi[] ={	  //����������Ϊ���������ڶ�ʱ���е���װֵ����һ���Ǹ�λ���ڶ����ǵ�λ
	0xf8,0x8c,	  //�Ͱ˶ȣ���1
	0xf9,0x5b,	  
	0xfa,0x15,	  //��3
	0xfa,0x67,
	0xfb,0x04,	  //��5
	0xfb,0x90,
	0xfc,0x0c,	  //��7	
	0xfc,0x44,	  //����C��
	0xfc,0xac,	  //��2
	0xfd,0x09,
	0xfd,0x34,	  //��4
	0xfd,0x82,
	0xfd,0xc8,	  //��6
	0xfe,0x06,
	0xfe,0x22,	  //�߰˶ȣ���1	
	0xfe,0x56,
	0xfe,0x85,	  //��3	
	0xfe,0x9a,
	0xfe,0xc1,	  //��5
	0xfe,0xe4,
	0xff,0x03	  //��7
};

uchar huanlesong[] = {
0xfd,0x09, //E5
0xfd,0x09, //E5
0xfd,0x34, //F5
0xfd,0x82, //G5
0xfd,0x82, //G5
0xfd,0x34, //F5
0xfd,0x09, //E5
0xfc,0xac, //D5
0xfc,0x44, //C5
0xfc,0x44, //C5
0xfc,0xac, //D5
0xfd,0x09, //E5
0xfd,0x09, //E5
0xfc,0xac, //D5
0xfc,0xac, //D5
0xfc,0xac, //D5				  
};
/**********************
*�������ƣ�void delay()
*������������ʱ
*��ڲ�����xms��������ʱʱ��
*���ڲ�������
*��ע��
*
***********************/
void delay(unsigned int xms)
{
	uint i,j;						   
	 for(i=xms;i>0;i--)
	 	for(j=124;j>0;j--);
}

/**********************
*�������ƣ�void init_sys()
*����������ϵͳ��ʼ��������������IO��
*��ڲ�������
*���ڲ�������
*��ע��
*
***********************/
void init_sys()			  
{
	P0M1=0x00; P0M0=0xff; 
	P2M1=0x10; P2M0=0x00;
	P3M1=0x00; P3M0=0x00;
						  //IO�˿�����

	beep=0;	//���������Ի�Ϊ�͵�ƽ
	TH0=0x00;
	TL0=0x00;	//��ʼ����ʱ��������ʼֵ
	TMOD=0x01;  //��ʱ��0����ʽ1
	EA=1;//���ж�ʹ��
	ET0=1;	//��ʱ��0�ж�ʹ��
	TR0=0;	 //��ʱ�رն�ʱ��0
}
void main()
{
	init_sys();

	flag=0;
	time_counter=0;
	quzi_index=0; //������ʼ��
	while(1)//���ȵ�ɨ���Ƿ����񶯷���   
	{	    
		if(vibrate==0)
		{
			delay(5); //����
			if(vibrate==0)
			{
				flag=1;//�������񶯱�־λ��1
				TR0=1; //������ʱ��
			}
		} 
			   
	}
	                                        		
}

void tim1() interrupt 1						//��ʱ������Ƶ��
{
	if(flag)
	{
		time_counter++;	 //�жϼ���
		if(time_counter==(300+30*quzi_index))//���ڿ���ÿ���ض�Ƶ�������ķ���ʱ��
		{
			time_counter=0;
			if(quzi_index<40)
				quzi_index=quzi_index+2;
			else 
					{
						quzi_index=0;
						 flag=0;
						 beep=0; //�������㣬Ϊ�´ι�������׼��
					}
		}
		timeh=quzi[quzi_index];
		timel=quzi[quzi_index+1];	
		TH0=timeh;
		TL0=timel;
	
		beep=~beep;//beep�ܽ�ȡ��
	}

}
