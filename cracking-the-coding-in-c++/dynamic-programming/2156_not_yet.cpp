// 백준 온라인 저지 2156번 https://www.acmicpc.net/problem/2156
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

	int n;
	cin >> n;

	vector<int> theNumOfWine(n);
	for (int i = 0; i < n; i++)
	{
		cin >> theNumOfWine[i];
	}

	// 마지막 와인을 마실 수 있는 경우와 없는 경우
	vector<int> wine00(2, 0); // o
	vector<int> wine01(2, 0); // o
	vector<int> wine10(2, 0); // o
	vector<int> wine11(2, 0); // x

	int maxOfWine;
	for (int i = 0; i < n; i++)
	{
		wine01[1] = theNumOfWine[i - 1];
		wine10[0] = theNumOfWine[i - 2];
		wine11[0] = theNumOfWine[i - 2];
		wine11[1] = theNumOfWine[i - 1];

		maxOfWine = max(wine00[0] + wine00[1] + theNumOfWine[i],
						wine01[0] + wine01[1] + theNumOfWine[i], 
						wine10[0] + wine10[1] + theNumOfWine[i]);
		maxOfWine = max(maxOfWine, wine11[0] + wine11[1]);
	}

	cout << maxOfWine;
}
