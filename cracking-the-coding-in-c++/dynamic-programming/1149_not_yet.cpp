// 백준 온라인 저지 1149번 https://www.acmicpc.net/problem/1149
// 제한 시간 : 0.5초 (추가 시간 없음)
// 실행 시간 : ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 집의 수 N(2 ≤ N ≤ 1,000)
	int N;
	cin >> N;

	vector<vector<int>> colorOfHouses(N, vector<int>(3, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> colorOfHouses[y][x];
		}
	}

	int minOfCost = 0;
	vector<vector<int>> selected(N, vector<int>(3, 0));
	pair<int, int> minOfXY[2];

	if (colorOfHouses[0][0] + colorOfHouses[1][1])
	{
		minOfCost = colorOfHouses[0][0] + colorOfHouses[1][1];
		minOfXY[0].first = 0;
		minOfXY[0].second = 0;
		minOfXY[1].first = 1;
		minOfXY[1].second = 1;
	}

	if (colorOfHouses[0][0] + colorOfHouses[1][2] < minOfCost)
	{
		minOfCost = colorOfHouses[0][0] + colorOfHouses[1][2];
		minOfXY[0].first = 0;
		minOfXY[0].second = 0;
		minOfXY[1].first = 1;
		minOfXY[1].second = 2;
	}

	if (colorOfHouses[0][1] + colorOfHouses[1][0] < minOfCost)
	{
		minOfCost = colorOfHouses[0][1] + colorOfHouses[1][0];
		minOfXY[0].first = 0;
		minOfXY[0].second = 1;
		minOfXY[1].first = 1;
		minOfXY[1].second = 0;
	}

	if (colorOfHouses[0][1] + colorOfHouses[1][2] < minOfCost)
	{
		minOfCost = colorOfHouses[0][1] + colorOfHouses[1][2];
		minOfXY[0].first = 0;
		minOfXY[0].second = 1;
		minOfXY[1].first = 1;
		minOfXY[1].second = 2;
	}

	if (colorOfHouses[0][2] + colorOfHouses[1][0] < minOfCost)
	{
		minOfCost = colorOfHouses[0][2] + colorOfHouses[1][0];
		minOfXY[0].first = 0;
		minOfXY[0].second = 2;
		minOfXY[1].first = 1;
		minOfXY[1].second = 0;
	}

	if (colorOfHouses[0][2] + colorOfHouses[1][1] < minOfCost)
	{
		minOfCost = colorOfHouses[0][2] + colorOfHouses[1][1];
		minOfXY[0].first = 0;
		minOfXY[0].second = 2;
		minOfXY[1].first = 1;
		minOfXY[1].second = 1;
	}

	selected[minOfXY[0].first][minOfXY[0].second] = 1;
	selected[minOfXY[1].first][minOfXY[1].second] = 1;

	for (size_t y = 2; y < N; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			if (selected[y - 2][x] == 1)
			{
				switch (x)
				{
				case 0:
					if (colorOfHouses[y][1] < colorOfHouses[y][2])
					{
						minOfCost += colorOfHouses[y][1];
						selected[y][1] = 1;
					}
					else
					{
						minOfCost += colorOfHouses[y][2];
						selected[y][2] = 1;
					}
					break;
				case 1:
					if (colorOfHouses[y][0] < colorOfHouses[y][2])
					{
						minOfCost += colorOfHouses[y][0];
						selected[y][0] = 1;
					}
					else
					{
						minOfCost += colorOfHouses[y][2];
						selected[y][2] = 1;
					}
					break;
				case 2:
					if (colorOfHouses[y][0] < colorOfHouses[y][1])
					{
						minOfCost += colorOfHouses[y][0];
						selected[y][0] = 1;
					}
					else
					{
						minOfCost += colorOfHouses[y][1];
						selected[y][1] = 1;
					}
					break;
				default:
					break;
				}
			}
		}
	}

	cout << minOfCost;
}