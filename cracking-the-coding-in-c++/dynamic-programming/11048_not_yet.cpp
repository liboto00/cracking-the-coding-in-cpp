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
	
	int N, M, B;
	cin >> N >> M >> B;
	
	vector<vector<int>> ground(N, vector<int>(M));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> ground[y][x];
		}
	}


}