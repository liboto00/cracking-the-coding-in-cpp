// 백준 온라인 저지 1697번 https://www.acmicpc.net/problem/1697
// 제한 시간 : 2초
// 실행 시간 : ms	

#include <iostream>
#include <vector>
using namespace std;

int main()
{
<<<<<<< HEAD
	// 수빈이와 동생의 위치 N(0 ≤ N, K ≤ 100,000)
=======
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)
>>>>>>> 23b18fe227aa3a0ec1e929ec71a06d7d9efb7d1c
	int N, K;
	cin >> N >> K;

	if (N == K)
	{
		cout << 0;

		return 0;
	}

<<<<<<< HEAD
	vector<int> visited(100000, 0);
	visited[N] = 1;
	queue<int> q;
	q.push(N);

	int minTime = 0;
	while (!q.empty())
	{
		minTime++;

		int nowN = q.front();
		int moving[3] = { nowN - 1, nowN + 1, 2 * nowN };

		for (size_t i = 0; i < 3; i++)
		{
			if (visited[moving[i]] == 0)
			{
				visited[q.back()] = 1;
=======
	// 수빈이의 위치가 X일 때, 1초 후, 이동 위치
	// 1. X - 1
	// 2. X + 1
	// 3. 2 * X 이동
	vector<int> position(2 * K, 0);
	int nowN = N;
	int direction[4] = {nowN - 1, nowN + 1, 2 * nowN};
	int cntStep = 0;

	while (!position[K])
	{
		cntStep++;

		for (size_t i = 0; i < 3; i++)
		{
			nowN = direction[i];

			if ((0 <= nowN && nowN <= 100000)
				&& position[nowN] == 0)
			{
				position[nowN] = cntStep;
>>>>>>> 23b18fe227aa3a0ec1e929ec71a06d7d9efb7d1c

				q.push(moving[i]);
				if (q.back() == K)
				{
<<<<<<< HEAD
					if (minTime % 3 == 0)
						cout << minTime / 3;
					else
						cout << minTime / 3;

=======
					cout << position[K];
					
>>>>>>> 23b18fe227aa3a0ec1e929ec71a06d7d9efb7d1c
					return 0;
				}
			}
		}

		q.pop();
	}

<<<<<<< HEAD
	return 0;
=======
	cout << position[K];
>>>>>>> 23b18fe227aa3a0ec1e929ec71a06d7d9efb7d1c
}