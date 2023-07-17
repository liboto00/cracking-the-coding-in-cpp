// ���� �¶��� ���� 2751�� https://www.acmicpc.net/problem/2751
// ���� �ð� : 2��
// ���� �ð� : ms

#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

// i: ���ĵ� ���� ����Ʈ�� ���� �ε���
// j: ���ĵ� ������ ����Ʈ�� ���� �ε���
// k: ���ĵ� ����Ʈ�� ���� �ε���
/* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
void merge(vector<int> stack, int left, int mid, int right)
{
	vector<int> sorted(1000, 0);
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right)
	{
		if (stack[i] <= stack[j])
			sorted[k++] = stack[i++];
		else
			sorted[k++] = stack[j++];
	}

	// ���� �ִ� ������ �ϰ� ����
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = stack[l];
	}
	// ���� �ִ� ������ �ϰ� ����
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = stack[l];
	}

	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 stack[]�� �纹��
	for (l = left; l <= right; l++)
	{
		stack[l] = sorted[l];
	}
}

void merge_sort(vector<int> stack, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		merge_sort(stack, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge_sort(stack, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge(stack, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int num;
	vector<int> stack;
	
	
	cin >> N;	
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		stack.push_back(num);
	}

	// sort(stack.begin(), stack.end());
	merge_sort(stack, 0, N);

	for (int i : stack)
	{
		cout << i << '\n';
	}
}