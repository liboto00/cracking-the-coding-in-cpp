// 백준 온라인 저지 11048번 https://www.acmicpc.net/problem/11048
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M; // (1 ≤ N, M ≤ 1,000)
	cin >> N >> M;

	vector<vector<int>> board(N + 1, vector<int> (M + 1));
	for (size_t y = 1; y < N + 1; y++)
	{
		for (size_t x = 1; x < M + 1; x++)
		{
			cin >> board[y][x];
		}
	}

	// 사탕을 가져오는 모든 경우의 수를 구해 최대값을 구하기

	// 준규가 (r, c)에 있다고 가정했을 때,
	// (r+1, c) 또는 (r, c+1) 또는 (r+1, c+1)로 이동한 경우로 나누어 생각하기
}