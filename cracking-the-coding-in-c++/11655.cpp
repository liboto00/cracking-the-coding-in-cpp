// ���� �¶��� ���� 11655�� https://www.acmicpc.net/problem/11655
// ���� �ð� : 1��
// ���� �ð� : 0ms

#include <iostream>
#include <string>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	std::string inputLetters;
	
	getline(cin, inputLetters);
	for (int i = 0; i < inputLetters.size(); i++)
	{
		if (inputLetters[i] >= 'A' && inputLetters[i] <= 'Z')
		{
			if (inputLetters[i] <= 'M')
			{
				inputLetters[i] += 13;
			}
			else
			{
				inputLetters[i] -= 13;

			}
		}
		else if (inputLetters[i] >= 'a' && inputLetters[i] <= 'z')
		{
			if (inputLetters[i] <= 'm')
			{
				inputLetters[i] += 13;
			}
			else
			{
				inputLetters[i] -= 13;

			}
		}
	}
	cout << inputLetters;
}