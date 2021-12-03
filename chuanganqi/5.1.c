#include "STC15F2K60S2.H"

/**************************
引脚别名定义如下：
**************************/

//数码管位选管脚定义
sbit SEL0 = P2 ^ 0;
sbit SEL1 = P2 ^ 1;
sbit SEL2 = P2 ^ 2;
sbit SEL3 = P2 ^ 3;
sbit Echo = P1 ^ 0;
sbit Trig = P1 ^ 1;

// 定义变量如下：
#define uint unsigned int
#define uchar unsigned char

//存储从ADC读取到的测量结果
float receive;
uint receiveint;
char global = 0;

//用于设置温度显示的个位，十位，百位和千位
uint qianwei = 0;
uint baiwei = 0;
uint shiwei = 0;
uint gewei = 0;

uchar code table[] = {0x02, 0x04, 0x08, 0x10};

// 存储了0-f的显示编码
// 当选中某个数码管， 并将下面数组元素送入数码管的段选
// 口，即P0口时，数码管就会显示对应的数字。比如送入
// 0x3f就会显示0.

char segtable[] ={
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
    0x71
};

//延时函数
void delay(unsigned int xms)
{
    uint i, j;
    for (i = xms; i > 0; i--)
        for (j = 124; j > 0; j--)
            ;
}

void Delay(int n)
{
    int i = 0;
    for (; n > 0; n--)
        for (i = 0; i < 110; i++)
            ;
}

void data_process()
{
    qianwei = receiveint / 1000;
    baiwei = receiveint % 1000 / 100;
    shiwei = receiveint % 100 / 10;
    gewei = receiveint % 10;
}

void forward()
{
    char i;
    while (1)
    {
        for (i = 0; i < 4; i++)
        {
            P4 = table[i];
            ///控制电机转动
            Delay(20);
            //延时以控制电机转速
        }
    }
}

void backward()
{
    char i;
    while (1)
    {
        for (i = 3; i >= 0; i--)
        {
            P4 = table[i];
            ///控制电机转动
            Delay(20);
            //延时以控制电机转速
        }
    }
}

void DistanceMeasure()
{
    // 生成20us的脉冲宽度的触发信号
    Trig = 1;
    delay(2);
    Trig = 0;

    // 等待回响信号变高电平，当回响信号变高电平
    // 表示超声波已经发出，需要开始计时
    while (!Echo)
        ;
    TR0 = 1; // 启动定时器0，开始计时

    // 等待回响信号变低电平，当回响信号变低电平
    // 表示经过障碍物反射的超声波已经被接受到
    while (Echo)
        ;
    TR0 = 0; // 关闭定时器0
    // 通过晶振频率、传播时间和声音传播速度可以测得距离
    receive = (340 * ((float)TH0 * 256 + (float)TL0)) / 2000;
    // 这里的转化结果是 米/毫秒 或者 毫米/秒
    receiveint = (int)receive;
    if (receiveint < 30 || receiveint > 4000)
    {
        receiveint = 0;
    }
    data_process();

    TH0 = 0;
    TL0 = 0;
}

//用于数码管显示的位选选择
void weixuan(char i)
{
    SEL2 = i % 8 / 4;
    SEL1 = i % 4 / 2;
    SEL0 = i % 2;
}

//把数据显示在数码管上
void SEG_Display()
{

    int weixuan_count;
    weixuan_count = 0;
    while (weixuan_count < 4)
    {

        weixuan(weixuan_count);
        switch (weixuan_count)
        {
        case 0:
            P0 = segtable[qianwei];
            break;
        case 1:
            P0 = segtable[baiwei];
            break;
        case 2:
            P0 = segtable[shiwei];
            break;
        default:
            P0 = segtable[gewei];
            break;
        }
        delay(10); //延时10ms

        weixuan_count++;
    }
}

void main()
{
    int count = 0;
    // 电机初始化
    P4M0 = 0xff;
    P4M1 = 0x00;
    P4 = 0x00;

    // 七段显示管初始化
    P0M1 = 0x00;
    P0M0 = 0xff;
    P2M1 = 0x00;
    P2M0 = 0x08;
    SEL3 = 0;

    // 使用定时器T0，用于计算超声波发出到回来被接收到的时间差
    TMOD = 0x01;

    while (1)
    {
        if (receiveint < 200)
        {
            forward();
        }
        else
        {
            backward();
        }
        SEG_Display();
        count++;
        if (count > 100)
        {
            DistanceMeasure();
            count = 0;
        }
    }
}
