// ���� �¶��� ���� 15990�� https://www.acmicpc.net/problem/15990
// ���� �ð� : 1�� (�߰� �ð� ����)
// ���� �ð� : ms

// 1, 2, 3�� ������ n(1 �� n �� 100,000)�� ��Ÿ���� ����� ���� 1,000,000,009�� ���� ������ ���ϱ�
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �׽�Ʈ ���̽��� ��
	int T;
	cin >> T;

	int n;// (1 �� n �� 100,000)

	int using1 = 0;
	int using2 = 0;
	int using3 = 0;
	int sum = 0;

	// �׽�Ʈ ���̽��� ����ŭ �ݺ�
	for (size_t i = 0; i < T; i++)
	{
		// ���� n �Է�
		cin >> n;

		if (n == 1)
		{
			cout << 1 << '\n';
		}
		else if (n == 2)
		{
			cout << 2 << '\n';
		}

		// n�� ���ϴ� ����� �� ���� ������ �ݺ�
		while (true)
		{
		// 1�� ���� ����� ���
			// 1�� ������ 2, 3 ���
			
		// 2�� ���� ����� ���
			// 2�� ������ 1, 3 ���
			
		// 3�� ���� ����� ���
			// 3�� ������ 1, 2 ���
						
		}
	}
}