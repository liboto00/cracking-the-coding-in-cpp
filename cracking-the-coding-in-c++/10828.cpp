// 백준 온라인 저지 10828번 https://www.acmicpc.net/problem/10828
// 제한 시간 : 0.5초
// 실행 시간 : ms

// 핵심 : 스택이 비어있는지, 혹은 비어있지 않다면 들어있는 정수의 개수가 몇 개인지 판단

#include <iostream>
using namespace std;

void stack_function(int N, int* stack);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// stack 연습을 위해 STL을 사용하지 않고, new 연산자를 사용해 배열의 크기 동적할당
	int* stack = new int[0];

	stack_function(N, stack);

	// 메모리 해제
	delete[] stack;
}

void stack_function(int N, int* stack)
{
	string stack_opearion_string;
	int X;

	for (int i = 0; i < N; i++)
	{
		cin >> stack_opearion_string;

		if (stack_opearion_string == "push")
		{
			// 스택에 넣을 정수 X 입력
			cin >> X;
			
			// 배열의 끝에 값 위치 찾기(NULL을 만나기 전까지 i 증감)
			int j;
			for (j = 0; stack != NULL; j++);

			// 만약 스택에 들어있는 정수가 없다면,
			if (stack[0] == '\0')
			{
				stack[0] = X;
			}
			else
			{
				stack[j - 1] = X;
			}
		}
		else if (stack_opearion_string == "pop")
		{
			// 만약 스택에 들어있는 정수가 없다면,
			if (stack[0] == '\0')
			{
				// -1 출력
				cout << -1 << '\n';
			}
			// 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력.
			else
			{
				int j;
				// 배열의 끝에 값 위치 찾기(NULL을 만나기 전까지 i 증감)
				for (j = 0; stack != NULL; j++);

				cout << stack[j - 1]; // 가장 위에 있는 정수 출력
				stack[j - 1] = '\0'; // 출력 후 그 정수가 있던 위치의 값을 NULL값으로 변경
			}
		}
		else if (stack_opearion_string == "size")
		{
			// 스택에 들어있는 정수의 개수를 출력
			
			// 배열의 끝에 값 위치 찾기(NULL을 만나기 전까지 i 증감)
			int j;
			for (j = 0; stack != NULL; j++);

			cout << j - 1 << '\n';
		}
		else if (stack_opearion_string == "empty")
		{
			// 스택이 비어있으면, 1을 출력
			if (stack[0] == '\0')
			{
				cout << 1 << '\n';
			}
			// 아니면 0을 출력
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (stack_opearion_string == "top")
		{
			// 만약 스택에 들어있는 정수가 없다면,
			if (stack[0] == '\0')
			{
				// -1을 출력
				cout << -1 << '\n';
			}
			else
			{
				// 스택의 가장 위에 있는 값의 위치 찾기(NULL을 만나기 전까지 i 증감)
				int j;
				for (j = 0; stack != NULL; j++);

				// 스택의 가장 위에 있는 정수를 출력
				cout << stack[j - 1] << '\n';
			}
		}
	}
}
