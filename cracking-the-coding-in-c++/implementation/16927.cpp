// ���� �¶��� ���� 16927�� https://www.acmicpc.net/problem/16927
// ���� �ð� : 1��
// ���� �ð� : 144ms

#include <iostream>
#include <vector>
using namespace std;

int N, M;
void RotateCube(int nowRow, vector<vector<int>>& cube, vector<vector<int>>& cube_after_rotate)
{
	// ��
	// (0, M ~ 0, 1)
	// (0+1, M-1 ~ 0+1, 1+1)
	// ...
	for (size_t x = (M - 1) - nowRow; x >= 1 + nowRow; x--)
	{
		cube_after_rotate[nowRow][x - 1] = cube[nowRow][x];
	}

	// ����
	// (0, 0 ~ N-1, 0)
	// (0+1, 0+1 ~ N-1-1, 0+1)
	// ...
	for (size_t y = 0 + nowRow; y < N - 1 - nowRow; y++)
	{
		cube_after_rotate[y + 1][nowRow] = cube[y][nowRow];
	}

	// �Ʒ�
	// (N, 0 ~ N, M-1)
	// (N-1, 0+1 ~ N-1, M-1-1)
	// ... 
	for (size_t x = nowRow; x < M - 1 - nowRow; x++)
	{
		cube_after_rotate[(N - 1) - nowRow][x + 1] = cube[(N - 1) - nowRow][x];
	}

	// ������
	// (N, M) ~ (1, M)
	// (N-1, M-1) ~ (1+1, M-1)
	// ...
	for (size_t y = (N - 1) - nowRow; y >= 1 + nowRow; y--)
	{
		cube_after_rotate[y - 1][(M - 1) - nowRow] = cube[y][(M - 1) - nowRow];
	}

	// __________________________________________________________________________________________

	// ��
	for (size_t x = (M - 1) - nowRow; x >= 1 + nowRow; x--)
	{
		cube[nowRow][x] = cube_after_rotate[nowRow][x];
	}

	// ����
	for (size_t y = 0 + nowRow; y < N - 1 - nowRow; y++)
	{
		cube[y][nowRow] = cube_after_rotate[y][nowRow];
	}

	// �Ʒ� 
	for (size_t x = nowRow; x < M - 1 - nowRow; x++)
	{
		cube[(N - 1) - nowRow][x] = cube_after_rotate[(N - 1) - nowRow][x];
	}

	// ������
	for (size_t y = (N - 1) - nowRow; y >= 1 + nowRow; y--)
	{
		cube[y][(M - 1) - nowRow] = cube_after_rotate[y][(M - 1) - nowRow];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 2 �� N, M �� 300, 1 �� R �� 10^9
	int R;
	cin >> N >> M >> R;
	vector<vector<int>> cube(N, vector<int>(M, 0));

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> cube[y][x];
		}
	}

	vector<vector<int>> cube_after_rotate(N, vector<int>(M, 0));
	size_t the_num_of_border = min(N, M) / 2;
	for (size_t now_row = 0; now_row < the_num_of_border; now_row++)
	{
		for (size_t j = 0; j < R % (2 * (N + M - 2 - 4 * now_row)); j++)
		{
			RotateCube(now_row, cube, cube_after_rotate);
		}
	}

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cout << cube[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}