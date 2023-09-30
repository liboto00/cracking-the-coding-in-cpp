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

	vector<int> using1(2, 0);
	vector<int> using2(2, 0);
	vector<int> using3(2, 0);
	vector<int> using4(2, 0);
	vector<int> using5(2, 0);
	vector<int> using6(2, 0);
	vector<int> using7(2, 0);
	vector<int> using8(2, 0);
	vector<int> using9(2, 0);

	// 테스트 케이스의 수만큼 반복
	for (size_t i = 0; i < T; i++)
	{
		// 정수 n 입력
		cin >> n;

		
	}
}