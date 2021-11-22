#include <STC15F2K60S2.h>
#define uint unsigned int
#define uchar unsigned char

uint led_number[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

sbit HALL = P1 ^ 2;
sbit k1 = P3 ^ 2;

int cnt;
bit flag; //控制中断

void delay(unsigned int xms)
{
    uint i, j;
    for (i = xms; i > 0; i--)
        for (j = 124; j > 0; j--)
            ;
}

void init_sys()
{
    //0x04的二进制是0000 0100
    //霍尔传感器管脚P1.2设置成输入
    P1M1 = 0x04;
    P1M0 = 0x00;

    flag = 0;
    TMOD = 0x01; //定时器0，方式1       16位不可重装模式
    EA = 1;      //总中断使能
    ET0 = 1;     //定时器0中断使能
    TR0 = 0;     //暂时关闭定时器0

    P0M1 = 0x00;
    P0M0 = 0xff; //设置P0为推挽输出
    P2M1 = P2M1 | 0x00;
    P2M0 = P2M0 | 0x08; //设置P23为推挽输出
    P2 = P2 | 0x08;     //根据电路原理分析，将P23置1，即高电平

    //IO端口设置
}

void main()
{
    init_sys();
    while (1)
    {
        if (!k1)
        {
            P0 = 0x00;
        }
        while (!HALL)
        {
            P0 = P0 + 1;
            while (!HALL)
                ;
        }
    }
}
