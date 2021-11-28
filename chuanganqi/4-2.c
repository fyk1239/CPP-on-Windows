#include "STC15F2K60S2.H"

/**************************
引脚别名定义如下：
**************************/

//数码管位选管脚定义
sbit SEL0 = P2 ^ 0;
sbit SEL1 = P2 ^ 1;
sbit SEL2 = P2 ^ 2;

sbit SEL3 = P2 ^ 3;

// 定义变量如下：
#define uint unsigned int

//存储从ADC读取到的测量结果
uint datatemperature = 0;

//用于设置温度显示的个位，十位，百位
uint temperaturebaiwei = 0;
uint temperatureshiwei = 0;
uint temperaturegewei = 0;

char weixuan_count;

// 存储了0-f的显示编码
// 当选中某个数码管， 并将下面数组元素送入数码管的段选
// 口，即P0口时，数码管就会显示对应的数字。比如送入
// 0x3f就会显示0.

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

void SEG_Display();                 // 数码管显示函数声明
void InitAndStartADC_temperature(); // 系统初始化
void data_processtemperature();     // 从ADC测量得到的数据处理以方便数码管的显示

//初始化温度ADC
void InitAndStartADC_temperature()
{
    P1ASF = 0x08; // 使用第3通道，因为温度传感器的输出段
                  // 接在了P1.3管脚
    ADC_RES = 0;  // 结果寄存器清零ADC_RES和ADC_RESL存放ADC读取到的结果
    ADC_RESL = 0;

    // 0x8b= 1000 1011b,打开ADC转换电源，转换速度
    // 设置为每540个周期转换一次
    // 启动ADC转换，P1.3作为AD输入来源
    // 具体内容参考数据手册相关内容
    ADC_CONTR = 0x8b;
    CLK_DIV = 0x20; // 转换后的结果用10bit的，
}

//延时函数
void delay(unsigned int xms)
{
    uint i, j;
    for (i = xms; i > 0; i--)
        for (j = 124; j > 0; j--)
            ;
}

void main()
{
    int timeInterruptCounter = 0; //ADC采集时间控制

    //推挽
    P0M1 = 0x00;
    P0M0 = 0xff;

    P2M1 = 0x00;
    P2M0 = 0x08;

    SEL3 = 0; // LED灯关闭（永远关闭）

    EA = 1;   //使能(enable)总中断源
    EADC = 1; //使能ADC中断，EA=1 并且 EADC=1 ADC产生
    //中断后中断函数才能被调用
    weixuan_count = 0;
    timeInterruptCounter = 0;
    InitAndStartADC_temperature();

    while (1)
    {
        SEG_Display();
        timeInterruptCounter++;
        if (timeInterruptCounter > 200)
        {

            InitAndStartADC_temperature(); //每次转化之前都要初始化ADC相关寄存器

            timeInterruptCounter = 0;
        }
    }
}

//对应温度部分的处理数据
void data_processtemperature()
{
    temperaturebaiwei = datatemperature % 1000 / 100;
    temperatureshiwei = datatemperature % 100 / 10;
    temperaturegewei = datatemperature % 10;
}

//AD中断
void adc_isr() interrupt 5
{
    EADC = 0;
    datatemperature = ADC_RES * 256 + ADC_RESL; //从寄存器中读取转换结果
    data_processtemperature();
    //转换完成后，ADC_FLAG清零
    ADC_CONTR &= ~0x10;
    EADC = 1;
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
    while (weixuan_count < 3)
    {

        weixuan(weixuan_count);
        switch (weixuan_count)
        {
        case 0:
            P0 = segtable[temperaturebaiwei];
            break;
        case 1:
            P0 = segtable[temperatureshiwei];
            break;
        default:
            P0 = segtable[temperaturegewei];
            break;
        }

        delay(5); //延时5ms

        weixuan_count++;
    }
}
