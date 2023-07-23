// 백준 온라인 저지 1181번 https://www.acmicpc.net/problem/1181
// 제한 시간 : 2초
// 실행 시간 : ms

// 핵심 : 길이가 짧은 순, 길이가 같으면 사전 순, 중복 제거

// 문제점 1 : 길이가 짧은 순으로 정렬하는 ShortOrderSort()는 O(n^2)에 가까워 정렬 방식을 바꿔야 한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string word;
	vector<string> words;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		words.push_back(word);
	}

	// 길이가 짧은 순으로 정렬
	string temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (words[i].size() > words[j].size())
			{
				temp = words[i];
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}

	// 중복 제거
	words.erase(unique(words.begin(), words.end()), words.end());

	// 길이가 짧은 순으로 저장된 배열의 인덱스 위치와 같은 위치에 길이의 값이 있는 배열 생성
	vector<int> LexicographicOrder;
	for (string i : words)
	{
		LexicographicOrder.push_back(i.size());
	}

	// 길이가 같으면, 사전 순으로 정렬
	int cnt;
	string str;
	for (int i = 0; i < words.size(); i++)
	{
		if ()
		{

		}
	}

	// 조건에 맞게 정렬된 배열의 원소들 출력
	for (string i : words)
	{
		cout << i << "\n";
	}
}
