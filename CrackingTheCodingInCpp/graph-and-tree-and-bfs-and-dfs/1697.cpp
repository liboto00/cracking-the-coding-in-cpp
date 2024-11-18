// ���� �¶��� ���� 1697�� https://www.acmicpc.net/problem/1697
// ���� �ð� : 2��
// ���� �ð� : 0ms	

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �������� ���� ��ġ N(0 �� N �� 100,000), ������ ���� ��ġ K(0 �� K �� 100,000)
	int N, K;
	cin >> N >> K;

	typedef pair<int, int> p;
	queue<p> q;
	// ù ��° �� : �̵��� �ð�
	// �� ��° �� : �������� ��ġ
	q.push(make_pair(0, N));

	// �湮 ó��
	vector<int> visited(100001, 0);
	visited[N] = 1;

	while (!q.empty())
	{
		// �������� ��ġ�� ������ ��ġ�� ���ٸ�,
		if (q.front().second == K)
		{
			cout << q.front().first;

			return 0;
		}

		int front = q.front().second - 1;
		int back = q.front().second + 1;
		int jump = q.front().second * 2;

		// ������ �̵����� ���
		if (0 <= front && visited[front] == 0)
		{
			visited[front] = 1;
			q.push(make_pair(q.front().first + 1, front));
		}

		// �ڷ� �̵����� ���
		if (back < 100001 && visited[back] == 0)
		{
			visited[back] = 1;
			q.push(make_pair(q.front().first + 1, back));
		}

		// ������ 2�� �̵����� ���
		if (jump < 100001 && visited[jump] == 0)
		{
			visited[jump] = 1;
			q.push(make_pair(q.front().first + 1, jump));
		}

		q.pop();
	}

	return 0;
}