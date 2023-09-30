// ���� �¶��� ���� 13023�� https://www.acmicpc.net/problem/13023
// ���� �ð� : 2��
// ���� �ð� : ms

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& list, vector<int>& visited, int start)
{
	int connectedNode;

	for (int i = 0; i < list[start].size(); i++)
	{
		connectedNode = list[start][i];

		if (visited[connectedNode] == 0)
		{
			visited[connectedNode] = 1;
			start = list[start][i];
			dfs(list, visited, start);
		}
		visited[connectedNode] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ù° �ٿ� ����� �� N (5 �� N �� 2000)�� ģ�� ������ �� M (1 �� M �� 2000)
	int N, M, u, v;
	cin >> N >> M;

	vector<vector<int>> list(N + 1, vector <int>());
	vector<int> visited(N + 1, 0);

	// ģ���� ���� �� M��ŭ �ݺ�
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	// ���谡 ���������� 4�� �̻� �̾�����, 1 ��� �ƴϸ�, 0 ���
	for (int i = 0; i < M; i++)
	{
		// ���� �� ������ �Ź� ���� ī������ �ʱ�ȭ �ؾ��Ѵ�.
		dfs(list, visited, i);
		if ()
		{

		}
	}
}