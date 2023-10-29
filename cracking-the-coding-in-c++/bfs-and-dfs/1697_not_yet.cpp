// ���� �¶��� ���� 1697�� https://www.acmicpc.net/problem/1697
// ���� �ð� : 2��
// ���� �ð� : ms	

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	// �����̿� ������ ��ġ N(0 �� N, K �� 100,000)
	int N, K;
	cin >> N >> K;

	if (N == K)
	{
		cout << 0;

		return 0;
	}

	vector<int> visited(100000, 0);
	visited[N] = 1;
	queue<int> q;
	q.push(N);

	int minTime = 0;
	while (!q.empty())
	{
		minTime++;

		int nowN = q.front();
		int moving[3] = { nowN - 1, nowN + 1, 2 * nowN };

		for (size_t i = 0; i < 3; i++)
		{
			if (visited[moving[i]] == 0)
			{
				visited[q.back()] = 1;

				q.push(moving[i]);
				if (q.back() == K)
				{
					if (minTime % 3 == 0)
						cout << minTime / 3;
					else
						cout << minTime / 3;

					return 0;
				}
			}
		}

		q.pop();
	}

	return 0;
}