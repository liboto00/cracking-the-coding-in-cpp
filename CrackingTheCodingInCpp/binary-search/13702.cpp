// ���� �¶��� ���� 13702�� https://www.acmicpc.net/problem/13702
// ���� �ð� : 1��
// ���� �ð� : ms

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int BinarySearch(vector<int>& capacityOfMakgeolli, int maxCapacity, int K)
{
	int answer = 0;
	sort(capacityOfMakgeolli.begin(), capacityOfMakgeolli.end());

	size_t start = 0, end = (pow(2, 31));

	vector<int> originalCapacityOfMakgeolli = capacityOfMakgeolli;
	int cntFriends = 0;
	while (start <= end)
	{
		size_t mid = (start + end) / 2;
		cntFriends = 0;

		for (int j = 0; j < capacityOfMakgeolli.size(); j++)
		{
			cntFriends += max((size_t)0, capacityOfMakgeolli[j] / mid);
		}

		// ģ������ ��� mid��ŭ �Ծ��ٸ�,
		if (cntFriends >= K)
		{
			answer = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

		capacityOfMakgeolli = originalCapacityOfMakgeolli;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �����̰� �ֹ��� ���ɸ� �������� ����(N <= 10,000)
	int N;
	// �����̸� ������ ģ������ ��(K <= 1,000,000)
	int K;

	cin >> N >> K;

	// ���ɸ� �뷮 �Է�(0 <= ���ɸ� �뷮 <= 2^31 - 1)
	vector<int> capacityOfMakgeolli(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> capacityOfMakgeolli[i];
	}

	int maxCapacity = -1;
	maxCapacity = BinarySearch(capacityOfMakgeolli, maxCapacity, K);

	cout << maxCapacity;

	return 0;
}