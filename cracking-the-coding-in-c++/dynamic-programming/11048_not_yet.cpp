// ���� �¶��� ���� 11048�� https://www.acmicpc.net/problem/11048
// ���� �ð� : 1��
// ���� �ð� : ms

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