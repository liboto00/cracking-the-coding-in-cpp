// ���� �¶��� ���� 1138�� https://www.acmicpc.net/problem/1138
// ���� �ð� : 2��
// ���� �ð� : 0ms

#include <iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numOfPeople;
	cin >> numOfPeople;

	int leftPeople;
	vector<int> line(numOfPeople, 0);
	for (int i = 0; i < numOfPeople; i++)
	{
		cin >> leftPeople;

		// ���ʿ� leftPeople��ŭ�� ������ ����� �� �Ҵ�
		int cnt = 0;
		int j;
		for (j = 0; cnt != (leftPeople + 1); j++)
		{
			if (line[j] == 0)
			{
				cnt++;
			}
		}
		line[j - 1] = i + 1;
	}

	for (int i = 0; i < numOfPeople; i++)
	{
		cout << line[i] << ' ';
	}
}