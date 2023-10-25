// 백준 온라인 저지 16926번 https://www.acmicpc.net/problem/16926
// 제한 시간 : 1초
// 실행 시간 : ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 배열의 크기 N, M (2 ≤ N, M ≤ 300)
	int N, M;
	// 회전 수 R (1 ≤ R ≤ 1,000)
	int R;

	cin >> N >> M >> R;

	vector<vector<int>> vec(N, vector<int>(M));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> vec[y][x];
		}
	}

	/*
	바깥 테두리 : 첫 행의 모든 열 + 끝 행의 모든 열 + 첫 열의 모든 행 + 끝 열의 모든 행
	안쪽 테두리 : 두 번째 행부터 마지막 - 1행까지의 두 번째 열부터 마지막 - 1열까지
	*/

	for (size_t i = 0; i < R; i++)
	{
		// 반 시계 방향으로 한 칸씩 이동
		
		// 한 칸씩 이동하기 위해서는 temp 필요
		vector<int> temp;

		// 첫 행 0열부터 끝 행 0열까지
		for (int y = 0; y < N - 1; y++)
		{
			temp.push_back(vec[y + 1][0]);
			vec[y + 1][0] = vec[y][0];
		}

		// 끝 행 0열부터 끝 행 끝 열까지

		
		// 끝 행 끝 열부터 첫 행 끝 열까지

		
		// 첫 행 끝 열부터 첫 행 첫 열까지

	}
}