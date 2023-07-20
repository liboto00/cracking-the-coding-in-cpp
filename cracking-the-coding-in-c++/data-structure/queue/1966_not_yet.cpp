// 백준 온라인 저지 1966번 https://www.acmicpc.net/problem/1966
// 제한 시간 : 2초
// 실행 시간 : ms

// 핵심 : 1. 중요도가 같은 경우도 고려해야 한다 2. queue에 몇 번째에 놓인 특정 정수를 기억해야 한다.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case_num; // 테스트 케이스의 수
	int N; // 문서의 개수
	int M; // 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에 몇 번째에 놓였는지를 나타내는 정수

	cin >> test_case_num;
	// 테스트 케이스 수만큼 반복
	for (int i = 0; i < test_case_num; i++)
	{
		vector<int> queue_importance; // 각 문서의 중요도를 담는 동적 배열

		cin >> N >> M;

		vector<int> find_M(N, -1); // M을 추적하는 배열, 모든 값에 -1 대입 ∵ M과 구분하기 위해서
		find_M[M] = 1; // M의 자리에 1 대입

		int importance; // 중요도
		int max_importance = 0; // 중요도 중 가장 큰 수 (중요도는 1~100이므로 이와 관계 없는 숫자로 초기화)
		// 문서의 개수만큼 반복
		for (int i = 0; i < N; i++)
		{
			cin >> importance; // 중요도 입력
			queue_importance.push_back(importance);// 각 중요도를 배열에 대입

			// 현재 max_importance보다 크거나 같은 importance가 있다면,
			if (importance >= max_importance)
			{
				// 그 importance가 곧 max_importance
				max_importance = importance;
			}
		}
		
		// M(몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에 몇 번째에 놓였는지)에 있는 수가 프린트에 출력될 때까지 반복
		while (true)
		{
			int printed_order = 0; // 프린트된 순서
			int temp; // 임시로 배열의 원소의 값을 저장할 변수
			vector<int>::iterator itr = queue_importance.begin();

			// 배열의 첫 번째 원소의 값이 max_importance이면,
			if (*itr == max_importance)
			{
				printed_order++; // 프린트된 순서 증가
				queue_importance.erase(itr); // 프린트된 값 제거
			}
			// 배열의 첫 번째 원소의 값이 max_importance보다 작으면,
			else if (*itr < max_importance)
			{
				// *itr;
			}
		}
	}
}
