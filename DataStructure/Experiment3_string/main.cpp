#include "utility.h"		// ʵ�ó��������
#include "string.h"			// ����

int main(void)
{
	// ���Թ��캯��
	String s1("���Թ��캯��");
	Write(s1);
	String s2(s1);
	Write(s2);
	
	// ����Read()
	cout << "����s1:"; 
	s1 = Read(cin);
	cout << "����s2:"; 
	s2 = Read(cin);
	
	// ����Concat()
	Concat(s1 ,s2);
	Write(s1);

	// ����Copy()
	s2 = "This is a string.";
	Copy(s1 ,s2);
	Write(s1);
	Copy(s1 ,s2, 4);
	Write(s1);

	// ����Index()
	s1 = "This is a string.";
	s2 = "is";
	cout << Index(s1, s2) << endl;
	cout << Index(s1, s2, 6) << endl;

	// ����SubString()
	String strTmp = SubString(s1, 2, 2);
	Write(strTmp);

	// ��ʽ�±������
	cout << s1[1] << endl;
	
	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
