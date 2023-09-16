// 백준 온라인 저지 14235번 https://www.acmicpc.net/problem/14235
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; // 거점지 방문 횟수(1 ≤ n ≤ 5,000)
    int a; // 충전할 선물 개수(1 ≤ a ≤ 100)

	int gift; // 선물들의 가치(0 ≤ gift < 100,000)
	vector<int> gifts; // 선물들의 가치를 담는 배열, 최대 크기 n(5,000) * a(100)

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (!a)
		{
			if (gifts.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				// 끝에 있는 가장 큰 수 출력
				cout << *(gifts.end() - 1) << '\n';

				// 끝에 있는 가장 큰 수 제거
				gifts.pop_back();
			}
		}
		else
		{
			for (int j = 0; j < a; j++)
			{
				// 선물들의 가치 입력
				cin >> gift;

				// gifts에 대입
				gifts.push_back(gift);
			}

			// gifts를 오름차순으로 정렬
				sort(gifts.begin(), gifts.end());
		}
	}
}
