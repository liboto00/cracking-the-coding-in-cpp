// ���� �¶��� ���� 9996�� https://www.acmicpc.net/problem/9996
// ���� �ð� : 1��
// ���� �ð� : 0ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<string> words(N);

	string pattern;
	cin >> pattern;

	string patternBeforeAsterisk;
	for (int i = 0; i < pattern.find('*'); i++)
	{
		patternBeforeAsterisk.push_back(pattern[i]);
	}

	string patternAfterAsterisk;
	for (int i = pattern.find('*') + 1; i < pattern.size(); i++)
	{
		patternAfterAsterisk.push_back(pattern[i]);
	}

	string fWord;
	string bWord;
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];

		if (words[i].size() < patternBeforeAsterisk.size() + patternAfterAsterisk.size())
		{
			cout << "NE" << '\n';
			continue;
		}

		fWord = words[i].substr(0, patternBeforeAsterisk.size());
		bWord = words[i].substr(words[i].size() - patternAfterAsterisk.size());

		// pattern �� * ���� ���� pattern�� ���� ���� �������� ������,
		if (fWord.find(patternBeforeAsterisk) == string::npos)
		{
			cout << "NE" << '\n';
		}
		// �����ϸ�,
		else
		{
			// pattern �� * �Ŀ� ���� pattern�� ���� ���� �������� ������,
			if (bWord.find(patternAfterAsterisk) == string::npos)
			{
				cout << "NE" << '\n';
			}
			// �����ϸ�,
			else
			{
				cout << "DA" << '\n';
			}
		}
	}
}