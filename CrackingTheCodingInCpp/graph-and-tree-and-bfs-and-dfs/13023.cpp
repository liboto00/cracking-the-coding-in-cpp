// ���� �¶��� ���� 13023�� https://www.acmicpc.net/problem/13023
// ���� �ð� : 2��
// ���� �ð� : 32ms

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cnt = 0;
int FindABCDE(vector<vector<int>>& relation, vector<int>& visited, int nowNode)
{
	// ��ġ�� ������ �� ���� ��带 Ž������ ��,
	// ������ 4�� �̻��̸�,
	if (cnt >= 4)
	{
		return 1;
	}

	for (size_t i = 0; i < relation[nowNode].size(); i++)
	{
		int connectedNode = relation[nowNode][i];

		if (visited[connectedNode] == 1)
			continue;

		visited[connectedNode] = 1;
		cnt++;
		if (FindABCDE(relation, visited, connectedNode))
		{
			return 1;
		}
		cnt--;
		visited[connectedNode] = 0;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ����� �� N (5 �� N �� 2000)�� ģ�� ������ �� M (1 �� M �� 2000)
	cin >> N >> M;

	// ��� ���� ���� ���� ���� ����
	vector<vector<int>> relation(N);
	vector<int> visited(N, 0);
	for (size_t i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		relation[u].push_back(v);
		relation[v].push_back(u);
	}

	for (int startNode = 0; startNode < N; startNode++)
	{
		visited[startNode] = 1;

		if (FindABCDE(relation, visited, startNode))
		{
			cout << 1;

			return 0;
		}

		visited[startNode] = 0;
	}

	cout << 0;

	return 0;
}