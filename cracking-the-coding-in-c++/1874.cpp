// ���� �¶��� ���� 1874�� https://www.acmicpc.net/problem/1874
// ���� �ð� : 2��
// ���� �ð� : ms

// ������ : �Է°��� ���� sequence stack�� top�� ���� �� sequence�� ��� �ִ� ��쿡 Error�� �߻��Ѵ�. e.g. num�� ù �Է°��� 1�� ���

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // ������ ũ��
	int num; // �Է� ���� 1~n������ ���� �ӽ÷� ����
	int maxNumOfPop; // �˵� �� �� �ִ밪
	stack<int> sequence; // �Է� ���� 1~n������ ���� ����
	vector<string> pushOrPop; // push�� pop�� ����. ��, ������ push�� pop ���θ� ��� ������ �� ���

	cin >> n;
	vector<bool> isPop(n, false); // ������ �� ������ pop ���θ� üũ

	cin >> num;
	int isPopIndex = num - 1;
	for (int i = 0; i < num; i++)
	{
		sequence.push(i + 1);
		pushOrPop.push_back("+");
	}
	maxNumOfPop = sequence.top();
	pushOrPop.push_back("-");
	sequence.pop();
	isPop[isPopIndex] = true;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> num;
		isPopIndex = num - 1;

		// pop�� �� ��(isPop�� ���� true�� ��)���� �ݺ�
		while (!isPop[isPopIndex])
		{
			// ���� �Է°��� sequence�� top�� ������,
			if (num == sequence.top())
			{
				// pop
				sequence.pop(); // sequence�� top�� �ִ� �� pop
				pushOrPop.push_back("-"); // pushOrPop�� - push
				isPop[isPopIndex] = true; // pop�� ���� ��ġ�� ���� true�� �ٲٱ�
			}
			// ���� �Է°��� sequence�� top���� ������,
			else if (num < sequence.top())
			{
				// ���� sequence�� top�� �Էµ� ��(num) ���̿� �ٸ� ���� �����Ѵٸ�,
				if ((sequence.top() - num) > 1)
				{
					// ���� sequence�� top�� �Էµ� �� ������ ���� pop ���� �ʾҴٸ�,
					if (true)
					{
						cout << "NO";
						break;
					}
				}
				// ���� sequence�� top�� �Էµ� ��(num) ���̿� �ٸ� ���� ���ٸ�,
				else if ((sequence.top() - num) == 1)
				{
					// pop
					sequence.pop(); // sequence�� top�� �ִ� �� pop
					pushOrPop.push_back("-"); // pushOrPop�� - push
					isPop[isPopIndex] = true; // pop�� ���� ��ġ�� ���� true�� �ٲٱ�

				}
			}
			// ���� �Է°��� sequence�� top���� ũ��, sequence���� pop�� �� �� �ִ밪���� ũ�ٸ�,
			else if (num > sequence.top() && num > maxNumOfPop)
			{
				// maxNumOfPop���� num��ŭ �ݺ�
				for (int i = maxNumOfPop + 1; i <= num; i++)
				{
					sequence.push(i);
					pushOrPop.push_back("+"); // pushOrPop�� - push
				}
				// pop
				sequence.pop(); // sequence�� top�� �ִ� �� pop
				pushOrPop.push_back("-"); // pushOrPop�� - push
				isPop[isPopIndex] = true; // pop�� ���� ��ġ�� ���� true�� �ٲٱ�
			}

			// �Է� ���� �˵� �� �� �ִ밪(maxNumOfPop)���� ũ�ٸ�,
			if (num > maxNumOfPop)
			{
				// num�� �� �˵� �� �� �ִ밪(maxNumOfPop)
				maxNumOfPop = num;
			}
		}
	}

	// ��� pop�� �ƴٸ�,
	if (sequence.empty())
	{
		// pushOrPop�� push(+), pop(-) ���� ���
		for (string i : pushOrPop)
		{
			cout << i << '\n';
		}
	}
}