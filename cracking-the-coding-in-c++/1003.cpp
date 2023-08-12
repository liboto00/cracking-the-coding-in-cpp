// ���� �¶��� ���� 1003�� https://www.acmicpc.net/problem/1003
// ���� �ð� : 0.25 �� (�߰� �ð� ����)
// ���� �ð� : 0ms

// ������ 1 : �޸� ���� 128mb �ʰ�
// �ذ� 1 : �� �׽�Ʈ ���̽����� vector�� �ʱ�ȭ�ϸ�, ���� ����� �޸𸮿� ��� ���̹Ƿ� �� ���� �ʱ�ȭ

#include <iostream>
using namespace std;

int fibonacciArr[41] = { 0 , };

int fibonacci(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibonacciArr[1] = 1;

	int testCase;
	cin >> testCase;

	int fiboNum;
	for (int i = 0; i < testCase; i++)
	{
		cin >> fiboNum;

		if (fiboNum == 0)
		{
			cout << "1 0\n";
		}
		else
		{
			cout << fibonacci(fiboNum - 1) << ' ' << fibonacci(fiboNum) << '\n';
		}
	}
}

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (fibonacciArr[n] != 0)
	{
		return fibonacciArr[n];
	}
	else
	{
		fibonacciArr[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return fibonacciArr[n];
	}
}