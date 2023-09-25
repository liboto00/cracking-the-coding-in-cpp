// 백준 온라인 저지 1697번 https://www.acmicpc.net/problem/1697
// 제한 시간 : 2초
// 실행 시간 : ms	

// 문제점 : 한 사이클에서 하나의 길로만 쭉 queue에 쌓여서 bfs로 안 돈다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수빈이가 있는 위치 N, 동생이 있는 위치 K
	int N, K; // (0 ≤ N, K ≤ 100,000)
	cin >> N >> K;

	vector<int> visited(100001, 0);
	queue<int> q;

	int nowN = N;
	int nextN;
	int minTime = 0;
	// 수빈이가 동생의 위치에 갈 때까지 반복
	while (nowN != K)
	{
		// 방문한 적이 없다면,
		if (visited[nowN] == 0)
		{
			// 방문 처리
			visited[nowN] = 1;

			// queue에 nowN push
			q.push(nowN);

			// queue가 비어있을 때까지 반복
			while (!q.empty())
			{
				nowN = q.front();
				q.pop();

				if (nowN == K)
				{
					cout << minTime;

					return 0;
				}

				int nAfterOneSecond[3] = { nowN + 1 , nowN - 1, nowN * 2 };
				/*int nowNPlusOne = nowN + 1;
				int nowNMinusOne = nowN - 1;
				int nowNMultiplyTwo = nowN * 2;*/

				for (int i = 0; i < 3; i++)
				{
					nextN = nAfterOneSecond[i];

					// 배열 범위(1≤nAfterOneSecond≤100,000)를 넘지 않고,
					// 방문한 적이 없다면,
					if (0 <= nextN && nextN <= 100000
						&& visited[nextN] == 0)
					{
						// 방문처리
						visited[nextN] = 1;
						q.push(nextN);

						if (nextN == K)
						{
							cout << minTime;

							return 0;
						}
					}
				}
			}
			minTime++;
		}
	}

	cout << minTime;
}