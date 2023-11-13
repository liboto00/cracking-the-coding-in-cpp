// ���� �¶��� ���� 1932�� https://www.acmicpc.net/problem/1932
// ���� �ð� : 2��
// ���� �ð� : 40ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// �ﰢ���� ũ�� n(1 �� n �� 500)
	int n;
	cin >> n;

	// 2���� �迭�� ����(������ 0 �̻� 9999 ����) �ﰢ�� ����
	vector<vector<int>> triangle(n, vector<int>(n, -1));
	for (size_t y = 0; y < n; y++)
	{
		for (size_t x = 0; x <= y; x++)
		{
			cin >> triangle[y][x];
		}
	}

	if (n == 1)
	{
		cout << triangle[0][0];

		return 0;
	}

	if (n == 2)
	{
		cout << triangle[0][0] + max(triangle[1][0], triangle[1][1]);

		return 0;
	}

	// 1������� ������ ���صα�
	triangle[1][0] += triangle[0][0];
	triangle[1][1] += triangle[0][0];

	// 2����� n����� ������ ���ϱ�
	for (size_t y = 2; y < n; y++)
	{
		for (size_t x = 0; x <= y; x++)
		{
			if (x == 0)
			{
				triangle[y][x] += triangle[y - 1][x];
			}
			else if (x == y)
			{
				triangle[y][x] += triangle[y - 1][x - 1];
			}
			else
			{
				triangle[y][x] += max(triangle[y - 1][x - 1], triangle[y - 1][x]);
			}
		}
	}

	int maxSum = -1;
	for (size_t x = 1; x < n; x++)
	{
		if (maxSum < max(triangle[n - 1][x - 1], triangle[n - 1][x]))
		{
			maxSum = max(triangle[n - 1][x - 1], triangle[n - 1][x]);
		}
	}

	cout << maxSum;

	return 0;
}