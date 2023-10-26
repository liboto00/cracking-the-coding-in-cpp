// ���� �¶��� ���� 1697�� https://www.acmicpc.net/problem/1697
// ���� �ð� : 2��
// ���� �ð� : ms	

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)
	int N, K;
	cin >> N >> K;

	if (N == K)
	{
		cout << 0;

		return 0;
	}

	// �������� ��ġ�� X�� ��, 1�� ��, �̵� ��ġ
	// 1. X - 1
	// 2. X + 1
	// 3. 2 * X �̵�
	vector<int> position(2 * K, 0);
	int nowN = N;
	int direction[4] = {nowN - 1, nowN + 1, 2 * nowN};
	int cntStep = 0;

	while (!position[K])
	{
		cntStep++;

		for (size_t i = 0; i < 3; i++)
		{
			nowN = direction[i];

			if ((0 <= nowN && nowN <= 100000)
				&& position[nowN] == 0)
			{
				position[nowN] = cntStep;

				if (nowN == K)
				{
					cout << position[K];
					
					return 0;
				}
			}
		}
	}

	cout << position[K];
}