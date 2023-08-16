// ���� �¶��� ���� 1012�� https://www.acmicpc.net/problem/1012
// ���� �ð� : 1��
// ���� �ð� : 0ms

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	int M, N, K;
	
	typedef pair<int, int> p;
	queue<p> q;
	int x, y, nowX, nowY;

	// �����¿츦 ��Ÿ���� �迭
	int dy[4] = { 0, 0, -1, 1 };
	int dx[4] = { 1, -1, 0, 0 };
	int nextY, nextX;

	int minOfEarthworm;

	// test case��ŭ �ݺ�
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		minOfEarthworm = 0;

		vector<vector<int>> aFieldOfCabbage(50, vector<int>(50, 0));
		vector<vector<int>> visitedSection(50, vector<int>(50, 0));

		cin >> M >> N >> K;

		// ���߹翡 �ִ� ���߸� 1�� ǥ��, ���ٸ� 0
		for (int j = 0; j < K; j++)
		{
			cin >> x >> y;
			aFieldOfCabbage[y][x] = 1;
		}

		for (int x = 0; x < M; x++)
		{
			for (int y = 0; y < N; y++)
			{
				// ���߰� �ְ�, �湮�� ���� ���ٸ�,
				if (aFieldOfCabbage[y][x] == 1 && !visitedSection[y][x])
				{
					q.push(make_pair(y, x));
					visitedSection[y][x] = 1;

					// queue�� ������� ������ �ݺ�
					while (!q.empty())
					{
						nowY = q.front().first;
						nowX = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							nextY = nowY + dy[k];
							nextX = nowX + dx[k];

							if ((0 <= nextX && nextX < M) // x ���� �˻�
								&& (0 <= nextY && nextY < N) // y ���� �˻�
								&& (aFieldOfCabbage[nextY][nextX] == 1) // ���� ������ 1�̰�,
								&& !visitedSection[nextY][nextX]) // �湮�� ���� ���ٸ�,
							{
								visitedSection[nextY][nextX] = 1;
								q.push(make_pair(nextY, nextX));
							}
						}
					}
					minOfEarthworm++;
				}
			}
		}

		cout << minOfEarthworm << '\n';
	}
}