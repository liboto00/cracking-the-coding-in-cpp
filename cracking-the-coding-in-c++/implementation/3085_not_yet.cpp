// ���� �¶��� ���� 3085�� https://www.acmicpc.net/problem/3085
// ���� �ð� : 1��
// ���� �ð� : ms

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ������ ũ�� N (3 �� N �� 50)
	int N;
	cin >> N;

	// ������ ���� ����
	vector<vector<char>> board(N, vector<char> (N));
	// ���� ����(�������� C, �Ķ����� P, �ʷϻ��� Z, ������� Y)
	string str;
	for (size_t y = 0; y < N; y++)
	{
		cin >> str;
		istringstream ss(str);
		while (getline(ss, str, ' '))
		{
			for (size_t x = 0; x < str.size(); x++)
			{
				board[y][x] = str[x];
			}
		}
	}
	
	// C, P, Z, Y ������ ���� ���� �� �ִ� ������ �ִ� ������ ���ϰ� ���� �� �� �ִ밪 ���ϱ�.
	
}