// 백준 온라인 저지 1874번 https://www.acmicpc.net/problem/1874
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> stack;
	vector<string> is_stack_ascending_order;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		// 수열의 모든 값을 -1로 대입 ∵ pop되지 않은 수열의 값을 구분하기 위해서
		stack.push_back(-1); 
	}

	// 현재 입력값(num)
	int num; 
	// pop된 값 중 최대값(max_num)
	int max_num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		// 만약 pop된 값 중 최대값(max_num)이 현재 입력값(num)보다 크면,
		if (max_num > num) 
		{
			// max_num보다 작고 num보다 큰 값(temp)이 존재하면 없을 때까지 반복
			for (int i = num + 1; num < i && i < max_num; i++)
			{
				// 아직 pop이 안 된 값이 있다면(= stack 원소의 값이 -1이라면),
				if (stack[i - 1])
				{
					// "NO" 출력 후, 프로그램 종료
					cout << "NO";
					return 0;
				}
			}
			// 현재 입력값(num)의 -1을 한 원소 위치에 1 대입 ∵ pop된 값으로 구분하기 위해서
			stack[num - 1] = 1;
			// pop 기록
			is_stack_ascending_order.push_back("-");
		}
		// 만약 pop된 값 중 최대값(max_num)이 현재 입력값(num)보다 작으면,
		else if (max_num < num) 
		{
			// 현재 입력값의 -1을 한 원소 위치에 1 대입 ∵ pop된 값으로 구분하기 위해서
			stack[num - 1] = 1; 

			// max_num에서 num만큼 is_stack_ascending_order에 +(push) 대입 후, -(pop) 대입
			for (int i = max_num; i < num; i++)
			{
				// push 기록
				is_stack_ascending_order.push_back("+");
			}
			// pop 기록
			is_stack_ascending_order.push_back("-");

			// 현재 입력값이 pop된 값 중 최대값
			max_num = num;
		}
	}

	for (int i : stack)
	{
		cout << stack[i] << '\n';
	}
}
