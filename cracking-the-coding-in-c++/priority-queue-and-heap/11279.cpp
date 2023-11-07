// ���� �¶��� ���� 11279�� https://www.acmicpc.net/problem/11279
// ���� �ð� : 1�� (�߰� �ð� ����)
// ���� �ð� : 16ms

#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int>& maxHeap, int x, int y)
{
	int temp = maxHeap[x];
	maxHeap[x] = maxHeap[y];
	maxHeap[y] = temp;
}

// �迭�� ���� push�� �ϰ� parent���� ���� ���ų� ���� ������ ���Ѵ�.
void Push(vector<int>& maxHeap, int x)
{
	maxHeap.push_back(x);

	int child = maxHeap.size() - 1;
	int parent = child / 2;

	while (child > 1 && maxHeap[child] > maxHeap[parent])
	{
		Swap(maxHeap, child, parent);
		child = parent;
		parent = child / 2;
	}
}

// root�� pop�ϰ� �� �� ��带 root�� �÷� child���� ���ų� Ŭ ������ ���Ѵ�.
int Pop(vector<int>& maxHeap)
{
	int root = maxHeap[1];
	int heapSize = maxHeap.size() - 1;

	Swap(maxHeap, 1, heapSize);
	maxHeap.pop_back();
	heapSize--;

	int parent = 1;
	int child = parent * 2;

	// �ڽ� �� �� ū ���� ���� �ڽ� ����
	if (child + 1 <= heapSize)
	{
		child = (maxHeap[child] > maxHeap[child + 1]) ? child : child + 1;
	}

	while (child <= heapSize && maxHeap[child] > maxHeap[parent])
	{	
		Swap(maxHeap, child, parent);
		parent = child;
		child = parent * 2;

		if (child + 1 <= heapSize)
		{
			child = (maxHeap[child] > maxHeap[child + 1]) ? child : child + 1;
		}
	}

	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> maxHeap(1, 0);

	int N; // (1 �� N �� 100,000)
	int x; // ���꿡 ���� ���� (0 �� x < 2^31)

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		
		// x�� �ڿ����̸�,
		if (x > 0)
		{
			// ���� x ����
			Push(maxHeap, x);
		}
		else if (!x)
		{
			if (maxHeap.size() == 1)
			{
				cout << 0 << '\n';
				continue;
			}

			// ������ ���� ū �� ���
			cout << Pop(maxHeap) << '\n';
		}
	}
}