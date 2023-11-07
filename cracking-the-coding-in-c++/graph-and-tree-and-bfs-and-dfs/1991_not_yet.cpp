// 백준 온라인 저지 1991번 https://www.acmicpc.net/problem/1991
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
using namespace std;

int N;
string path;
void SearchBinaryTree(vector<char>& tree, int level)
{
	// 말단 노드까지 탐색하면,
	if ()
	{
		// 탐색한 노드를 출력 후,
		cout << path;

		// 반환
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

	// 노드(i), 왼쪽 자식 노드(2 * i), 오른쪽 자식 노드 입력(2 * i + 1)
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
				// 입력한 값이 트리에 이미 있으면,
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

		// i 기준이 아니라, 첫 번째로 입력받은 부모 노드가 있는 인덱스 기준으로 설정해야 함.
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

		// 현재까지 입력된 노드들이 존재하는 범위
		indexRange = 2 * i + 1;
	}

	SearchBinaryTree(tree, 1);
}