// 백준 온라인 저지 1149번 https://www.acmicpc.net/problem/1149
// 제한 시간 : 0.5초 (추가 시간 없음)
// 실행 시간 : ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 집의 수 N(2 ≤ N ≤ 1,000)
	int N;
	cin >> N;

	vector<vector<int>> colorOfStreet(N, vector<int>(3));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			cin >> colorOfStreet[y][x];
		}
	}

	// 인접한 집과 같은 색이면 안 된다는 조건을 적용해 Brute force
	// e.g.
	// 첫 번째 행의 첫 번째 열의 색을 선택한 경우, 두 번째 행은 첫 번째 열을 선택하지 못한다.
	
	// 4, 4, 4번 실행
	for (size_t i = 0; i < ; i++)
	{

	}
}