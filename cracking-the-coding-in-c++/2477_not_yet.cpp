// ���� �¶��� ���� 2477�� https://www.acmicpc.net/problem/2477
// ���� �ð� : 1��
// ���� �ð� : ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ������ ����
	int K;
	cin >> K;

	// ���ܹ�
	vector<vector<int>> field(1001, vector<int> (1001, 0));

	// ���� �׵θ� ���ϱ�
	int direction;
	int length;
	int y = 500, x = 500;
	for (size_t i = 1; i <= 6; i++)
	{
		cin >> direction >> length;

		switch (direction)
		{
		case 1:
			// ���� ��ġ���� length���� 1�� ������ ���̸� ǥ��
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				x++;
			}
			break;
		case 2:
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				x--;
			}
			break;
		case 3:
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				y++;
			}
			break;
		case 4:
			for (size_t j = 1; j <= length; j++)
			{
				field[y][x] = 1;
				y--;
			}
			break;
		default:
			break;
		}
	}

	bool isField;
	for (size_t nowY = 0; nowY < 1001; nowY++)
	{
		for (size_t nowX = 0; nowX < 1000; nowX++)
		{
			isField = false;

			// �̹� �湮�� ���� ���� �����ٸ�,
			if (field[nowY][nowX] == 1)
			{
				// 1ĭ �յ� �湮�� ���� ���̶��,
				if (field[nowY][nowX + 1] == 1)
				{
					// 2���� ��� ����
					// 1. Only �׵θ� e.g. 00001111100000...
					// 2. �׵θ� + ���� �� ���� e.g. 00001111000001000...

					for (size_t tempX = nowX; tempX < 1001; tempX++)
					{
						// 0�� ������, Ż��
						if (field[nowY][tempX] == 0)
						{
							nowX = tempX;

							break;
						}
					}

					// �ٽ� 1�� ������ 2���� ����̰�, �ƴϸ� 1���� ���
					for (size_t tempX = nowX; tempX < 1001; tempX++)
					{
						// �ٽ� 1�� ������,
						if (field[nowY][tempX] == 1)
						{
							// ���� �� �����̹Ƿ� isField�� ���̴�.
							isField = true;
							break;
						}
					}

					// 2���� ��� : ���� �� ����������, ���� �湮���� �ʾҴٸ�,
					if (isField)
					{
						// ���� �����̹Ƿ� 1�� �湮 ǥ��
						for (size_t tempX = nowX; field[nowY][tempX] != 1; tempX++)
						{
							field[nowY][tempX] = 1;

// Error �߻�
							nowX = tempX;
						}
					}
				}
				// �ƴ϶��,
				else
				{
					// ���� �����̹Ƿ� 1�� �湮 ǥ��
					for (size_t tempX = nowX + 1; field[nowY][tempX] != 1; tempX++)
					{
						field[nowY][tempX] = 1;

						nowX = tempX;
					}
				}
			}
		}
	}
	
	// 1�� �� 1m^2�� ��Ÿ������ 1�� ������ ���ϱ�
	int sizeOfField = 0;
	for (size_t nowY = 0; nowY < 1001; nowY++)
	{
		for (size_t nowX = 0; nowX < 1001; nowX++)
		{
			if (field[nowY][nowX] == 1)
			{
				sizeOfField++;
			}
		}
	}
	
	// ���� ũ��� ������ ������ �� ���
	cout << sizeOfField * K;
}