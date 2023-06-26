// 백준 온라인 저지 2446번

#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int rowNumber;

	std::cin >> rowNumber;

	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << " ";
		}

		for (int k = 0; k < (2 * rowNumber) - (2 * i + 1); k++)
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}

	for (int i = 0; i < rowNumber - 1; i++)
	{
		for (int j = i; j < rowNumber - 2; j++)
		{
			std::cout << " ";
		}

		for (int k = 0; k < 3 + (2 * i); k++)
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}
}
