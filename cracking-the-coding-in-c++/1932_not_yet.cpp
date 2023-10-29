// 백준 온라인 저지 1932번 https://www.acmicpc.net/problem/1932
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> triangle(n, vector<int>(n, -1));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < y + 1; x++)
		{
			cin >> triangle[y][x];
		}
	}

	// Brute force

}