// 백준 온라인 저지 1697번 https://www.acmicpc.net/problem/1697
// 제한 시간 : 2초
// 실행 시간 : ms	

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)
	int N, K;
	cin >> N >> K;

	// 수빈이의 위치가 X일 때, 1초 후, 이동 위치
	// 1. X - 1
	// 2. X + 1
	// 3. 2 * X 이동
	vector<int> position(2 * K, 0);
	int nowN = N;
	int direction[3] = {nowN - 1, nowN + 1, 2 * nowN};
	while (!position[K])
	{
		if (position[nowN] == 0)
			position[nowN] = 1;
		
		// dfs로 풀기
	}
}