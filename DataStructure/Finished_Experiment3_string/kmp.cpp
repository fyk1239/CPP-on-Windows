#include "utility.h"		// ʵ�ó��������
#include "kmpmatch.h"		// KMP�㷨

int main()
{	// ��ʽKMP�ַ���ģʽƥ���㷨
	String T("this is a string");
	String P("is");

	cout << KMPIndex(T, P) << endl;
	cout << KMPIndex(T, P, 3) << endl;
	cout << KMPIndex(T, P, 6) << endl;
	T=P;
	cout << KMPIndex(T, P) << endl;

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}