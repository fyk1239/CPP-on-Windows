//�ֽ��������

#include <iostream>
using namespace std;

/*
 * 1���ж��ǲ������������ݹ��˳����� )
 */
bool isprime(int num)
{
	int i;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

void dividePrimeToFactors(int num)
{
	/*
	 * 2���ݹ����
	 */
	if (isprime(num))
	{
		cout << num << " ";
		return;
	}
	else
	{
		for (int i = 2;; i++)
		{
			if (num % i == 0 && isprime(i))
			{
				cout << i << " ";
				num /= i;
				dividePrimeToFactors(num);
				return;
			}
		}
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		dividePrimeToFactors(n);
		cout << endl;
	}
	return 0;
}