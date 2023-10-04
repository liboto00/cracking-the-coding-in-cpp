// 백준 온라인 저지 13023번 https://www.acmicpc.net/problem/13023
// 제한 시간 : 2초
// 실행 시간 : ms

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
			// 연속적인 관계의 수 카운팅
			(*_cntConnectedNodes)++;
			dfs(list, visited, connectedNode, _cntConnectedNodes, _isABCDE);
		}
	}

	// start에서 다시 경로를 탐색하므로 방문했던 노드들은 다시 초기화
	visited[start] = 0;
	(*_cntConnectedNodes)--;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)
	int N, M, u, v;
	cin >> N >> M;

	vector<vector<int>> list(N, vector <int>());
	vector<int> visited(N, 0);

	// 친구의 관계 수 M만큼 반복
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	int cntConnectedNodes = 0;
	bool isABCDE = false;

	// 연속적인 관계의 수가 4번 이상 이어지면, 1 출력 아니면, 0 출력
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