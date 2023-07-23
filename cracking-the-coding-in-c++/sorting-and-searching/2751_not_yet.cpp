// 백준 온라인 저지 2751번 https://www.acmicpc.net/problem/2751
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

int sorted[1000000];

void merge(vector<int> vec, int left, int mid, int right)
{
	// i: 정렬된 왼쪽 리스트에 대한 인덱스
	// j: 정렬된 오른쪽 리스트에 대한 인덱스
	// k: 정렬될 리스트에 대한 인덱스
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
			sorted[k++] = vec[i++];
		else
			sorted[k++] = vec[j++];
	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = vec[l];
	}
	// 남아 있는 값들을 일괄 복사
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = vec[l];
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 vec[]로 재복사
	for (l = left; l <= right; l++)
	{
		vec[l] = sorted[l];
	}
}

void merge_sort(vector<int> vec, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		merge_sort(vec, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
		merge_sort(vec, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
		merge(vec, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int num;
	vector<int> vec;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	merge_sort(vec, 0, N - 1);

	for (int i : vec)
	{
		cout << i << '\n';
	}
}
