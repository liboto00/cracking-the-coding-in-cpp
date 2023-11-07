// ���� �¶��� ���� 1991�� https://www.acmicpc.net/problem/1991
// ���� �ð� : 2��
// ���� �ð� : ms

#include <iostream>
#include <vector>
using namespace std;

int N;
string path;
void SearchBinaryTree(vector<char>& tree, int level)
{
	// ���� ������ Ž���ϸ�,
	if ()
	{
		// Ž���� ��带 ��� ��,
		cout << path;

		// ��ȯ
		return;
	}

	path.push_back(tree[level]);
	SearchBinaryTree(tree, 2 * level);
	path.pop_back();

	path.push_back(tree[level + 1]);
	SearchBinaryTree(tree, 2 * level + 1);
	path.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	char nodes[4] = {};
	vector<char> tree(N * 3 + 1, '.');

	// ���(i), ���� �ڽ� ���(2 * i), ������ �ڽ� ��� �Է�(2 * i + 1)
	int indexRange = 1;
	for (size_t i = 1; i <= N; i++)
	{
		cin >> nodes[0];
		int indexOfParent = -1;
		if (tree[i] == '.')
		{
			bool isExist = false;
			for (size_t j = i; j < indexRange; j++)
			{
				// �Է��� ���� Ʈ���� �̹� ������,
				if (nodes[0] == tree[j])
				{
					isExist = true;
					indexOfParent = j;

					break;
				}
			}

			if (!isExist)
			{
				tree[i] = nodes[0];
				indexOfParent = i;
			}
		}
		else
		{
			indexOfParent = i;
		}

		// i ������ �ƴ϶�, ù ��°�� �Է¹��� �θ� ��尡 �ִ� �ε��� �������� �����ؾ� ��.
		cin >> nodes[1];
		if (tree[2 * indexOfParent] == '.')
		{
			tree[2 * indexOfParent] = nodes[1];
		}
		
		cin >> nodes[2];
		if (tree[2 * indexOfParent + 1] == '.')
		{
			tree[2 * indexOfParent + 1] = nodes[2];
		}

		// ������� �Էµ� ������ �����ϴ� ����
		indexRange = 2 * i + 1;
	}

	SearchBinaryTree(tree, 1);
}