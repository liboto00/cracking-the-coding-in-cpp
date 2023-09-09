// 백준 온라인 저지 13023번 https://www.acmicpc.net/problem/13023
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &list, vector<int>&visited, int nodeNum, int cnt)
{
	for (int i = 0; i < list[nodeNum].size(); i++)
	{
		if (visited[list[nodeNum][i]] == 0)
		{
			// 방문 표시
			visited[list[nodeNum][i]] = list[nodeNum][i];
			cnt++;
			if (cnt >= 4)
			{
				cout << 1;
				break;
			}
			dfs(list, visited, nodeNum, cnt);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, u, v;
	cin >> N >> M;

	vector<vector<int>> list(N + 1, vector <int>());
	vector<int> visited(N + 1, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	dfs(list, visited, N - 1, 0);
}