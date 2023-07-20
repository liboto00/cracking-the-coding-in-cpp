// 백준 온라인 저지 1158번 https://www.acmicpc.net/problem/1158
// 제한 시간 : 2초
// 실행 시간 : ms

// 핵심 : 시작과 끝이 연결되어있다.

// 문제점 1 : iterator를 이용해 배열의 원소를 erase한 후, *iterator를 사용하면 Error가 발생 
// 해결 1 :  반복 시마다 itr_begin = queue.begin();으로 iterator가 가리키는 주소를 명확히 함으로써 문제를 해결했다.

// 문제점 2 : 시간 초과

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 사람 수
	int K; // 제거할 사람이 앉은 곳의 순서
	vector<int> queue;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		queue.push_back(i + 1); // 각 사람에게 1번부터 N번까지 번호 부여
	}

	bool isAnybody = true;
	int countOrder = 0; // K 순서의 사람을 제거하기 위해 몇 번째 사람인지 카운트
	int countEliminatedPeople = 0; // 제거된 사람 수 카운트
	// int temp; // queue의 원소를 임시 저장할 변수
	vector<int>::iterator itr_begin = queue.begin();

	cout << "<";
	// 사람이 모두 제거될 때까지(값이 모두 -1일 때까지) 반복
	while (isAnybody)
	{
		// K 번째의 사람이고, 이미 제거된 사람이 아니라면,
		if ((countOrder + 1) == K && *itr_begin != -1)
		{
			cout << *itr_begin << ", "; // K 번째 사람의 순번 출력

			queue.push_back(-1); // K 번째 사람의 순번 제거 후(-1로 값 변경 후), queue의 맨 뒤로 이동
			queue.erase(itr_begin); // queue의 맨 앞에 남아있는 순번의 값은 제거

			countEliminatedPeople++; // 제거된 사람 수 1 증가
			countOrder = 0; // K 순번의 사람을 처음부터 다시 찾기 위해 countOrder 초기화
		}
		// K 번째의 사람이 아니고, 이미 제거된 사람이 아니라면,
		else if ((countOrder + 1) != K && *itr_begin != -1)
		{
			queue.push_back(*itr_begin); // queue의 맨 뒤로 이동
			queue.erase(itr_begin); // queue의 맨 앞에 남아있는 이동된 값 제거

			countOrder++; // countOrder 1 증가
		}
		// 이미 제거된 사람이라면,
		else if (*itr_begin == -1)
		{
			queue.push_back(*itr_begin); // queue의 맨 뒤로 이동
			queue.erase(itr_begin); // queue의 맨 앞에 남아있는 이동된 값 제거
		}
		itr_begin = queue.begin(); // iterator가 가리키는 주소를 다시 원소의 첫 번째로 지정

		// 제거된 사람의 수가 모든 사람의 수보다 1명 적다면,
		if (countEliminatedPeople == (N - 1))
		{
			// 모든 사람 중
			for (; itr_begin != queue.end(); itr_begin++)
			{
				// 제거되지 않은 사람의 순번을 찾으면,
				if (*itr_begin != -1)
				{
					// 출력
					cout << *itr_begin;
					break;
				}
			}

			// 모든 사람의 순번이 제거되었으므로, 반복문 종료
			isAnybody = false;
			continue;
		}
	}
	cout << ">";
}
