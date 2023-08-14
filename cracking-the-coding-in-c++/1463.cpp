// ���� �¶��� ���� 1463�� https://www.acmicpc.net/problem/1463
// ���� �ð� : 0.15��
// ���� �ð� : 8ms

#include <iostream>
using namespace std;

int minimum[1000001] = { 1000000 };
int compare[3];

int MakeItOne(int N)
{
	for (int i = 4; i <= N; i++)
	{
		// 3���� ������ ��������,
		if (i % 3 == 0)
		{
			// ù ��° �� ���ҿ� ����
			compare[0] = i / 3;
		}
		// �ƴϸ�,
		else
		{
			// minimum�� ù ��° ���Ұ��� 1,000,000�� ����Ų��.
			compare[0] = 0;
		}

		// 2�� ������ ��������,
		if (i % 2 == 0)
		{
			// �� ��° �� ���ҿ� ����
			compare[1] = i / 2;
		}
		// �ƴϸ�,
		else
		{
			// minimum�� ù ��° ���Ұ��� 1,000,000�� ����Ų��.
			compare[1] = 0;
		}
		
		// 1�� �� �� �� ��° �� ���ҿ� ����
		compare[2] = i - 1;

		if (minimum[compare[0]] <= minimum[compare[1]])
		{
			if (minimum[compare[0]] <= minimum[compare[2]])
			{
				minimum[i] = minimum[compare[0]] + 1;
			}
			else
			{
				minimum[i] = minimum[compare[2]] + 1;
			}
		}
		else if (minimum[compare[1]] <= minimum[compare[2]])
		{
			minimum[i] = minimum[compare[1]] + 1;
		}
		else
		{
			minimum[i] = minimum[compare[2]] + 1;
		}
	}

	return minimum[N];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	minimum[1] = 0;
	minimum[2] = 1;
	minimum[3] = 1;

	int N;
	cin >> N;

	switch (N)
	{
	case 1:
		cout << minimum[N];
		return 0;
	case 2:
		cout << minimum[N];
		return 0;
	case 3:
		cout << minimum[N];
		return 0;
	}

	cout << MakeItOne(N);
}