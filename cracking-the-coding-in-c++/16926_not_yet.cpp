// ���� �¶��� ���� 16926�� https://www.acmicpc.net/problem/16926
// ���� �ð� : 1��
// ���� �ð� : ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �迭�� ũ�� N, M (2 �� N, M �� 300)
	int N, M;
	// ȸ�� �� R (1 �� R �� 1,000)
	int R;

	cin >> N >> M >> R;

	vector<vector<int>> vec(N, vector<int>(M));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> vec[y][x];
		}
	}

	/*
	�ٱ� �׵θ� : ù ���� ��� �� + �� ���� ��� �� + ù ���� ��� �� + �� ���� ��� ��
	���� �׵θ� : �� ��° ����� ������ - 1������� �� ��° ������ ������ - 1������
	*/

	for (size_t i = 0; i < R; i++)
	{
		// �� �ð� �������� �� ĭ�� �̵�
		
		// �� ĭ�� �̵��ϱ� ���ؼ��� temp �ʿ�
		vector<int> temp;

		// ù �� 0������ �� �� 0������
		for (int y = 0; y < N - 1; y++)
		{
			temp.push_back(vec[y + 1][0]);
			vec[y + 1][0] = vec[y][0];
		}

		// �� �� 0������ �� �� �� ������

		
		// �� �� �� ������ ù �� �� ������

		
		// ù �� �� ������ ù �� ù ������

	}
}