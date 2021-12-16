/**************************
光敏电阻的例程
**************************/

/**************************
使用头文件如下：
**************************/
#include "STC15F2K60S2.H"

/**************************
引脚别名定义如下：
**************************/

//数码管位选管脚定义
sbit SEL0 = P2 ^ 0;
sbit SEL1 = P2 ^ 1;
sbit SEL2 = P2 ^ 2;

sbit SEL3 = P2 ^ 3;

/**************************
定义变量如下：
**************************/
#define uint unsigned int

//存储从ADC读取到的测量结果
uint resultData = 0;

//用于设置光的显示的个位，十位，百位
unsigned char lightbaiwei = 0;
unsigned char lightshiwei = 0;
unsigned char lightgewei = 0;

unsigned char tempbaiwei = 0;
unsigned char tempshiwei = 0;
unsigned char tempgewei = 0;

char ADC_End_Flag = 0;

char weixuan_count;

//存储了0-f的显示编码
// 当选中某个数码管， 并将下面数组元素送入数码管的段选
//口，即P0口时，数码管就会显示对应的数字。比如送入
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

void SEG_Display();                //	  数码管显示函数声明
void InitAndStartADC_light(char);  //系统初始化
void date_processlight(int, char); //从ADC测量得到的数据处理以方便数码管的显示

//初始化ADC
void InitAndStartADC_light(char LightOrTemp)
{
    if (LightOrTemp == 1)
    {
        P1ASF = 0x10; //使用第4通道，因为光照传感器的输出段
                      //0x8C= 1000 1100b,打开ADC转换电源，转换速度
            //设置为每540个周期转换一次
            //启动ADC转换，	P1.4作为AD输入来源
            //具体内容参考数据手册相关谳
        ADC_CONTR = 0X84;
    }
    else if (LightOrTemp == 2) //如果是要测温度，就选择通道3，与
    //光照测量的配置只有P1ASF和ADC_CONTR不同
    {
        P1ASF = 0x08;
        ADC_CONTR = 0X83;
    }
    //接在了P1.4管脚
    ADC_RES = 0; //结果寄存器清零ADC_RES和ADC_RESL存放ADC读取
    //到的结果
    ADC_RESL = 0;

    ADC_CONTR = ADC_CONTR | 0x08;
    CLK_DIV = 0X20; //转换后的结果用10bit的，
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
    int data_before;
    int data_now;
    int count = 0;
    int datetemp = 0;
    //char ADC_End_Flag=0;
    char InitFlag = 0;
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
    //InitAndStartADC_light();
    InitFlag = 0;
    while (1)
    {
        SEG_Display();
        timeInterruptCounter++;
        if (timeInterruptCounter > 50)
        {
            InitAndStartADC_light(1); //每次转化之前都要初始化ADC相关寄存器
            while (ADC_End_Flag == 0)
                ;
            ADC_End_Flag = 0;
            if (InitFlag == 0)
            {
                data_before = resultData;
                data_now = resultData;
                InitFlag = 1;
            }

            else
            {
                data_now = resultData;
                if (data_before - data_now > 20)
                {
                    count++;
                }
                data_before = data_now;
            }
            date_processlight(count, 1);
            InitAndStartADC_light(2); //每次转化之前都要初始化ADC相关寄存器
            while (ADC_End_Flag == 0)
                ;
            ADC_End_Flag = 0;
            datetemp = resultData;
            date_processlight(datetemp, 2);
            timeInterruptCounter = 0;
        }
    }
}

//对应光和温度部分的处理数据
void date_processlight(int displayData, char lightOrtemp)
{
    if (lightOrtemp == 1)
    {
        lightbaiwei = displayData % 1000 / 100;
        lightshiwei = displayData % 100 / 10;
        lightgewei = displayData % 10;
    }

    else if (lightOrtemp == 2)
    {
        tempbaiwei = displayData % 1000 / 100;
        tempshiwei = displayData % 100 / 10;
        tempgewei = displayData % 10;
    }
}

//AD中断
void adc_isr() interrupt 5
{
    EADC = 0;
    ADC_End_Flag = 1;
    resultData = ADC_RES * 256 + ADC_RESL; //从寄存器中读取转换结果

    //date_processlight();
    //转换完成后，ADC_FLAG清零
    ADC_CONTR &= ~0X10;
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
    while (weixuan_count < 7)
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
        case 2:
            P0 = segtable[lightgewei];
            break;
        case 3:
            P0 = 0x00;
            break;
        case 4:
            P0 = segtable[tempbaiwei];
            break;
        case 5:
            P0 = segtable[tempshiwei];
            break;
        case 6:
            P0 = segtable[tempshiwei];
            break;
        default:
            P0 = 0x00;
            break;
        }
        delay(5); //延时5ms

        weixuan_count++;
    }
}