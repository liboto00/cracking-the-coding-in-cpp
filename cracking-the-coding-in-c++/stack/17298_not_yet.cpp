// 백준 온라인 저지 17298번 https://www.acmicpc.net/problem/17298
// 제한 시간 : 1초
// 실행 시간 : ms

// 오큰수 NGE(i) : Ai보다 오른쪽에 있으면서 큰 수 중에서 가장 왼쪽에 있는 수, 그러한 수가 없는 경우 오큰수는 -1
// e.g. A = [3, 5, 2, 7], NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1
//		A = [9, 5, 4, 8], NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1

// 핵심 : N (1 ≤ N ≤ 1,000,000)이기 때문에 2중 반복문 이상이면 시간 초과가 되는 점을 유의해야 한다.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> sequence; // 수열을 담을 동적배열
	stack<int> stack;
	
	cin >> N; // 수열의 크기 N 입력
	int num; // 수열의 각 값을 담을 변수
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		sequence.push_back(num); // 동적배열에 수열의 각 값 넣기
	}

	for (int i = 0; i < N; i++)
	{
		while (true)
		{
			// Ai와 그 오른쪽의 값을 순차적으로 비교 -> 큰 수를 처음 찾으면 그 수를 출력 후 i값 1 증가
			if (sequence[i] < sequence[i])
			{

			}
		}
	}
}
