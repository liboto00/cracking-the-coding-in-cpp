// ���� �¶��� ���� 1920�� https://www.acmicpc.net/problem/1920
// ���� �ð� : 1��
// ���� �ð� : 52ms

#include <iostream>
#include <algorithm>
using namespace std;

bool BinarySearch(int* arrN, int left, int right, int mI);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int N;
	cin >> N;
	int* arrayN = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arrayN[i] = num;
	}

	int M;
	cin >> M;
	int* arrayM = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		arrayM[i] = num;
	}

	sort(arrayN, arrayN + N);

	for (int i = 0; i < M; i++)
	{
		cout << BinarySearch(arrayN, 0, N - 1, arrayM[i]) << '\n';
	}

	delete[] arrayN;
	delete[] arrayM;
}

bool BinarySearch(int* arrN, int left, int right, int mI)
{
	int mid = (left + right) / 2;

	// �������� ���ĵ� arrayN�� ���ҵ��� ������ ���� mI�� ���� ������ ������ ū�� Ȯ��
	if (left != right)
	{
		// �߰��� ��ġ�� ���� ������,
		if (mI == arrN[mid])
		{
			return 1;
		}
		// �߰��� ��ġ�� ������ ������,
		else if (mI < arrN[mid])
		{
			// ���ʿ��� �̺� Ž��
			return BinarySearch(arrN, left, mid, mI);
		}
		// �߰��� ��ġ�� ������ ũ��,
		else if (mI > arrN[mid])
		{
			// �����ʿ��� �̺� Ž��
			return BinarySearch(arrN, mid + 1, right, mI);
		}
	}
	// left�� right ���� ������,
	else
	{
		// �߰��� ��ġ�� ���� ������,
		if (mI == arrN[mid])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}