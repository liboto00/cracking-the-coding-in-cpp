// 백준 온라인 저지 1966번 https://www.acmicpc.net/problem/1966
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCaseNum; // 테스트 케이스의 수
	int N; // 문서의 개수
	int M; // 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서 몇 번째에 놓여있는지를 나타내는 정수
	int importance; // 중요도
	
	cin >> testCaseNum;
	for (int i = 0; i < testCaseNum; i++)
	{
		vector<int> queue;

		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> importance;
			queue.push_back(importance); // 중요도를 배열의 원소로 대입
		}
		
		int cnt = 0;
		bool isPrinted = false;
		// 문서의 개수만큼 반복
		for (int j = 0; j < queue.size(); j++)
		{
			if (isPrinted)
			{
				break;
			}
			cnt++;

			int maxNum = -999;
			for (int k = 0; k < queue.size(); k++)
			{
				if (maxNum < queue[k])
				{
					maxNum = queue[k];
				}
				else if (maxNum == queue[k])
				{
					
				}
			}
			
			for (int k = 0; k < queue.size(); k++)
			{
				if (queue[M] == maxNum)
				{
					cout << cnt << '\n';
					isPrinted = true;
					break;
				}
				else if (queue[k] == maxNum)
				{
					queue[k] = -1; // 현재 최대값을 -1로 변경 (-1로 출력됨을 표시)
					break;
				}
			}
		}
	}
}
