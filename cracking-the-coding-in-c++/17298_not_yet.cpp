// 백준 온라인 저지 17298번 https://www.acmicpc.net/problem/17298
// 제한 시간 : 1초
// 실행 시간 : ms

// 수열: A = A1, A2, ..., AN
// 1. Ai보다 큰 수가 오른쪽에 존재하는지 여부
// 2 - 1. Yes : 큰 수 중 가장 왼쪽에 있는 수 출력
// 2 - 2. No : -1

// 문제점 : 최대 1,000,000 크기의 수열에 최대 1,000,000이라는 숫자를 가지는 원소들이 존재한다.
// A1의 수보다 큰 수를 찾는다고 가정했을 때, 최악의 경우 1,000,000번 반복해야 한다.
// 이때, An의 n이 1,000,000이면, 큰 수를 찾는 과정 1,000,000번을 1,000,000번 가까이 해야할 수도 있다.
// 즉, 시간 초과가 된다.

// vector의 find_if 사용 결과 : 시간 복잡도가 O(n)이기 때문에 for loop과 사용했을 때, 시간 복잡도가 O(n^2)이 되므로 사용하면 시간 초과가 된다.
// stack 사용 결과 : 

#include <iostream>
#include <vector>
using namespace std;

int a_i;
bool isNGE(int num)
{
	return num > a_i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 수열의 크기
	
	cin >> N;
	vector<int> A(N); // 수열이 저장될 동적배열 (불필요한 메모리 증설이 반복되지 않게, 입력 받은 N만큼 크기 설정)
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
	}
	
}