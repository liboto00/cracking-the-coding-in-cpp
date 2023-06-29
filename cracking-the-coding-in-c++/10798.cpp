// 백준 온라인 저지 10798번 https://www.acmicpc.net/problem/10798
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string array[5][15] = {"-1", };
	std::string inputletters;

	for (int i = 0; i < 5; i++)
	{
		std::cin >> inputletters;

		for (int j = 0; j < inputletters.size(); j++)
		{
			array[i][j] = inputletters[j];
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (array[j][i] == "-1")
			{
				continue;
			}
			else
			{
				std::cout << array[j][i];
			}
		}
	}
}