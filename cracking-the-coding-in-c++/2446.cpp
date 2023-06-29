// 백준 온라인 저지 2446번 https://www.acmicpc.net/problem/2446
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<int> array = {};

	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << ' ';
		}

		for (int k = 0; k < (2 * N) - (2 * i + 1); k++)
		{
			std::cout << '*';
		}

		std::cout << "\n";
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N - 2; j++)
		{
			std::cout << ' ';
		}

		for (int k = 0; k < 3 + (2 * i); k++)
		{
			std::cout << '*';
		}

		std::cout << "\n";
	}
}
