#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
아래와 같이 한 노드에 2개 이상의 노드들이 연결될 수 있기 때문에 '다중 연결 리스트(multi-linked list)'로 구현하려고 한다.

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