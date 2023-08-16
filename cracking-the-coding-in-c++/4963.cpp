// ���� �¶��� ���� 4963�� https://www.acmicpc.net/problem/4963
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

	int w, h;

	int nowY, nowX, nextY, nextX;
	int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

	typedef pair<int, int> p;
	queue<p> q;

	int landOrSea;
	int numOfLand;
	cin >> w >> h;
	while (!(w == 0 && h == 0))
	{
		numOfLand = 0;

		vector<vector <int>> territory(50, vector<int>(50, 0));
		vector<vector <int>> visitedArea(50, vector<int>(50, 0));

		// ��(1), �ٴ�(0) �Է�
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> landOrSea;

				territory[y][x] = landOrSea;
			}
		}

		for (int x = 0; x < w; x++)
		{
			for (int y = 0; y < h; y++)
			{
				// ���̰�, ���� �湮���� �ʾҴٸ�,
				if (territory[y][x] == 1 && !visitedArea[y][x])
				{
					visitedArea[y][x] = 1;
					q.push(make_pair(y, x));
					
					while (!q.empty())
					{
						nowY = q.front().first;
						nowX = q.front().second;
						q.pop();

						for (int i = 0; i < 8; i++)
						{
							nextY = nowY + dy[i];
							nextX = nowX + dx[i];

							if ((0 <= nextX && nextX < w) && // w ���� �ȿ� �ִ��� Ȯ��
								(0 <= nextY && nextY < h) && // h ���� �ȿ� �ִ��� Ȯ��
								territory[nextY][nextX] == 1 && // ������ ���� ���̰�,
								!visitedArea[nextY][nextX] // ���� �湮���� �ʾҴٸ�,
								)
							{
								visitedArea[nextY][nextX] = 1;
								q.push(make_pair(nextY, nextX));
							}
						}
					}
					numOfLand++;
				}
			}
		}

		cout << numOfLand << '\n';
		
		// �ʺ� w, ���� h �Է�
		cin >> w >> h;
	}
}