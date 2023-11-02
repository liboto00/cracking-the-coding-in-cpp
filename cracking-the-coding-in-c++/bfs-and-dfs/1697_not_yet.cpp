// 백준 온라인 저지 1697번 https://www.acmicpc.net/problem/1697
// 제한 시간 : 2초
// 실행 시간 : ms	

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)
	int N, K;
	cin >> N >> K;

	if (N == K)
	{
		cout << 0;

		return 0;
	}

	vector<int> visited(200001, 0);
	visited[N] = 1;
	typedef pair<int, int> p;
	queue<p> q;
	q.push(make_pair(N, 0));

	while (!q.empty())
	{
		q.back().second++;

		int nowN = q.front().first;

		int moving[3] = { nowN - 1, nowN + 1, 2 * nowN };
		for (size_t i = 0; i < 3; i++)
		{
			if (moving[i] < 0 || 200000 < moving[i])
				continue;

			if (visited[moving[i]] == 0)
			{
				visited[q.back().first] = 1;
				q.push(make_pair(moving[i], ++q.back().second));

				if (q.back().first == K)
				{
					cout << q.back().second / 3;

					if (q.back().second % 3 == 0)
						cout << q.back().second / 3;
					else
						cout << (q.back().second / 3) + 1;

					return 0;
				}
			}
		}
		q.pop();
	}

	return 0;
}