// 백준 온라인 저지 1920번 https://www.acmicpc.net/problem/1920
// 제한 시간 : 1초
// 실행 시간 : 52ms

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

	// 오름차순 정렬된 arrayN의 원소들을 반으로 나눠 mI가 절반 값보다 작은지 큰지 확인
	if (left != right)
	{
		// 중간에 위치한 값과 같으면,
		if (mI == arrN[mid])
		{
			return 1;
		}
		// 중간에 위치한 값보다 작으면,
		else if (mI < arrN[mid])
		{
			// 왼쪽에서 이분 탐색
			return BinarySearch(arrN, left, mid, mI);
		}
		// 중간에 위치한 값보다 크면,
		else if (mI > arrN[mid])
		{
			// 오른쪽에서 이분 탐색
			return BinarySearch(arrN, mid + 1, right, mI);
		}
	}
	// left와 right 값이 같으면,
	else
	{
		// 중간에 위치한 값과 같으면,
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