// ���� �¶��� ���� 18111�� https://www.acmicpc.net/problem/18111
// ���� �ð� : 1�� (�߰� �ð� ����)
// ���� �ð� : 516ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// (1 �� M, N �� 500, 0 �� B �� 6.4 �� 107)
	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> ground(N, vector<int>(M));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> ground[y][x];
		}
	}

	// ����� �װų�, �����ϴ� �ð�
	vector<int> timeLoadedOrDeletedBlock(257, 0);

	// ���忡 �κ��丮�� ����� ���� ����� ���� ���� ���� �ε��� ��ġ
	typedef pair<int, int> p;

	for (size_t hToMake = 0; hToMake <= 256; hToMake++)
	{
		int nowB = B;
		vector<p> cannotBuiltPosition;

		for (size_t y = 0; y < N; y++)
		{
			for (size_t x = 0; x < M; x++)
			{
				// ���� ���� ���̰� ������� ���̺��� ������,
				if (ground[y][x] > hToMake)
				{
					// �� ���� ���� �ð� 2�� �߰�
					timeLoadedOrDeletedBlock[hToMake] += (ground[y][x] - hToMake) * 2;
					// ������ ��ϸ�ŭ �κ��丮�� ��� ����
					nowB += (ground[y][x] - hToMake);
				}
				// ���� ���� ���̰� ������� ���̺��� ������,
				else if (ground[y][x] < hToMake)
				{
					// ���� �κ��丮�� �ִ� ����� ������ �׾ƾ� �ϴ� ����� �������� ������,
					if (nowB >= (hToMake - ground[y][x]))
					{
						// �� ���� �״� �ð� 1�� �߰�
						timeLoadedOrDeletedBlock[hToMake] += (hToMake - ground[y][x]) * 1;
						// ���� ��ϸ�ŭ �κ��丮���� ����
						nowB -= (hToMake - ground[y][x]);
					}
					// ���� �κ��丮�� �ִ� ����� ������ �׾ƾ� �ϴ� ����� �������� ������,
					else
					{
						// �κ��丮�� ����� ���� ����� ���� ���� ���� �ε��� ����
						cannotBuiltPosition.push_back(make_pair(y, x));
					}
				}
			}
		}

		// ��� ���� ��ȸ�� ��, �κ��丮�� ��� ����� ������ ����� ���� ���� ���� �׾ƾ� �ϴ� ����� ������ ��
		int tempY, tempX;
		for (size_t i = 0; i < cannotBuiltPosition.size(); i++)
		{
			tempY = cannotBuiltPosition[i].first;
			tempX = cannotBuiltPosition[i].second;
			
			// ���� �κ��丮�� �ִ� ����� ������ �׾ƾ� �ϴ� ����� �������� ������,
			if (0 < nowB && (hToMake - ground[tempY][tempX]) <= nowB)
			{
				// �� ���� �״� �ð� 1�� �߰�
				timeLoadedOrDeletedBlock[hToMake] += (hToMake - ground[tempY][tempX]) * 1;
				// ���� ��ϸ�ŭ �κ��丮���� ����
				nowB -= (hToMake - ground[tempY][tempX]);
			}
			// ��� ���� ��ȸ�� ���� �κ��丮�� ��� ������ �����ϴٸ�,
			else
			{
				// �ش� hToMake�� ���̸� ���� �� �����Ƿ� ���̸� ���ߴ� ���� �������� ���� -1�� �� ����
				timeLoadedOrDeletedBlock[hToMake] = -1;
				break;
			}
		}
	}

	int minTime = timeLoadedOrDeletedBlock[0];
	int maxHOfMinTime;
	for (int i = 0; i <= 256; i++)
	{
		if (0 <= timeLoadedOrDeletedBlock[i] && timeLoadedOrDeletedBlock[i] <= minTime)
		{
			minTime = timeLoadedOrDeletedBlock[i];
			maxHOfMinTime = i;
		}
	}

	cout << timeLoadedOrDeletedBlock[maxHOfMinTime] << ' ' << maxHOfMinTime;
}