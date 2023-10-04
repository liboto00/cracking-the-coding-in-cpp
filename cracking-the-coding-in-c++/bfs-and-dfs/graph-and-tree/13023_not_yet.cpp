// ���� �¶��� ���� 13023�� https://www.acmicpc.net/problem/13023
// ���� �ð� : 2��
// ���� �ð� : ms

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& list, vector<int>& visited, int start, int* _cntConnectedNodes, bool* _isABCDE)
{
	int connectedNode;
	visited[start] = 1;

	for (size_t i = 0; i < list[start].size(); i++)
	{
		connectedNode = list[start][i];

		if (*_cntConnectedNodes >= 4)
		{
			*_isABCDE = true;

			return;
		}

		if (visited[connectedNode] == 0)
		{
			visited[connectedNode] = 1;
			// �������� ������ �� ī����
			(*_cntConnectedNodes)++;
			dfs(list, visited, connectedNode, _cntConnectedNodes, _isABCDE);
		}
	}

	// start���� �ٽ� ��θ� Ž���ϹǷ� �湮�ߴ� ������ �ٽ� �ʱ�ȭ
	visited[start] = 0;
	(*_cntConnectedNodes)--;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ù° �ٿ� ����� �� N (5 �� N �� 2000)�� ģ�� ������ �� M (1 �� M �� 2000)
	int N, M, u, v;
	cin >> N >> M;

	vector<vector<int>> list(N, vector <int>());
	vector<int> visited(N, 0);

	// ģ���� ���� �� M��ŭ �ݺ�
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	int cntConnectedNodes = 0;
	bool isABCDE = false;

	// �������� ������ ���� 4�� �̻� �̾�����, 1 ��� �ƴϸ�, 0 ���
	for (int i = 0; i < N; i++)
	{
		dfs(list, visited, i, &cntConnectedNodes, &isABCDE);

		if (isABCDE)
		{
			cout << 1;

			return 0;
		}
	}

	cout << 0;
}