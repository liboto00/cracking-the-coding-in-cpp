// ���� �¶��� ���� 1991�� https://www.acmicpc.net/problem/1991
// ���� �ð� : 2��
// ���� �ð� : ms

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

	// vector�� tuple�� ����� �� ���� ���� �ڽ� ���, ������ �ڽ� ��� �Է�
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

	// ���� ��ȸ(��Ʈ) (���� �ڽ�) (������ �ڽ�)
	for (size_t i = 0; i < length; i++)
	{

	}

	// ���� ��ȸ(���� �ڽ�) (��Ʈ) (������ �ڽ�)
	for (size_t i = 0; i < length; i++)
	{

	}

	// ���� ��ȸ(���� �ڽ�) (������ �ڽ�) (��Ʈ)
	for (size_t i = 0; i < length; i++)
	{

	}
}