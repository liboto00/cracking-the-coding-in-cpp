#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> triangle(n, vector<int>(n, -1));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < y + 1; x++)
		{
			cin >> triangle[y][x];
		}
	}

	// Brute force

}