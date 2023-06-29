// ���� �¶��� ���� 1929�� https://www.acmicpc.net/problem/1929
// ���� �ð� : 2��
// ���� �ð� : 12ms

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	(M == 1) ? ++M : M;

	bool* primeNumber = new bool[N + 1];
	for (int i = 2; i <= N; i++)
	{
		primeNumber[i] = true;
	}

	for (int i = 2; i * i <= N; i++)
	{
		if (primeNumber[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				primeNumber[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (primeNumber[i])
		{
			cout << i << "\n";
		}
	}
}