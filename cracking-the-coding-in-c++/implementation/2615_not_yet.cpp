// 백준 온라인 저지 2615번 https://www.acmicpc.net/problem/2615
// 제한 시간 : 1초
// 실행 시간 : ms

// 반례 : https://www.acmicpc.net/board/view/83649

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int board[20][20] = { 0, };
	for (size_t y = 1; y <= 19; y++)
	{
		for (size_t x = 1; x <= 19; x++)
		{
			cin >> board[y][x]; 
		}
	}

	// 흑돌, 백돌 연속된 개수 판단
	// 
	// 가로줄 : 열만 1씩 커지는 경우
	// 세로줄 : 행만 1씩 커지는 경우
	// 대각선줄 : 행, 열이 동시에 1씩 커지는 경우

	int cntBlack = 0;
	int cntWhite = 0;
	int maxNumOfBlack = 0;
	int maxNumOfWhite = 0;
	pair<int, int> positionOfBlack;
	pair<int, int> positionOfWhite;
	for (int y = 1; y <= 18; y++)
	{
		for (int x = 1; x <= 18; x++)
		{
			// 흑돌을 만나면,
			if (board[y][x] == 1)
			{
				cntBlack = 1;

				// 가로줄에 있는 흑돌의 개수 판단
				for (int nowX = x + 1; nowX <= 19; nowX++)
				{
					if (board[y][nowX] == 1)
					{
						cntBlack++;
					}
					else
					{
						break;
					}
				}
				// 현재 위치한 가로줄에 있는 흑돌의 개수가 연속된 흑돌들 중 최대값 보다 크고, 6 미만이라면,
				if (maxNumOfBlack < cntBlack && cntBlack < 6)
				{
					// 현재 위치한 가로줄에 있는 흑돌의 개수가 최대값
					maxNumOfBlack = cntBlack;

					// 맨 왼쪽에 있는 흑돌의 위치
					positionOfBlack.first = y;
					positionOfBlack.second = x;
				}
				cntBlack = 1;

				// 세로줄에 있는 흑돌의 개수 판단
				for (int nowY = y + 1; nowY <= 19; nowY++)
				{
					if (board[nowY][x] == 1)
					{
						cntBlack++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfBlack < cntBlack && cntBlack < 6)
				{
					maxNumOfBlack = cntBlack;

					// 맨 위쪽에 있는 흑돌의 위치
					positionOfBlack.first = y;
					positionOfBlack.second = x;
				}
				cntBlack = 1;

				// 대각선줄에 있는 흑돌의 개수 판단
				for (int i = 1; (y + i <= 19) && (x + i <= 19); i++)
				{
					if (board[y + i][x + i] == 1)
					{
						cntBlack++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfBlack < cntBlack && cntBlack < 6)
				{
					maxNumOfBlack = cntBlack;

					// 맨 왼쪽 위에 있는 흑돌의 위치
					positionOfBlack.first = y;
					positionOfBlack.second = x;
				}
				cntBlack = 1;
			} 
			// 백돌을 만나면,
			else if (board[y][x] == 2)
			{
				cntWhite = 1;

				// 가로줄에 있는 백돌의 개수 판단
				for (int nowX = x + 1; nowX <= 19; nowX++)
				{
					if (board[y][nowX] == 2)
					{
						cntWhite++;
					}
					else
					{
						break;
					}
				}
				// 현재 위치한 가로줄에 있는 백돌의 개수가 연속된 백돌들 중 최대값 보다 크고, 6 미만이라면,
				if (maxNumOfWhite < cntWhite && cntWhite < 6)
				{
					// 현재 위치한 가로줄에 있는 백돌의 개수가 최대값
					maxNumOfWhite = cntWhite;

					// 맨 왼쪽에 있는 백돌의 위치
					positionOfWhite.first = y;
					positionOfWhite.second = x;
				}
				cntWhite = 1;

				// 세로줄에 있는 백돌의 개수 판단
				for (int nowY = y + 1; nowY <= 19; nowY++)
				{
					if (board[nowY][x] == 2)
					{
						cntWhite++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfWhite < cntWhite && cntWhite < 6)
				{
					maxNumOfWhite = cntWhite;

					// 맨 위쪽에 있는 백돌의 위치
					positionOfWhite.first = y;
					positionOfWhite.second = x;
				}
				cntWhite = 1;

				// 대각선줄에 있는 백돌의 개수 판단
				for (int i = 1; (y + i <= 19) && (x + i <= 19); i++)
				{
					if (board[y + i][x + i] == 2)
					{
						cntWhite++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfWhite < cntWhite && cntWhite < 6)
				{
					maxNumOfWhite = cntWhite;

					// 맨 왼쪽 위에 있는 백돌의 위치
					positionOfWhite.first = y;
					positionOfWhite.second = x;
				}
				cntWhite = 1;
			}
		}
	}

	if (maxNumOfWhite < maxNumOfBlack)
	{
		cout << 1 << '\n';
		cout << positionOfBlack.first << ' ' << positionOfBlack.second;
	}
	else if (maxNumOfWhite > maxNumOfBlack)
	{
		cout << 2 << '\n';
		cout << positionOfWhite.first << ' ' << positionOfWhite.second;
	}
	else
	{
		cout << 0 << '\n';
	}
}