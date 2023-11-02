// 백준 온라인 저지 13023번 https://www.acmicpc.net/problem/13023
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> visited(N, 0);
void FindABCDE(int nowNode)
{
	// 겹치는 노드없이 한 번에 쭉 노드를 탐색했을 때,
	if ()
	{
		// 간선이 4개 이상이면,
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

	// 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)
	cin >> N >> M;

	// 사람 간의 관계 존재 여부 설정
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