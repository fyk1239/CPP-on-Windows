#include "quick_sort.h" // ���������㷨
#include "utility.h"	// ʵ�ó��������

int main()
{
	int a[11];
	for (int i = 0; i < 11; i++)
	{
		cin >> a[i];
	}
	
	cout << "����ǰ:";
	Display(a, 11);	 // ��ʾa
	QuickSort(a, 11); // ��������
	cout << "�����:";
	Display(a, 11); // ��ʾa

	system("PAUSE"); // ���ÿ⺯��system()
	return 0;		 // ����ֵ0, ���ز���ϵͳ
}
