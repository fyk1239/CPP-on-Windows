#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int reverse(int x)
{
    int a=0;
    while(x!=0)
    {
        a=a*10+x%10;
        x=x/10;
    }
   
    return a;
}
bool check(int y)
{
    if(y<=n)return false;
    int day=y%100;
    y=y/100;
    int month=y%100;
    if(month<=12&&month>0&&day>0&&day<32)
    {
        if(day<=m[month])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
 
int main()
{
    
    
    cin>>n;
    for(int i=n/10000;;i++)
    {
        int c=i*10000+reverse(i);
        if(check(c))
        {
            cout<<c<<endl;
            break;
        }
    }
    for(int i=n/1000000;;i++)
    {
        int c=i*1000000+i*10000+reverse(i)*100+reverse(i);
        if(check(c))
        {
            cout<<c;
            break;
        }
    }
    return 0;
}