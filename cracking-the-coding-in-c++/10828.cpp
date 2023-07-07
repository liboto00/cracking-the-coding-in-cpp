// ���� �¶��� ���� 10828�� https://www.acmicpc.net/problem/10828
// ���� �ð� : 0.5��
// ���� �ð� : 340ms

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	// cin >> N ������ �Է¿��� getline(cin, input)�� ȣ������ �� �� �ٲ��� ���� ���� ������, 
	// cin ���ۿ��� ���� �� �ٲ� ���ڰ� �����ֱ� ������ �� �ٲ� ���ڸ� �а� �� ���ڿ��� input�� �����Ѵ�.
	cin.ignore(); // �� �ٲ� ���� ����

	string input;
	string word;
	
	vector<string> stack;
	for (int i = 0; i < N; i++)
	{
		vector<string> stack_operations;
		getline(cin, input);

		stringstream ss(input);
		while (ss >> word)
		{
			stack_operations.push_back(word);
		}

		if (stack_operations[0] == "push")
		{
			stack.push_back(stack_operations[1]);
		}
		else if (stack_operations[0] == "pop")
		{
			if (stack.begin() == stack.end())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << *(stack.end() - 1) << "\n";
				stack.erase(stack.end() - 1);
			}
		}
		else if (stack_operations[0] == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (stack_operations[0] == "empty")
		{
			if (stack.begin() == stack.end())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (stack_operations[0] == "top")
		{
			if (stack.begin() == stack.end())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << *(stack.end() - 1)  << "\n";
			}
		}
	}
}
