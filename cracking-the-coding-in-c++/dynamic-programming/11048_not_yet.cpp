// ���� �¶��� ���� 11048�� https://www.acmicpc.net/problem/11048
// ���� �ð� : 1��
// ���� �ð� : ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M; // (1 �� N, M �� 1,000)
	cin >> N >> M;

	vector<vector<int>> board(N + 1, vector<int> (M + 1));
	for (size_t y = 1; y < N + 1; y++)
	{
		for (size_t x = 1; x < M + 1; x++)
		{
			cin >> board[y][x];
		}
	}

	// ������ �������� ��� ����� ���� ���� �ִ밪�� ���ϱ�

	// �ر԰� (r, c)�� �ִٰ� �������� ��,
	// (r+1, c) �Ǵ� (r, c+1) �Ǵ� (r+1, c+1)�� �̵��� ���� ������ �����ϱ�
}