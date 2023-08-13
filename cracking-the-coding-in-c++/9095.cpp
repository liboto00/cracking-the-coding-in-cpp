// ���� �¶��� ���� 9095�� https://www.acmicpc.net/problem/9095
// ���� �ð� : 1�� (�߰� �ð� ����)
// ���� �ð� : 0ms

#include <iostream>
using namespace std;

int arr[11] = {0, };

int OneTwoThree(int n)
{
	switch (n)
	{
	case 1:
		return arr[n];
	case 2:
		return arr[n];
	case 3:
		return arr[n];
	default:
		if (arr[n] != 0)
		{
			return arr[n];
		}
		else
		{
			return OneTwoThree(n - 1) + OneTwoThree(n - 2) + OneTwoThree(n - 3);
		}
	}
}

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	int T;
	cin >> T;

	int n;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cout << OneTwoThree(n) << '\n';
	}
}