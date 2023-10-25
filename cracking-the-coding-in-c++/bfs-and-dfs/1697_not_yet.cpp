// ���� �¶��� ���� 1697�� https://www.acmicpc.net/problem/1697
// ���� �ð� : 2��
// ���� �ð� : ms	

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)
	int N, K;
	cin >> N >> K;

	// �������� ��ġ�� X�� ��, 1�� ��, �̵� ��ġ
	// 1. X - 1
	// 2. X + 1
	// 3. 2 * X �̵�
	vector<int> position(2 * K, 0);
	int nowN = N;
	int direction[3] = {nowN - 1, nowN + 1, 2 * nowN};
	while (!position[K])
	{
		if (position[nowN] == 0)
			position[nowN] = 1;
		
		// dfs�� Ǯ��
	}
}