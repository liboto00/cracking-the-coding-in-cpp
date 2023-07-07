// 백준 온라인 저지 4949번 https://www.acmicpc.net/problem/4949
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string sentence;

	vector<string> parenthesesOrBrackets;
	int countParentheses = 0; // ()
	int countBrackets = 0; // []

	getline(cin, sentence);
	while (!(sentence[0] == '.' && sentence[1] == '\0'))
	{
		for (int i = 0; i < sentence.size(); i++)
		{
			if (sentence[i] == '(')
			{
				countParentheses++;
				parenthesesOrBrackets.push_back("(");
			}
			else if (sentence[i] == ')')
			{
				countParentheses--;
				if (*(parenthesesOrBrackets.end() - 1) == "[" || countParentheses < 0)
				{
					cout << "no\n";
					break;
				}
				parenthesesOrBrackets.erase(parenthesesOrBrackets.end() - 1);
			}

			if (sentence[i] == '[')
			{
				countBrackets++;
				parenthesesOrBrackets.push_back("[");
			}
			else if (sentence[i] == ']')
			{
				countBrackets--;
				if (*(parenthesesOrBrackets.end() - 1) == "(" || countBrackets < 0)
				{
					cout << "no\n";
					break;
				}
				parenthesesOrBrackets.erase(parenthesesOrBrackets.end() - 1);
			}
		}

		if (countParentheses == 0 && countBrackets == 0)
		{
			cout << "yes\n";
		}

		countParentheses = 0;
		countBrackets = 0;
		parenthesesOrBrackets.clear();

		getline(cin, sentence);
	}
}