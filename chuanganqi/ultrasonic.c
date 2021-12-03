/**************************
�ļ����ƣ�ultrasonic.c
˵�����������������
**************************/
/**************************
ʹ?ͷ?�����£�
**************************/
#include "STC15F2K60S2.H"
/**************************
���ű����������£�
**************************/
sbit SEL0 = P2 ^ 0;
sbit SEL1 = P2 ^ 1;
sbit SEL2 = P2 ^ 2;
sbit SEL3 = P2 ^ 3;
sbit Echo = P1 ^ 0;
sbit Trig = P1 ^ 1;
/**************************
����������£�
**************************/
#define uint unsigned int
//
#define uchar unsigned char
float receive;
uint receiveint;
char global = 0;
char qianwei = 0;
char baiwei = 0;
char shiwei = 0;
char gewei = 0;
uchar code table[] = {0x02, 0x04, 0x08, 0x10};
//�������
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
void SEG_Display();
void date_process();
void Delay(int n);
void distanceMessure()
{
    //?��20us�������ȵĴ����ź�
    Trig = 1;
    Delay(2);
    Trig = 0;
    //�ȴ������źű�?��ƽ,�������źű�?��ƽ
    //��?�������Ѿ���������Ҫ��ʼ��ʱ
    while (!Echo)
        ;
    TR0 = 1;
    //������ʱ��0����ʼ��ʱ
    //�ȴ������źű�͵�ƽ���������źű�͵�ƽ
    //��?�����ϰ��ﷴ���ĳ������Ѿ������յ���
    while (Echo)
        ;
    TR0 = 0;
    //�رն�ʱ��0
    //ͨ������Ƶ�ʣ�����ʱ�����?�����ٶȿ��Բ�þ���
    receive = (340 * ((float)TH0 * 256 + (float)TL0)) / 2000;
    //��?��ת������Ǻ�?
    receiveint = (int)receive;
    if (receiveint < 30 || receiveint > 4000)
    {
        receiveint = 0;
    }
    date_process();
    TH0 = 0;
    TL0 = 0;
}
void date_process()
{
    qianwei = receiveint / 1000;
    baiwei = receiveint % 1000 / 100;
    shiwei = receiveint % 100 / 10;
    gewei = receiveint % 10;
}
void weixuan(char i)
{
    SEL2 = i / 4;
    SEL1 = i % 4 / 2;
    SEL0 = i % 2;
}
void SEG_Display()
{
    weixuan(4);
    P0 = segtable[qianwei];
    Delay(10);
    weixuan(5);
    P0 = segtable[baiwei];
    Delay(10);
    weixuan(6);
    P0 = segtable[shiwei];
    Delay(10);
    weixuan(7);
    P0 = segtable[gewei];
    Delay(10);
}
void Delay(int n)
{
    int i = 0;
    for (; n > 0; n--)
        for (i = 0; i < 110; i++)
            ;
}
void delay1(unsigned int xms)
{
    uint i, j;
    for (i = xms; i > 0; i--)
        for (j = 124; j > 0; j--)
            ;
}
void dianjizhengzhuan()
{
    char i;
    char stepCount = 0;
    //while(stepCount<300)
    //{
    for (i = 0; i < 4; i++)
    {
        P4 = table[i];
        ///���Ƶ��ת��
        delay1(20);
        //��ʱ�Կ��Ƶ��ת��
    }
    //stepCount++;
    //}

    P4 = 0x00;
}
void dianjifanzhuan()
{
    char i;
    for (i = 3; i >= 0; i--)
    {
        P4 = table[i];
        ///���Ƶ��ת��
        delay1(20);
        //��ʱ�Կ��Ƶ��ת��
    }
    P4 = 0x00;
}
void main()
{
    int count = 0;
    P4M0 = 0xff;
    P4M1 = 0x00;
    P4 = 0x00;
    //�����ʼ��
    P0M1 = 0x00;
    P0M0 = 0xff; //P0 ?����Ϊ�������?
    P2M1 = 0x00;
    P2M0 = 0x08; //�ر�LED
    SEL3 = 0;
    //ʹ?��ʱ��T0?�ڳ��������������������յ���ʱ���
    TMOD = 0x01;
    while (1)
    {
        if (receiveint < 200)
        {
            dianjizhengzhuan();
        }
        else
        {
            dianjifanzhuan();
        }
        SEG_Display(); //�������?����Ҫ����ˢ��
        count++;
        if (count > 100) //ÿ��?��ʱ�䣬?��?���ӣ�����?�β������
        {
            distanceMessure();
            count = 0;
        }
    }
}