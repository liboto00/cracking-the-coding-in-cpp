// ���� �¶��� ���� 2615�� https://www.acmicpc.net/problem/2615
// ���� �ð� : 1��
// ���� �ð� : ms

// �ݷ� : https://www.acmicpc.net/board/view/83649

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int board[20][20] = { 0, };
	for (size_t y = 1; y <= 19; y++)
	{
		for (size_t x = 1; x <= 19; x++)
		{
			cin >> board[y][x]; 
		}
	}

	// �浹, �鵹 ���ӵ� ���� �Ǵ�
	// 
	// ������ : ���� 1�� Ŀ���� ���
	// ������ : �ุ 1�� Ŀ���� ���
	// �밢���� : ��, ���� ���ÿ� 1�� Ŀ���� ���

	int cntBlack = 0;
	int cntWhite = 0;
	int maxNumOfBlack = 0;
	int maxNumOfWhite = 0;
	pair<int, int> positionOfBlack;
	pair<int, int> positionOfWhite;
	for (int y = 1; y <= 18; y++)
	{
		for (int x = 1; x <= 18; x++)
		{
			// �浹�� ������,
			if (board[y][x] == 1)
			{
				cntBlack = 1;

				// �����ٿ� �ִ� �浹�� ���� �Ǵ�
				for (int nowX = x + 1; nowX <= 19; nowX++)
				{
					if (board[y][nowX] == 1)
					{
						cntBlack++;
					}
					else
					{
						break;
					}
				}
				// ���� ��ġ�� �����ٿ� �ִ� �浹�� ������ ���ӵ� �浹�� �� �ִ밪 ���� ũ��, 6 �̸��̶��,
				if (maxNumOfBlack < cntBlack && cntBlack < 6)
				{
					// ���� ��ġ�� �����ٿ� �ִ� �浹�� ������ �ִ밪
					maxNumOfBlack = cntBlack;

					// �� ���ʿ� �ִ� �浹�� ��ġ
					positionOfBlack.first = y;
					positionOfBlack.second = x;
				}
				cntBlack = 1;

				// �����ٿ� �ִ� �浹�� ���� �Ǵ�
				for (int nowY = y + 1; nowY <= 19; nowY++)
				{
					if (board[nowY][x] == 1)
					{
						cntBlack++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfBlack < cntBlack && cntBlack < 6)
				{
					maxNumOfBlack = cntBlack;

					// �� ���ʿ� �ִ� �浹�� ��ġ
					positionOfBlack.first = y;
					positionOfBlack.second = x;
				}
				cntBlack = 1;

				// �밢���ٿ� �ִ� �浹�� ���� �Ǵ�
				for (int i = 1; (y + i <= 19) && (x + i <= 19); i++)
				{
					if (board[y + i][x + i] == 1)
					{
						cntBlack++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfBlack < cntBlack && cntBlack < 6)
				{
					maxNumOfBlack = cntBlack;

					// �� ���� ���� �ִ� �浹�� ��ġ
					positionOfBlack.first = y;
					positionOfBlack.second = x;
				}
				cntBlack = 1;
			} 
			// �鵹�� ������,
			else if (board[y][x] == 2)
			{
				cntWhite = 1;

				// �����ٿ� �ִ� �鵹�� ���� �Ǵ�
				for (int nowX = x + 1; nowX <= 19; nowX++)
				{
					if (board[y][nowX] == 2)
					{
						cntWhite++;
					}
					else
					{
						break;
					}
				}
				// ���� ��ġ�� �����ٿ� �ִ� �鵹�� ������ ���ӵ� �鵹�� �� �ִ밪 ���� ũ��, 6 �̸��̶��,
				if (maxNumOfWhite < cntWhite && cntWhite < 6)
				{
					// ���� ��ġ�� �����ٿ� �ִ� �鵹�� ������ �ִ밪
					maxNumOfWhite = cntWhite;

					// �� ���ʿ� �ִ� �鵹�� ��ġ
					positionOfWhite.first = y;
					positionOfWhite.second = x;
				}
				cntWhite = 1;

				// �����ٿ� �ִ� �鵹�� ���� �Ǵ�
				for (int nowY = y + 1; nowY <= 19; nowY++)
				{
					if (board[nowY][x] == 2)
					{
						cntWhite++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfWhite < cntWhite && cntWhite < 6)
				{
					maxNumOfWhite = cntWhite;

					// �� ���ʿ� �ִ� �鵹�� ��ġ
					positionOfWhite.first = y;
					positionOfWhite.second = x;
				}
				cntWhite = 1;

				// �밢���ٿ� �ִ� �鵹�� ���� �Ǵ�
				for (int i = 1; (y + i <= 19) && (x + i <= 19); i++)
				{
					if (board[y + i][x + i] == 2)
					{
						cntWhite++;
					}
					else
					{
						break;
					}
				}
				if (maxNumOfWhite < cntWhite && cntWhite < 6)
				{
					maxNumOfWhite = cntWhite;

					// �� ���� ���� �ִ� �鵹�� ��ġ
					positionOfWhite.first = y;
					positionOfWhite.second = x;
				}
				cntWhite = 1;
			}
		}
	}

	if (maxNumOfWhite < maxNumOfBlack)
	{
		cout << 1 << '\n';
		cout << positionOfBlack.first << ' ' << positionOfBlack.second;
	}
	else if (maxNumOfWhite > maxNumOfBlack)
	{
		cout << 2 << '\n';
		cout << positionOfWhite.first << ' ' << positionOfWhite.second;
	}
	else
	{
		cout << 0 << '\n';
	}
}