// ���� �¶��� ���� 13023�� https://www.acmicpc.net/problem/13023
// ���� �ð� : 2��
// ���� �ð� : ms

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> visited(N, 0);
void FindABCDE(int nowNode)
{
	// ��ġ�� ������ �� ���� �� ��带 Ž������ ��,
	if ()
	{
		// ������ 4�� �̻��̸�,
		if (cnt >= 4)
		{
			cout << 0;
		}
		else
		{
			cout << 0;
		}

		return;
	}

	for (size_t i = 0; i < N; i++)
	{

		FindABCDE(i);

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ����� �� N (5 �� N �� 2000)�� ģ�� ������ �� M (1 �� M �� 2000)
	cin >> N >> M;

	// ��� ���� ���� ���� ���� ����
	vector<vector<int>> relation(N, vector<int>(N, 0));
	for (size_t i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		relation[u][v] = 1;
		relation[v][u] = 1;
	}

	for (size_t startNode = 0; startNode < N; startNode++)
	{
		FindABCDE(startNode);
	}

	cout << 0;
}