// 백준 온라인 저지 10828번 https://www.acmicpc.net/problem/10828
// 제한 시간 : 0.5초
// 실행 시간 : 340ms

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	// cin >> N 이후의 입력에서 getline(cin, input)을 호출했을 때 줄 바꿈을 제거 하지 않으면, 
	// cin 버퍼에는 아직 줄 바꿈 문자가 남아있기 때문에 줄 바꿈 문자를 읽고 빈 문자열을 input에 저장한다.
	cin.ignore(); // 줄 바꿈 문자 제거

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
