// ���� �¶��� ���� 6236�� https://www.acmicpc.net/problem/6236
// ���� �ð� : 1��
// ���� �ð� : ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int>& atm, int M)
{
	int ans = 0;
	sort(atm.begin(), atm.end());

	int start = 1;
	// �Ϸ� �̿� �ִ� �ݾ�
	int end = 10000 * 100000 + 1;

	int cntWithdrawal = 0;
	// ���� �� ���� ����
	int sumOfMoney = 0;
	bool isCharge = true;
	while (start <= end)
	{
		// ���� �ݾ� K = mid
		size_t K = (start + end) / 2;

		isCharge = true;
		sumOfMoney = 0;
		cntWithdrawal = 0;

		// ���� ����
		for (int i = 0; i < atm.size(); i++)
		{
			// �����ؾ� �ϴ� �ݾ׺��� ������ �ִ� �ݾ��� ũ�ų� ������,
			if (atm[i] <= sumOfMoney)
			{
				sumOfMoney -= atm[i];
			}
			// �����ؾ� �ϴ� �ݾ׺��� ������ �ִ� �ݾ��� ������,
			else
			{
				// ����
				sumOfMoney = K;

				// ���� Ƚ�� ī����
				cntWithdrawal++;

				// ������ �ݾ� K�� atm[i]���� ������
				if (K < atm[i])
				{
					isCharge = false;

					// ���� ����� �ݾ��� ����
					break;
				}
				// ������ �ݾ��� ���� ����� �ݾ׺��� ���ų� ������,
				else
				{
					// ���忡 �ٽ� ����ְ�, �ٽ� K�� ����
					sumOfMoney -= atm[i];
				}
			}
		}

		// ���� ���� Ƚ�� M���� �Ⱓ �� ������ Ƚ������ ũ��,
		if (M < cntWithdrawal || !isCharge)
		{
			start = K + 1;
		}
		else
		{
			ans = K;
			end = K - 1;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N��, ���� ���� Ƚ�� M�� (1 �� N �� 100,000, 1 �� M �� N)
	int N, M;
	cin >> N >> M;

	vector<int> atm(N, 0);
	for (size_t i = 0; i < atm.size(); i++)
	{
		cin >> atm[i];
	}

	int K = BinarySearch(atm, M);
	cout << K;

	return 0;
}