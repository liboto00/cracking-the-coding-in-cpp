// ���� �¶��� ���� 1149�� https://www.acmicpc.net/problem/1149
// ���� �ð� : 0.5�� (�߰� �ð� ����)
// ���� �ð� : 0ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ���� �� N(2 �� N �� 1,000)
	int N;
	cin >> N;

	vector<vector<int>> houses(N, vector<int>(3, 0));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			cin >> houses[y][x];
		}
	}

	vector<int> minCost = { houses[1][0], houses[1][1], houses[1][2] };
	for (size_t y = 1; y < N; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			switch (x)
			{
			case 0:
				if (houses[y - 1][1] < houses[y - 1][2])
				{
					houses[y][0] += houses[y - 1][1];
					minCost[x] = houses[y][0];
				}
				else
				{
					houses[y][0] += houses[y - 1][2];
					minCost[x] = houses[y][0];
				}
				break;
			case 1:
				if (houses[y - 1][0] < houses[y - 1][2])
				{
					houses[y][1] += houses[y - 1][0];
					minCost[x] = houses[y][1];
				}
				else
				{
					houses[y][1] += houses[y - 1][2];
					minCost[x] = houses[y][1];
				}
				break;
			case 2:
				if (houses[y - 1][0] < houses[y - 1][1])
				{
					houses[y][2] += houses[y - 1][0];
					minCost[x] = houses[y][2];
				}
				else
				{
					houses[y][2] += houses[y - 1][1];
					minCost[x] = houses[y][2];
				}
				break;
			default:
				break;
			}
		}
	}

	cout << min(min(minCost[0], minCost[1]), minCost[2]);

	return 0;
}