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
	int visited_vertical[20][20] = { 0, };
	int visited_horizontal[20][20] = { 0, };
	int visited_slash[20][20] = { 0, };
	int visited_back_slash[20][20] = { 0, };
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
			// ��� �ϳ��� �ٿ� �湮���� �ʾҰ�, �浹�̸�,
			if ((visited_vertical[y][x] == 0 
				|| visited_horizontal[y][x]== 0 
				|| visited_slash[y][x] == 0
				|| visited_back_slash[y][x] == 0)	&& board[y][x] == 1)
			{
				cntBlack = 1;
				visited_vertical[y][x] = 1;
				visited_horizontal[y][x] = 1;
				visited_slash[y][x] = 1;
				visited_back_slash[y][x] = 1;

				// �����ٿ� �ִ� �浹�� ���� �Ǵ�
				for (int nowX = x + 1; nowX <= 19; nowX++)
				{
					// ���� �湮���� �ʾҰ�, �浹�̸�,
					if (visited_horizontal[y][nowX] == 0 && board[y][nowX] == 1)
					{
						// �湮 ó��
						visited_horizontal[y][nowX] = 1;

						// �浹 ���� ī��Ʈ
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
					// ���� �湮���� �ʾҰ�, �浹�̸�,
					if (visited_vertical[nowY][x] == 0 && board[nowY][x] == 1)
					{
						// �湮 ó��
						visited_vertical[nowY][x] = 1;

						// �浹 ���� ī��Ʈ
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

				// ������ ���� �밢���ٿ� �ִ� �浹�� ���� �Ǵ�
				for (int i = 1; (y + i <= 19) && (x + i <= 19); i++)
				{
					// ���� �湮���� �ʾҰ�, �浹�̸�,
					if (visited_slash[y + i][x + i] == 0 && board[y + i][x + i] == 1)
					{
						// �湮 ó��
						visited_slash[y + i][x + i] = 1;

						// �浹 ���� ī��Ʈ
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

				// �� ������ ���� �밢���ٿ� �ִ� �浹�� ���� �Ǵ�
				int i;
				for (i = 1; (y + i <= 19) && (x - i >= 0); i++)
				{
					// ���� �湮���� �ʾҰ�, �浹�̸�,
					if (visited_back_slash[y + i][x - i] == 0 && board[y + i][x - i] == 1)
					{
						// �湮 ó��
						visited_back_slash[y + i][x - i] = 1;

						// �浹 ���� ī��Ʈ
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
					positionOfBlack.first = y + (i - 1);
					positionOfBlack.second = x - (i - 1);
				}
				cntBlack = 1;
			} 
			// ��� �ϳ��� �ٿ� �湮���� �ʾҰ�, �鵹�̸�,
			else if ((visited_vertical[y][x] == 0
				|| visited_horizontal[y][x] == 0
				|| visited_slash[y][x] == 0
				|| visited_back_slash[y][x] == 0) && board[y][x] == 2)
			{
				cntWhite = 1;
				visited_vertical[y][x] = 1;
				visited_horizontal[y][x] = 1;
				visited_slash[y][x] = 1;
				visited_back_slash[y][x] = 1;

				// �����ٿ� �ִ� �鵹�� ���� �Ǵ�
				for (int nowX = x + 1; nowX <= 19; nowX++)
				{
					// ���� �湮���� �ʾҰ�, �鵹�̸�,
					if (visited_horizontal[y][nowX] == 0 && board[y][nowX] == 2)
					{
						// �湮 ó��
						visited_horizontal[y][nowX] = 1;

						// �鵹 ���� ī��Ʈ
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
					// ���� �湮���� �ʾҰ�, �鵹�̸�,
					if (visited_vertical[nowY][x] == 0 && board[nowY][x] == 2)
					{
						// �湮 ó��
						visited_vertical[nowY][x] = 1;

						// �鵹 ���� ī��Ʈ
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

				// ������ ���� �밢���ٿ� �ִ� �鵹�� ���� �Ǵ�
				for (int i = 1; (y + i <= 19) && (x + i <= 19); i++)
				{
					// ���� �湮���� �ʾҰ�, �鵹�̸�,
					if (visited_slash[y + i][x + i] == 0 && board[y + i][x + i] == 2)
					{
						// �湮 ó��
						visited_slash[y + i][x + i] = 1;

						// �鵹 ���� ī��Ʈ
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

				int i;
				// �� ������ ���� �밢���ٿ� �ִ� �鵹�� ���� �Ǵ�
				for (i = 1; (y + i <= 19) && (x - i >= 0); i++)
				{
					// ���� �湮���� �ʾҰ�, �鵹�̸�,
					if (visited_back_slash[y + i][x - i] == 0 && board[y + i][x - i] == 2)
					{
						// �湮 ó��
						visited_back_slash[y + i][x - i] = 1;

						// �鵹 ���� ī��Ʈ
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
					positionOfWhite.first = y + (i - 1);
					positionOfWhite.second = x - (i - 1);
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
		cout << 0;
	}
}