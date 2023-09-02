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

	for (int i = 0; i < n; i++)
	{
		
	}
}
