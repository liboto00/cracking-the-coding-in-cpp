// 백준 온라인 저지 1158번 https://www.acmicpc.net/problem/1158
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

	int N, K;
	vector<int> vec;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		vec.push_back(i + 1);
	}

	cout << '<';
	while (vec.begin() != vec.end())
	{
		if (vec.size() == 1)
		{
			break;
		}
		cout << *(vec.begin() + 2) << ", ";
	}
	cout << *vec.begin();
	cout << '>';

}