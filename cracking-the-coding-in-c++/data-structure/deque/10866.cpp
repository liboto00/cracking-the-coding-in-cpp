// 백준 온라인 저지 10866번 https://www.acmicpc.net/problem/10866
// 제한 시간 : 0.5초
// 실행 시간 : 8ms

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cin.ignore();

	vector<string> deque;
	string input;
	string word;
	for (int i = 0; i < N; i++)
	{
		vector<string> deque_operation;

		getline(cin, input);
		stringstream ss(input);
		while (ss >> word)
		{
			deque_operation.push_back(word);
		}

		if (deque_operation[0] == "push_front")
		{
			deque.insert(deque.begin(), deque_operation[1]);
		}
		else if (deque_operation[0] == "push_back")
		{
			deque.push_back(deque_operation[1]);
		}
		else if (deque_operation[0] == "pop_front")
		{
			if (deque.begin() == deque.end())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << *deque.begin() << '\n';
				deque.erase(deque.begin());
			}
		}
		else if (deque_operation[0] == "pop_back")
		{
			if (deque.begin() == deque.end())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << *(deque.end() - 1) << '\n';
				deque.erase(deque.end() - 1);
			}
		}
		else if (deque_operation[0] == "size")
		{
			cout << deque.size() << '\n';
		}
		else if (deque_operation[0] == "empty")
		{
			if (deque.begin() == deque.end())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (deque_operation[0] == "front")
		{
			if (deque.begin() == deque.end())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << *deque.begin() << '\n';
			}
		}
		else if (deque_operation[0] == "back")
		{
			if (deque.begin() == deque.end())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << *(deque.end() - 1) << '\n';
			}
		}
	}
}
