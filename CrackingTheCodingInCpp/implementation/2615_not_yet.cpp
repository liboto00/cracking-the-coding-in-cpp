// ���� �¶��� ���� 2615�� https://www.acmicpc.net/problem/2615
// ���� �ð� : 1��
// ���� �ð� : ms

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

void FindOmok(vector<vector<int>>& board)
{
	typedef pair<int, int> p;

	// ���� �ٵϵ�
	int prev_baduk_stone = 0;
	// �浹 ī��Ʈ = {�ٵϵ� �� �Ǵ�, ���ӵ� �浹 ī��Ʈ}
	p cnt_baduk_stone_1 = { 1, 1 };
	// �鵹 ī��Ʈ = {�ٵϵ� �� �Ǵ�, ���ӵ� �鵹 ī��Ʈ}
	p cnt_baduk_stone_2 = { 2, 1 };

	// ���� ���� ���� �Ǵ�
	for (size_t y = 1; y < 20; y++)
	{
		for (size_t x = 1; x < 20; x++)
		{
			// ���� Ž���� ���� �浹�̰�,
			if (board[y][x] == 1)
			{
				// ���� Ž���� ���� �浹�̶��,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// ���� Ž���� ���� �鵹�̶��,
				else if (prev_baduk_stone == 2)
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// ���� Ž���� ���� �鵹�̰�,
			else if (board[y][x] == 2)
			{
				// ���� Ž���� ���� �鵹�̶��,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// ���� Ž���� ���� �浹�̶��,
				else if (prev_baduk_stone == 1)
				{
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}
			}
			// ���� Ž���� ���� ���ٸ�,
			else
			{
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// ���� Ž���� ���� ������ ���� �ִٸ�,
			if (x == 19)
			{
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << x - 4;

					return;
				}
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << x - 4;

					return;
				}
			}
		}

		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// ���� ���� ���� �Ǵ�
	prev_baduk_stone = 0;
	for (size_t x = 1; x < 20; x++)
	{
		for (size_t y = 1; y < 20; y++)
		{
			// ���� Ž���� ���� �浹�̰�,
			if (board[y][x] == 1)
			{
				// ���� Ž���� ���� �浹�̶��,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// ���� Ž���� ���� �鵹�̶��,
				else if (prev_baduk_stone == 2)
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// ���� Ž���� ���� �鵹�̰�,
			else if (board[y][x] == 2)
			{
				// ���� Ž���� ���� �鵹�̶��,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// ���� Ž���� ���� �浹�̶��,
				else if (prev_baduk_stone == 1)
				{
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}
			}
			// ���� Ž���� ���� ���ٸ�,
			else
			{
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// ���� Ž���� ���� ������ ���� �ִٸ�,
			if (y == 19)
			{
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 4 << ' ' << x;

					return;
				}
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 4 << ' ' << x;

					return;
				}
			}
		}

		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// �밢�� �� ���� ���� �Ǵ�
	prev_baduk_stone = 0;
	for (size_t x = 1; x < 20; x++)
	{
		size_t nowX = x;
		size_t y = 1;

		// �ٵϵ��� �ٵ��� ���� �ȿ� �����ϸ�,
		while ((1 <= y && y <= 19) && (1 <= nowX && nowX <= 19))
		{
			// ���� Ž���� ���� �浹�̰�,
			if (board[y][nowX] == 1)
			{
				// ���� Ž���� ���� �浹�̶��,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// ���� Ž���� ���� �鵹�̶��,
				else if (prev_baduk_stone == 2)
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// ���� Ž���� ���� �鵹�̰�,
			else if (board[y][nowX] == 2)
			{
				// ���� Ž���� ���� �鵹�̶��,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// ���� Ž���� ���� �浹�̶��,
				else if (prev_baduk_stone == 1)
				{
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}
			}
			// ���� Ž���� ���� ���ٸ�,
			else
			{
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// ���� Ž���� ���� �밢���� ���� �ִٸ�,
			if (nowX == 1)
			{
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << nowX;

					return;
				}
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << nowX;

					return;
				}
			}

			// �밢������ �̵�
			y++;
			nowX--;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// �밢�� �Ʒ� ���� ���� �Ǵ�
	prev_baduk_stone = 0;
	for (size_t y = 1; y < 16; y++)
	{
		size_t x = 19;
		size_t nowY = y;

		// �ٵϵ��� �ٵ��� ���� �ȿ� �����ϸ�,
		while ((1 <= nowY && nowY <= 19) && (1 <= x && x <= 19))
		{
			// ���� Ž���� ���� �浹�̰�,
			if (board[nowY][x] == 1)
			{
				// ���� Ž���� ���� �浹�̶��,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// ���� Ž���� ���� �鵹�̶��,
				else if (prev_baduk_stone == 2)
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// ���� Ž���� ���� �鵹�̰�,
			else if (board[nowY][x] == 2)
			{
				// ���� Ž���� ���� �鵹�̶��,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// ���� Ž���� ���� �浹�̶��,
				else if (prev_baduk_stone == 1)
				{
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}
			}
			// ���� Ž���� ���� ���ٸ�,
			else
			{
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// ���� Ž���� ���� �밢���� ���� �ִٸ�,
			if (x == 1)
			{
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY << ' ' << x;

					return;
				}
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY << ' ' << x;

					return;
				}
			}

			// �밢������ �̵�
			nowY++;
			x--;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// �� �밢�� �� ���� ���� �Ǵ�
	prev_baduk_stone = 0;
	for (size_t x = 1; x < 16; x++)
	{
		size_t y = 1;
		size_t nowX = x;

		// �ٵϵ��� �ٵ��� ���� �ȿ� �����ϸ�,
		while ((1 <= y && y <= 19) && (1 <= nowX && nowX <= 19))
		{
			// ���� Ž���� ���� �浹�̰�,
			if (board[y][nowX] == 1)
			{
				// ���� Ž���� ���� �浹�̶��,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// ���� Ž���� ���� �鵹�̶��,
				else if (prev_baduk_stone == 2)
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// ���� Ž���� ���� �鵹�̰�,
			else if (board[y][nowX] == 2)
			{
				// ���� Ž���� ���� �鵹�̶��,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// ���� Ž���� ���� �浹�̶��,
				else if (prev_baduk_stone == 1)
				{
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}
			}
			// ���� Ž���� ���� ���ٸ�,
			else
			{
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// ���� Ž���� ���� �� �밢���� ���� �ִٸ�,
			if (nowX == 19)
			{
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 4 << ' ' << nowX - 4;

					return;
				}
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 4 << ' ' << nowX - 4;

					return;
				}
			}

			// �밢������ �̵�
			y++;
			nowX++;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// �� �밢�� �Ʒ� ���� ���� �Ǵ�
	prev_baduk_stone = 0;
	for (size_t y = 1; y < 16; y++)
	{
		size_t x = 1;
		size_t nowY = y;

		// �ٵϵ��� �ٵ��� ���� �ȿ� �����ϸ�,
		while ((1 <= nowY && nowY <= 19) && (1 <= x && x <= 19))
		{
			// ���� Ž���� ���� �浹�̰�,
			if (board[nowY][x] == 1)
			{
				// ���� Ž���� ���� �浹�̶��,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// ���� Ž���� ���� �鵹�̶��,
				else if (prev_baduk_stone == 2)
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					// ���� �浹�̹Ƿ� 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// ���� Ž���� ���� �鵹�̰�,
			else if (board[nowY][x] == 2)
			{
				// ���� Ž���� ���� �鵹�̶��,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// ���� Ž���� ���� �浹�̶��,
				else if (prev_baduk_stone == 1)
				{
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}
				// ���� Ž���� ���� ���ٸ�,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// ���� �鵹�̹Ƿ� 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}
			}
			// ���� Ž���� ���� ���ٸ�,
			else
			{
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}
				// �ٷ� �տ� Ž���� ���� 5���� ���ӵ� �ٵϵ��̰�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// ���� Ž���� ���� �� �밢���� ���� �ִٸ�,
			if (x == 19)
			{
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �浹�̶��,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 4 << ' ' << x - 4;

					return;
				}
				// 5���� ���ӵ� �ٵϵ��� �ְ�, �װ��� �鵹�̶��,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 4 << ' ' << x - 4;

					return;
				}
			}

			// �밢������ �̵�
			nowY++;
			x++;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	cout << 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> board(20, vector<int>(20, 0));
	for (size_t y = 1; y < 20; y++)
	{
		for (size_t x = 1; x < 20; x++)
		{
			cin >> board[y][x];
		}
	}

	// ����, ����, /, \ ���� ���� �Ǵ�
	FindOmok(board);
}