// 백준 온라인 저지 2477번 https://www.acmicpc.net/problem/2477
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 참외의 개수
	int K;
	cin >> K;

	// 참외밭
	vector<vector<int>> field(1001, vector<int> (1001, 0));

	// 밭의 테두리 구하기
	int direction;
	int length;
	int y = 500, x = 500;
	for (size_t i = 1; i <= 6; i++)
	{
		cin >> direction >> length;

		switch (direction)
		{
		case 1:
			// 현재 위치부터 length까지 1로 변경해 길이를 표현
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				x++;
			}
			break;
		case 2:
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				x--;
			}
			break;
		case 3:
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				y++;
			}
			break;
		case 4:
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				y--;
			}
			break;
		default:
			break;
		}
	}

	bool isField;
	for (size_t nowY = 0; nowY < 1001; nowY++)
	{
		for (size_t nowX = 0; nowX < 1000; nowX++)
		{
			isField = false;

			// 이미 방문한 참외 밭을 만났다면,
			if (field[nowY][nowX] == 1)
			{
				// 1칸 앞도 방문한 참외 밭이라면,
				if (field[nowY][nowX + 1] == 1)
				{
					// 2가지 경우 존재
					// 1. Only 테두리 e.g. 00001111100000...
					// 2. 테두리 + 밭의 안 공간 e.g. 00001111000001000...

					for (size_t tempX = nowX; tempX < 1001; tempX++)
					{
						// 0을 만나면, 탈출
						if (field[nowY][tempX] == 0)
						{
							nowX = tempX;

							break;
						}
					}

					// 다시 1을 만나면 2번의 경우이고, 아니면 1번의 경우
					for (size_t tempX = nowX; tempX < 1001; tempX++)
					{
						// 다시 1을 만나면,
						if (field[nowY][tempX] == 1)
						{
							// 참외 밭 내부이므로 isField는 참이다.
							isField = true;
							break;
						}
					}

					// 2번의 경우 : 참외 밭 내부이지만, 아직 방문하지 않았다면,
					if (isField)
					{
						// 밭의 내부이므로 1로 방문 표시
						for (size_t tempX = nowX; field[nowY][tempX] != 1; tempX++)
						{
							field[nowY][tempX] = 1;

// Error 발생
							nowX = tempX;
						}
					}
				}
				// 아니라면,
				else
				{
					// 밭의 내부이므로 1로 방문 표시
					for (size_t tempX = nowX + 1; field[nowY][tempX] != 1; tempX++)
					{
						field[nowY][tempX] = 1;

						nowX = tempX;
					}
				}
			}
		}
	}
	
	// 1이 곧 1m^2을 나타냄으로 1의 개수를 구하기
	int sizeOfField = 0;
	for (size_t nowY = 0; nowY < 1001; nowY++)
	{
		for (size_t nowX = 0; nowX < 1001; nowX++)
		{
			if (field[nowY][nowX] == 1)
			{
				sizeOfField++;
			}
		}
	}
	
	// 밭의 크기와 참외의 개수의 곱 출력
	cout << sizeOfField * K;
}