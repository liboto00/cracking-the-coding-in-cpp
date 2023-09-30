// 백준 온라인 저지 13023번 https://www.acmicpc.net/problem/13023
// 제한 시간 : 2초
// 실행 시간 : ms

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

	// 첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)
	int N, M, u, v;
	cin >> N >> M;

	vector<vector<int>> list(N + 1, vector <int>());
	vector<int> visited(N + 1, 0);

	// 친구의 관계 수 M만큼 반복
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	// 관계가 연속적으로 4번 이상 이어지면, 1 출력 아니면, 0 출력
	for (int i = 0; i < M; i++)
	{
		// 새로 돌 때마다 매번 관계 카운팅을 초기화 해야한다.
		dfs(list, visited, i);
		if ()
		{

		}
	}
}