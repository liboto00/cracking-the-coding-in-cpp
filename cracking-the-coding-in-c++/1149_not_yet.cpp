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

	vector<vector<int>> colorOfStreet(N, vector<int>(3, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> colorOfStreet[y][x];
		}
	}

	// ������ ���� ���� ���̸� �� �ȴٴ� ������ ������ DP
	// e.g. ù ��° ���� ù ��° ���� ���� ������ ���, �� ��° ���� ù ��° ���� �������� ���Ѵ�.
}