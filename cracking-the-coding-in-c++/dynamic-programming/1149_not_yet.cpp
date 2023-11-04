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
		minOfXY[0].first = 0;
		minOfXY[0].second = 0;
		minOfXY[1].first = 1;
		minOfXY[1].second = 1;
	}

	minOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
		colorOfHouses[minOfXY[1].first][minOfXY[1].second];

	if (colorOfHouses[0][0] + colorOfHouses[1][2] < minOfCost)
	{
		minOfXY[0].first = 0;
		minOfXY[0].second = 0;
		minOfXY[1].first = 1;
		minOfXY[1].second = 2;
	}

	minOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
		colorOfHouses[minOfXY[1].first][minOfXY[1].second];

	if (colorOfHouses[0][1] + colorOfHouses[1][0] < minOfCost)
	{
		minOfXY[0].first = 0;
		minOfXY[0].second = 1;
		minOfXY[1].first = 1;
		minOfXY[1].second = 0;
	}

	minOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
		colorOfHouses[minOfXY[1].first][minOfXY[1].second];

	if (colorOfHouses[0][1] + colorOfHouses[1][2] < minOfCost)
	{
		minOfXY[0].first = 0;
		minOfXY[0].second = 1;
		minOfXY[1].first = 1;
		minOfXY[1].second = 2;
	}

	minOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
		colorOfHouses[minOfXY[1].first][minOfXY[1].second];

	if (colorOfHouses[0][2] + colorOfHouses[1][0] < minOfCost)
	{
		minOfXY[0].first = 0;
		minOfXY[0].second = 2;
		minOfXY[1].first = 1;
		minOfXY[1].second = 0;
	}

	minOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
		colorOfHouses[minOfXY[1].first][minOfXY[1].second];

	if (colorOfHouses[0][2] + colorOfHouses[1][1] < minOfCost)
	{
		minOfXY[0].first = 0;
		minOfXY[0].second = 2;
		minOfXY[1].first = 1;
		minOfXY[1].second = 1;
	}

	minOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
		colorOfHouses[minOfXY[1].first][minOfXY[1].second];

	selected[minOfXY[0].first][minOfXY[0].second] = 1;
	selected[minOfXY[1].first][minOfXY[1].second] = 1;

	int tempMinOfCost = 1001;
	for (size_t y = 2; y < N - 1; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			if (selected[y - 1][x] == 1)
			{
				tempMinOfCost = 1001;

				switch (x)
				{
				case 0:
					if (colorOfHouses[y][1] + colorOfHouses[y + 1][2] < minOfCost)
					{
						minOfXY[0].first = y;
						minOfXY[0].second = 1;
						minOfXY[1].first = y + 1;
						minOfXY[1].second = 2;
					}

					tempMinOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
						colorOfHouses[minOfXY[1].first][minOfXY[1].second];

					if (colorOfHouses[y][2] + colorOfHouses[y + 1][1] < tempMinOfCost)
					{
						minOfXY[0].first = y;
						minOfXY[0].second = 2;
						minOfXY[1].first = y + 1;
						minOfXY[1].second = 1;
					}

					minOfCost += colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
						colorOfHouses[minOfXY[1].first][minOfXY[1].second];

					selected[y][minOfXY[0].second] = 1;

					break;
				case 1:
					if (colorOfHouses[y][0] + colorOfHouses[y + 1][2] < minOfCost)
					{
						minOfXY[0].first = y;
						minOfXY[0].second = 0;
						minOfXY[1].first = y + 1;
						minOfXY[1].second = 2;
					}

					tempMinOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
						colorOfHouses[minOfXY[1].first][minOfXY[1].second];

					if (colorOfHouses[y][2] + colorOfHouses[y + 1][0] < tempMinOfCost)
					{
						minOfXY[0].first = y;
						minOfXY[0].second = 2;
						minOfXY[1].first = y + 1;
						minOfXY[1].second = 0;
					}

					minOfCost += colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
						colorOfHouses[minOfXY[1].first][minOfXY[1].second];

					selected[y][minOfXY[0].second] = 1;
					break;
				case 2:
					if (colorOfHouses[y][0] + colorOfHouses[y + 1][1] < minOfCost)
					{
						minOfXY[0].first = y;
						minOfXY[0].second = 0;
						minOfXY[1].first = y + 1;
						minOfXY[1].second = 1;
					}

					tempMinOfCost = colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
						colorOfHouses[minOfXY[1].first][minOfXY[1].second];

					if (colorOfHouses[y][1] + colorOfHouses[y + 1][0] < tempMinOfCost)
					{
						minOfXY[0].first = y;
						minOfXY[0].second = 1;
						minOfXY[1].first = y + 1;
						minOfXY[1].second = 0;
					}

					minOfCost += colorOfHouses[minOfXY[0].first][minOfXY[0].second] +
						colorOfHouses[minOfXY[1].first][minOfXY[1].second];

					selected[y][minOfXY[0].second] = 1;
					break;
				default:
					break;
				}
			}
		}
	}

	cout << minOfCost;
}