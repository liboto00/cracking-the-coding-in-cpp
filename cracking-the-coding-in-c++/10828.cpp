// 백준 온라인 저지 10828번 https://www.acmicpc.net/problem/10828
// 제한 시간 : 0.5초
// 실행 시간 : ms

// 핵심 : 스택이 비어있는지, 혹은 비어있지 않다면 들어있는 정수의 개수가 몇 개인지 판단

#include <iostream>
using namespace std;

void stack_function(int N, string* stack_operation_array, int* stack);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// stack 연습을 위해 STL을 사용하지 않고, new 연산자를 사용해 배열의 크기 동적할당
	int* stack = new int[N];
	string* stack_opeation_array = new string[N]{};

	stack_function(N, stack_opeation_array, stack);

	// 메모리 해제
	delete[] stack;
	delete[] stack_opeation_array;
}

void stack_function(int N, string* stack_operation_array, int* stack)
{
	string stack_opearion_string;
	int X;

	for (int i = 0; i < N; i++)
	{
		cin >> stack_opearion_string;

		if (stack_opearion_string == "push")
		{
			// 정수 X를 스택에 넣은 연산
			cin >> X;
		}
		else if (stack_opearion_string == "pop")
		{
			// 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력.
			// 스택에 들어있는 정수가 없는 경우에는 -1을 출력.
		}
		else if (stack_opearion_string == "size")
		{
			// 스택에 들어있는 정수의 개수를 출력
		}
		else if (stack_opearion_string == "empty")
		{
			// 스택이 비어있으면 1, 아니면 0을 출력
		}
		else if (stack_opearion_string == "top")
		{
			// 스택의 가장 위에 있는 정수를 출력
			// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		}
	}
}
