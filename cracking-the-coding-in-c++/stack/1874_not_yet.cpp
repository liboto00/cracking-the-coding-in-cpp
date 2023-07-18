// 백준 온라인 저지 1874번 https://www.acmicpc.net/problem/1874
// 제한 시간 : 2초
// 실행 시간 : ms

// 문제점 : 입력값과 현재 sequence stack의 top을 비교할 때 sequence가 비어 있는 경우에 Error가 발생한다. e.g. num의 첫 입력값이 1인 경우

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // 수열의 크기
	int num; // 입력 받을 1~n까지의 수를 임시로 저장
	int maxNumOfPop; // 팝된 값 중 최대값
	stack<int> sequence; // 입력 받을 1~n까지의 수를 저장
	vector<string> pushOrPop; // push와 pop을 저장. 단, 수열의 push와 pop 여부를 모두 저장한 후 출력

	cin >> n;
	vector<bool> isPop(n, false); // 수열의 각 수들의 pop 여부를 체크

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

		// pop이 될 때(isPop의 값이 true일 때)까지 반복
		while (!isPop[isPopIndex])
		{
			// 현재 입력값이 sequence의 top과 같으면,
			if (num == sequence.top())
			{
				// pop
				sequence.pop(); // sequence의 top에 있는 값 pop
				pushOrPop.push_back("-"); // pushOrPop에 - push
				isPop[isPopIndex] = true; // pop된 값의 위치의 값을 true로 바꾸기
			}
			// 현재 입력값이 sequence의 top보다 작으면,
			else if (num < sequence.top())
			{
				// 현재 sequence의 top과 입력된 수(num) 사이에 다른 값이 존재한다면,
				if ((sequence.top() - num) > 1)
				{
					// 현재 sequence의 top과 입력된 수 사이의 값이 pop 됐지 않았다면,
					if (true)
					{
						cout << "NO";
						break;
					}
				}
				// 현재 sequence의 top과 입력된 수(num) 사이에 다른 값이 없다면,
				else if ((sequence.top() - num) == 1)
				{
					// pop
					sequence.pop(); // sequence의 top에 있는 값 pop
					pushOrPop.push_back("-"); // pushOrPop에 - push
					isPop[isPopIndex] = true; // pop된 값의 위치의 값을 true로 바꾸기

				}
			}
			// 현재 입력값이 sequence의 top보다 크고, sequence에서 pop된 값 중 최대값보다 크다면,
			else if (num > sequence.top() && num > maxNumOfPop)
			{
				// maxNumOfPop부터 num만큼 반복
				for (int i = maxNumOfPop + 1; i <= num; i++)
				{
					sequence.push(i);
					pushOrPop.push_back("+"); // pushOrPop에 - push
				}
				// pop
				sequence.pop(); // sequence의 top에 있는 값 pop
				pushOrPop.push_back("-"); // pushOrPop에 - push
				isPop[isPopIndex] = true; // pop된 값의 위치의 값을 true로 바꾸기
			}

			// 입력 값이 팝된 값 중 최대값(maxNumOfPop)보다 크다면,
			if (num > maxNumOfPop)
			{
				// num이 곧 팝된 값 중 최대값(maxNumOfPop)
				maxNumOfPop = num;
			}
		}
	}

	// 모두 pop이 됐다면,
	if (sequence.empty())
	{
		// pushOrPop의 push(+), pop(-) 내역 출력
		for (string i : pushOrPop)
		{
			cout << i << '\n';
		}
	}
}
