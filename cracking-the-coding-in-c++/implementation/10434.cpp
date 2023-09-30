// ���� �¶��� ���� 10434�� https://www.acmicpc.net/problem/10434
// ���� �ð� : 1��
// ���� �ð� : 160ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �׽�Ʈ ���̽��� �� (1 �� P �� 1000)
	int P;
	cin >> P;

	// �׽�Ʈ ���̽� ��ȣ
	int testCase;
	// �ູ�� �Ҽ����� ������ ���� (1 �� m �� 10000)
	int M;
	for (size_t i = 0; i < P; i++)
	{
		cin >> testCase >> M;

		if (M <= 1)
		{
			cout << testCase << ' ' << M << ' ' << "NO\n";
			continue;
		}

		// 1. �Ҽ����� �Ǻ�(�Ҽ��� �ƴ϶��, �ٷ� "NO" ���)
		vector<bool> eratos(M + 1, true);
		for (size_t i = 2; i * i <= M; i++)
		{
			if (eratos[i])
			{
				for (size_t j = i * i; j <= M; j += i)
				{
					eratos[j] = false;
				}
			}
		}

		// M�� �Ҽ��� �ƴ϶��,
		if (!eratos[M])
		{
			cout << testCase << ' ' << M << ' ' << "NO\n";
			continue;
		}

		// 2. �Ҽ� => �ڸ����� ������ ���� ���ϴ� ������ �ݺ����� ��, ���� 1�� �Ǵ� ������ �Ǻ�
		int happyNum = M;
		vector<int> checkHappyNum(10000, 0);
		bool isHappyNum = true;
		for (size_t i = 0; M != 1; i++)
		{	
			if (!isHappyNum)
			{
				cout << testCase << ' ' << happyNum << ' ' << "NO\n";

				break;
			}
			else
			{
				isHappyNum = true;
			}

			checkHappyNum[i] += (M / 1000) * (M / 1000);
			checkHappyNum[i] += ((M % 1000) / 100) * ((M % 1000) / 100);
			checkHappyNum[i] += ((M % 100) / 10) * ((M % 100) / 10);
			checkHappyNum[i] += (M % 10) * (M % 10);

			M = checkHappyNum[i];

			if (M == 1)
			{
				cout << testCase << ' ' << happyNum << ' ' << "YES\n";

				break;
			}
			else
			{
				// �ڸ����� ������ ���� ���� ���ߴ� ���� ������,
				
				for (int j = 0; j < i; j++)
				{
					if (checkHappyNum[i] == checkHappyNum[j])
					{
						isHappyNum = false;

						break;
					}
				}
			}
		}
	}
}