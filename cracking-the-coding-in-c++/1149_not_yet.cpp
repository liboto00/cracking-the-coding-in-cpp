// ���� �¶��� ���� 1149�� https://www.acmicpc.net/problem/1149
// ���� �ð� : 0.5�� (�߰� �ð� ����)
// ���� �ð� : ms

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

	vector<vector<int>> colorOfStreet(N, vector<int>(3));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			cin >> colorOfStreet[y][x];
		}
	}

	// ������ ���� ���� ���̸� �� �ȴٴ� ������ ������ Brute force
	// e.g.
	// ù ��° ���� ù ��° ���� ���� ������ ���, �� ��° ���� ù ��° ���� �������� ���Ѵ�.
	
	// 4, 4, 4�� ����
	for (size_t i = 0; i < ; i++)
	{

	}
}