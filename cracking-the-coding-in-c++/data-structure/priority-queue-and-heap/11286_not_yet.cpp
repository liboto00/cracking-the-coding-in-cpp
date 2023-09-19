// 백준 온라인 저지 11286번 https://www.acmicpc.net/problem/11286
// 제한 시간 : 1초 (추가 시간 없음)
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int>& minHeap, int x, int y)
{
	int temp = minHeap[x];
	minHeap[x] = minHeap[y];
	minHeap[y] = temp;
}

void Push(vector<int>& minHeap, int x)
{
	minHeap.push_back(x);

	int heapSize = minHeap.size() - 1;
	int child = heapSize;
	int parent = child / 2;

	while (child > 1 && abs(minHeap[child]) <= abs(minHeap[parent]))
	{
		if (abs(minHeap[child]) == abs(minHeap[parent]) && minHeap[child] >= minHeap[parent])
		{
			break;
		}

		Swap(minHeap, child, parent);
		child = parent;
		parent = child / 2;
	}
}

int Pop(vector<int>& minHeap)
{
	int root = minHeap[1];

	int heapSize = minHeap.size() - 1;
	Swap(minHeap, 1, heapSize);
	minHeap.pop_back();
	heapSize--;

	int parent = 1;
	int child = parent * 2;
	
	if (child + 1 <= heapSize)
	{
		child = abs(minHeap[child]) < abs(minHeap[child + 1]) ? child : child + 1;
	}
	
	while (child <= heapSize && minHeap[child] < minHeap[parent])
	{
		Swap(minHeap, child, parent);
		parent = child;
		child = parent * 2;

		if (child + 1 <= heapSize)
		{
			child = (abs(minHeap[child]) < abs(minHeap[child + 1])) ? child : child + 1;
		}
	}

	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> minHeap(1, 0);

	int N;
	int x;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x != 0)
		{
			Push(minHeap, x);
		}
		else
		{
			if (minHeap.size() == 1)
			{
				cout << 0 << '\n';
				continue;
			}

			// 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거하는 경우
			cout << Pop(minHeap) << '\n';
		}
	}
}