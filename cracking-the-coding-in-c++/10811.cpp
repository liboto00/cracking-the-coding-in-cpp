// 백준 온라인 저지 10811번 https://www.acmicpc.net/problem/10811
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<int> vec;
	int N, M;
	int startNumber, endNumber;

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		vec.push_back(i + 1);
	}

	std::vector<int>::iterator itr = vec.begin();
	for (int i = 0; i < M; i++)
	{
		std::cin >> startNumber >> endNumber;
		startNumber -= 1;
		endNumber -= 1;
		
		for (int j = startNumber; j <= endNumber; j++)
		{
			reverse(itr + startNumber, itr + endNumber);
		}
	}

	for (const auto& i : vec)
	{
		std::cout << i << " ";
	}
}