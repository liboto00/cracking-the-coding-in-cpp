// ���� �¶��� ���� 2108�� https://www.acmicpc.net/problem/2108
// ���� �ð� : 2��
// ���� �ð� : ms

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool FindTheSecondSmallestValue(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int FindMode(vector<int> numArr)
{
	vector<int>::iterator itr;
	vector<pair<int, int>> maxVal(numArr.size());
	for (int i = 0; i < numArr.size(); i++)
	{
		itr = (numArr.begin() + i);
		maxVal[i].first = *itr;
		maxVal[i].second = 0;
		
		while (itr != numArr.end())
		{
			if (find(itr, numArr.end(), maxVal[i].first) == numArr.end())
			{
				break;
			}
			itr++;
			maxVal[i].second++;
		}
	}

	sort(maxVal.begin(), maxVal.end(), FindTheSecondSmallestValue);
	
	vector<int> max(maxVal.size(), -4001);
	for (int i = 0; i < maxVal.size(); i++)
	{
		if (maxVal[i].second == maxVal[0].second)
		{
			max[i] = maxVal[i].first;
		}
		else
		{
			if (i == 1)
			{
				return max[0];
			}
			break;
		}
	}

	sort(maxVal.begin(), maxVal.end());

	return max[1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> numArr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> numArr[i];
	}

	// ���� ������ 1���� ��� ���� ó��
	if (N == 1)
	{
		cout << numArr[0] << '\n' << numArr[0] << '\n' << numArr[0] << '\n' << 0;

		return 0;
	}
	
	sort(numArr.begin(), numArr.end());

	// ������
	float avg = 0;
	for (int i = 0; i < N; i++)
	{
		avg += numArr[i];
	}
	avg /= N;

	cout << round(avg) << '\n';

	// �߾Ӱ�
	cout << numArr[N / 2] << '\n';

	// �ֺ�
	cout << FindMode(numArr) << '\n';

	// ����
	cout << *(numArr.end() - 1) - *numArr.begin();
}