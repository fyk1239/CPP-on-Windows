#include "utility.h"		// 实用程序软件包
#include "string.h"			// 串类

int main(void)
{
	// 测试构造函数
	String s1("测试构造函数");
	Write(s1);
	String s2(s1);
	Write(s2);
	
	// 测试Read()
	cout << "输入s1:"; 
	s1 = Read(cin);
	cout << "输入s2:"; 
	s2 = Read(cin);
	
	// 测试Concat()
	Concat(s1 ,s2);
	Write(s1);

	// 测试Copy()
	s2 = "This is a string.";
	Copy(s1 ,s2);
	Write(s1);
	Copy(s1 ,s2, 4);
	Write(s1);

	// 测试Index()
	s1 = "This is a string.";
	s2 = "is";
	cout << Index(s1, s2) << endl;
	cout << Index(s1, s2, 6) << endl;

	// 测试SubString()
	String strTmp = SubString(s1, 2, 2);
	Write(strTmp);

	// 测式下标运算符
	cout << s1[1] << endl;
	
	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}
