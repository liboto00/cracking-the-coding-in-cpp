// ���� �¶��� ���� 1697�� https://www.acmicpc.net/problem/1697
// ���� �ð� : 2��
// ���� �ð� : ms	

// ������ : �� ����Ŭ���� �ϳ��� ��θ� �� queue�� �׿��� bfs�� �� ����.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �����̰� �ִ� ��ġ N, ������ �ִ� ��ġ K
	int N, K; // (0 �� N, K �� 100,000)
	cin >> N >> K;

	vector<int> visited(100001, 0);
	queue<int> q;

	int nowN = N;
	int nextN;
	int minTime = 0;
	// �����̰� ������ ��ġ�� �� ������ �ݺ�
	while (nowN != K)
	{
		// �湮�� ���� ���ٸ�,
		if (visited[nowN] == 0)
		{
			// �湮 ó��
			visited[nowN] = 1;

			// queue�� nowN push
			q.push(nowN);

			// queue�� ������� ������ �ݺ�
			while (!q.empty())
			{
				nowN = q.front();
				q.pop();

				if (nowN == K)
				{
					cout << minTime;

					return 0;
				}

				int nAfterOneSecond[3] = { nowN + 1 , nowN - 1, nowN * 2 };
				/*int nowNPlusOne = nowN + 1;
				int nowNMinusOne = nowN - 1;
				int nowNMultiplyTwo = nowN * 2;*/

				for (int i = 0; i < 3; i++)
				{
					nextN = nAfterOneSecond[i];

					// �迭 ����(1��nAfterOneSecond��100,000)�� ���� �ʰ�,
					// �湮�� ���� ���ٸ�,
					if (0 <= nextN && nextN <= 100000
						&& visited[nextN] == 0)
					{
						// �湮ó��
						visited[nextN] = 1;
						q.push(nextN);

						if (nextN == K)
						{
							cout << minTime;

							return 0;
						}
					}
				}
			}
			minTime++;
		}
	}

	cout << minTime;
}