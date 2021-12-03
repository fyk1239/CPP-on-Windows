#include <STC15F2K60S2.H>

//2相4拍，STEP1-STEP2-STEP3-STEP4是顺时针转动，STEP1-STEP4-STEP3-STEP2是逆时针转动。

void STEP1() 
{
    A1 = 1;
    A2 = 0; 
    B1 = 1; 
    B2 = 0;
}
void STEP2() 
{
    A1 = 1;
    A2 = 0; 
    B1 = 0; 
    B2 = 1;
}
void STEP3() 
{
    A1 = 0;
    A2 = 1; 
    B1 = 0; 
    B2 = 1;
}
void STEP4() 
{
    A1 = 0;
    A2 = 1; 
    B1 = 1; 
    B2 = 0;
}

sbit EN1 = P1 ^ 0;
sbit A1 = P1 ^ 1;
sbit A2 = P1 ^ 2;
sbit EN2 = P1 ^ 3;
sbit B1 = P1 ^ 4;
sbit B2 = P1 ^ 5;

//延时函数
void DelayMS(unsigned int a)
{
    unsigned int i;
    while (a-- != 0)
    {
        for (i = 0; i < 600; i++)
            ;
    }
}

/*****
函数名：步进电机控制
调用：stepper(bit direction,unsigned char speed,unsigned long steps)
参数：direction(控制方向0为顺时针,1为逆时针)，speed(控制速度最快是1,速度快容易失步)，steps(走多少步)
返回值：无
*****/

void stepper(bit direction, unsigned char speed, unsigned long steps)
{
    unsigned long j;
    unsigned long k = 0;
    //stepsX4=steps/4;
    if (direction == 0)
    { //顺时针
        for (j = 0; j < steps; j++)
        {
            STEP1();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            } //steps一步是1.8度，到达设定步数就跳出循环

            STEP2();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            }

            STEP3();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            }
            STEP4();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            }
        }
    }
    else
    { //逆时针

        for (j = 0; j < steps; j++)
        {

            STEP1();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            }

            STEP4();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            }

            STEP3();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            }

            STEP2();
            DelayMS(speed);
            k++;
            if (k == steps)
            {
                break;
            }
        }
    }
}

//主函数

void main(void)

{
    EN1 = 1;
    EN2 = 1;

    while (1)
    {
        stepper(0, 5, 200);
        DelayMS(1000);
        stepper(1, 1, 200);
        DelayMS(1000);
    }
}