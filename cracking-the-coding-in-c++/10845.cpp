// 백준 온라인 저지 10845번 https://www.acmicpc.net/problem/10845
// 제한 시간 : 0.5초
// 실행 시간 : 12ms

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

	vector<string> queue;
	string input;
	string word;
	for (int i = 0; i < N; i++)
	{
		vector<string> queue_operation;

		getline(cin, input);
		stringstream ss(input);
		while (ss >> word)
		{
			queue_operation.push_back(word);
		}

		if (queue_operation[0] == "push")
		{
			queue.push_back(queue_operation[1]);
		}
		else if (queue_operation[0] == "pop")
		{
			if (queue.begin() == queue.end())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << *queue.begin() << '\n';
				queue.erase(queue.begin());
			}
		}
		else if (queue_operation[0] == "size")
		{
			cout << queue.size() << '\n';
		}
		else if (queue_operation[0] == "empty")
		{
			if (queue.begin() == queue.end())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (queue_operation[0] == "front")
		{
			if (queue.begin() == queue.end())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << *queue.begin() << '\n';
			}
		}
		else if (queue_operation[0] == "back")
		{
			if (queue.begin() == queue.end())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << *(queue.end() - 1) << '\n';
			}
		}
	}
}