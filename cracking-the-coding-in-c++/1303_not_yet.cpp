// 백준 온라인 저지 1303번 https://www.acmicpc.net/problem/1303
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> battleField(100, vector<char>(100, 0));
	vector<vector<char>> visitedArea(100, vector<char>(100, 0));

	string s;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> s;
			battleField[y][x] = s[x];
		}
	}

	typedef pair<int, int> p;
	queue<p> q;

	vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
	vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};

	int theNumOfW , thePowerOfW = 0;
	int theNumOfB, thePowerOfB = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (battleField[y][x] == 'W' && !visitedArea[y][x])
			{
				theNumOfW = 1;

				visitedArea[y][x] = 1;
				q.push(make_pair(y, x));

				while (!q.empty())
				{
					int nowY = q.front().first;
					int nowX = q.front().second;

					q.pop();

					for (int i = 0; i < 8; i++)
					{
						int nextY = nowY + dy[i];
						int nextX = nowX + dx[i];

						if ((0 <= nextY && nextY < N)
							&& (0 <= nextX && nextX < M)
							&& battleField[nextY][nextX] == 'W'
							&& !visitedArea[nextY][nextX]
							)
						{
							visitedArea[nextY][nextX] = 1;
							q.push(make_pair(nextY, nextX));

							theNumOfW++;
						}
					}
				}

				//// 인접한 White 병사의 수가 5명 이상이고,
				//if (theNumOfW >= 5)
				//{
				//	for (int i = 0; i < N; i++)
				//	{
				//		// 대각선(\)으로만 인접한 경우라면,
				//		if (battleField[i][i] == 'W')
				//		{
				//			
				//		}
				//		// 대각선(/)으로만 인접한 경우라면,
				//		else if (battleField[i][N - 1 - i] == 'W')
				//		{
				//			
				//		}
				//		else
				//		{
				//			thePowerOfW += theNumOfW * theNumOfW;
				//		}
				//	}
				//}
			}
			else if (battleField[y][x] == 'B' && !visitedArea[y][x])
			{
				theNumOfB = 1;

				visitedArea[y][x] = 1;
				q.push(make_pair(y, x));

				while (!q.empty())
				{
					int nowY = q.front().first;
					int nowX = q.front().second;

					q.pop();

					for (int i = 0; i < 8; i++)
					{
						int nextY = nowY + dy[i];
						int nextX = nowX + dx[i];

						if ((0 <= nextY && nextY < N)
							&& (0 <= nextX && nextX < M)
							&& battleField[nextY][nextX] == 'B'
							&& !visitedArea[nextY][nextX]
							)
						{
							visitedArea[nextY][nextX] = 1;
							q.push(make_pair(nextY, nextX));

							theNumOfB++;
						}
					}
				}

				//// 인접한 Blue 병사의 수가 5명 이상이고, 
				//if (theNumOfB >= 5)
				//{
				//	// 대각선(\)으로만 인접한 경우라면,
				//	if (battleField[0][0] == 'B'
				//		&& battleField[1][1] == 'B'
				//		&& battleField[2][2] == 'B'
				//		&& battleField[3][3] == 'B'
				//		&& battleField[4][4] == 'B'
				//		)
				//	{
				//		thePowerOfB += theNumOfB;
				//	}
				//	// 대각선(/)으로만 인접한 경우라면,
				//	else if (battleField[0][4] == 'B'
				//		&& battleField[1][3] == 'B'
				//		&& battleField[2][2] == 'B'
				//		&& battleField[3][1] == 'B'
				//		&& battleField[4][0] == 'B'
				//		)
				//	{
				//		thePowerOfB += theNumOfB;
				//	}
				//	else
				//	{
				//		thePowerOfB += theNumOfB * theNumOfB;
				//	}
				//}
				//else
				//{
				//	thePowerOfB += theNumOfB;
				//}
			}
		}
	}

	cout << thePowerOfW << ' ' << thePowerOfB;
}