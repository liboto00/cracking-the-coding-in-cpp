// ���� �¶��� ���� 11286�� https://www.acmicpc.net/problem/11286
// ���� �ð� : 1�� (�߰� �ð� ����)
// ���� �ð� : 16ms

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> p;

void Swap(vector<p>& minHeap, int x, int y)
{
	int absTemp = minHeap[x].first;
	minHeap[x].first = minHeap[y].first;
	minHeap[y].first = absTemp;

	int temp = minHeap[x].second;
	minHeap[x].second = minHeap[y].second;
	minHeap[y].second = temp;
}

void Push(vector<p>& minHeap, int x)
{
	minHeap.push_back(make_pair(abs(x), x));

	int heapSize = minHeap.size() - 1;
	int child = heapSize;
	int parent = child / 2;

	while (child > 1 && minHeap[child].first <= minHeap[parent].first)
	{
		if (minHeap[child].first == minHeap[parent].first && minHeap[child].second >= minHeap[parent].second)
		{
			break;
		}

		Swap(minHeap, child, parent);
		child = parent;
		parent = child / 2;
	}
}

int Pop(vector<p>& minHeap)
{
	int root = minHeap[1].second;

	int heapSize = minHeap.size() - 1;
	Swap(minHeap, 1, heapSize);
	minHeap.pop_back();
	heapSize--;

	int parent = 1;
	int child = parent * 2;
	
	if (child + 1 <= heapSize)
	{
		if (minHeap[child].first < minHeap[child + 1].first)
		{
			child = child;
		}
		else if (minHeap[child].first > minHeap[child + 1].first)
		{
			child = child + 1;
		}
		else
		{
			if (minHeap[child].second <= minHeap[child + 1].second)
			{
				child = child;
			}
			else
			{
				child = child + 1;
			}
		}
	}
	
	while (child <= heapSize && minHeap[child].first <= minHeap[parent].first)
	{
		if (minHeap[child].first == minHeap[parent].first && minHeap[child].second >= minHeap[parent].second)
		{
			break;
		}

		Swap(minHeap, child, parent);
		parent = child;
		child = parent * 2;

		if (child + 1 <= heapSize)
		{
			if (minHeap[child].first < minHeap[child + 1].first)
			{
				child = child;
			}
			else if (minHeap[child].first > minHeap[child + 1].first)
			{
				child = child + 1;
			}
			else
			{
				if (minHeap[child].second <= minHeap[child + 1].second)
				{
					child = child;
				}
				else
				{
					child = child + 1;
				}
			}
		}
	}

	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<p> minHeap(1, make_pair(0, 0));

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

			// �迭���� ������ ���� ���� ���� ����ϰ�, �� ���� �迭���� �����ϴ� ���
			cout << Pop(minHeap) << '\n';
		}
	}
}