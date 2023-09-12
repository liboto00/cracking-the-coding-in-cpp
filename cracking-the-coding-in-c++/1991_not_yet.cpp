// 백준 온라인 저지 1991번 https://www.acmicpc.net/problem/1991
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	typedef tuple<char, char, char> tup;
	vector<tup> binary_tree;

	// vector와 tuple을 사용해 각 노드와 왼쪽 자식 노드, 오른쪽 자식 노드 입력
	char node, left_child, right_child;
	for (int i = 0; i < N; i++)
	{
		cin >> node >> left_child >> right_child;

		if (left_child == '.')
		{
			left_child = 0;
		}
		if (right_child == '.')
		{
			right_child = 0;
		}

		binary_tree.push_back(make_tuple(node, left_child, right_child));
	}

	// 전위 순회(루트) (왼쪽 자식) (오른쪽 자식)
	for (size_t i = 0; i < length; i++)
	{

	}

	// 중위 순회(왼쪽 자식) (루트) (오른쪽 자식)
	for (size_t i = 0; i < length; i++)
	{

	}

	// 후위 순회(왼쪽 자식) (오른쪽 자식) (루트)
	for (size_t i = 0; i < length; i++)
	{

	}
}