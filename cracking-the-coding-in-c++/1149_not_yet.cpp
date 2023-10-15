// 백준 온라인 저지 1149번 https://www.acmicpc.net/problem/1149
// 제한 시간 : 0.5초 (추가 시간 없음)
// 실행 시간 : ms

#include<iostream>
#include<vector>
using namespace std;

int N;
int visited[3][3] = {};
int path[3] = {};
int cnt = 0;
int minNum = 1001;
void Recursive(int level, vector<vector<int>> _colorOfStreet)
{
	if (level == N)
	{
		if (path[0] + path[1] + path[2] < minNum)
		{
			minNum = path[0] + path[1] + path[2];
		}

		return;
	}

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (y == 0 && visited[y][x] == 0)
			{
				visited[y][x] = 1;
				path[level] = _colorOfStreet[y][x];
				Recursive(level + 1, _colorOfStreet);
				visited[y][x] = 0;
				path[level] = 0;
				break;
			}
			else if (y > 0 && visited[y - 1][x] == 0 && visited[y][x] == 0)
			{
				visited[y][x] = 1;
				path[level] = _colorOfStreet[y][x];
				Recursive(level + 1, _colorOfStreet);
				visited[y][x] = 0;
				path[level] = 0;
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 집의 수 N(2 ≤ N ≤ 1,000)
	cin >> N;

	vector<vector<int>> colorOfStreet(N, vector<int>(3, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> colorOfStreet[y][x];
		}
	}

	// 인접한 집과 같은 색이면 안 된다는 조건을 적용해 Brute force
	// e.g. 첫 번째 행의 첫 번째 열의 색을 선택한 경우, 두 번째 행은 첫 번째 열을 선택하지 못한다.
	Recursive(0, colorOfStreet);

	cout << minNum;
}