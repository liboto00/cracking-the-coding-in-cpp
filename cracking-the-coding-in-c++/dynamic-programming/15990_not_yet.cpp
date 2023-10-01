// 백준 온라인 저지 15990번 https://www.acmicpc.net/problem/15990
// 제한 시간 : 1초 (추가 시간 없음)
// 실행 시간 : ms

// 1, 2, 3의 합으로 n(1 ≤ n ≤ 100,000)을 나타내는 방법의 수를 1,000,000,009로 나눈 나머지 구하기
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 테스트 케이스의 수
	int T;
	cin >> T;

	int n;// (1 ≤ n ≤ 100,000)

	int using1 = 0;
	int using2 = 0;
	int using3 = 0;
	int sum = 0;

	// 테스트 케이스의 수만큼 반복
	for (size_t i = 0; i < T; i++)
	{
		// 정수 n 입력
		cin >> n;

		if (n == 1)
		{
			cout << 1 << '\n';
		}
		else if (n == 2)
		{
			cout << 2 << '\n';
		}

		// n을 구하는 방법이 더 없을 때까지 반복
		while (true)
		{
		// 1을 먼저 사용한 경우
			// 1을 제외한 2, 3 사용
			
		// 2를 먼저 사용한 경우
			// 2를 제외한 1, 3 사용
			
		// 3을 먼저 사용한 경우
			// 3을 제외한 1, 2 사용
						
		}
	}
}