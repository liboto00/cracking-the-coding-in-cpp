#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
�Ʒ��� ���� �� ��忡 2�� �̻��� ������ ����� �� �ֱ� ������ '���� ���� ����Ʈ(multi-linked list)'�� �����Ϸ��� �Ѵ�.

1-2-3
 \/ /
 5-4-6

*/

typedef struct node
{
	int data;
	vector<struct node*> pointers;
} Node;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
	}

	
}