// ���� �¶��� ���� 1966�� https://www.acmicpc.net/problem/1966
// ���� �ð� : 2��
// ���� �ð� : ms

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCaseNum; // �׽�Ʈ ���̽��� ��
	int N; // ������ ����
	int M; // �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� Queue���� �� ��°�� �����ִ����� ��Ÿ���� ����
	int importance; // �߿䵵
	
	cin >> testCaseNum;
	for (int i = 0; i < testCaseNum; i++)
	{
		vector<int> queue;

		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> importance;
			queue.push_back(importance); // �߿䵵�� �迭�� ���ҷ� ����
		}
		
		int cnt = 0;
		bool isPrinted = false;
		// ������ ������ŭ �ݺ�
		for (int j = 0; j < queue.size(); j++)
		{
			if (isPrinted)
			{
				break;
			}
			cnt++;

			int maxNum = -999;
			for (int k = 0; k < queue.size(); k++)
			{
				if (maxNum < queue[k])
				{
					maxNum = queue[k];
				}
				else if (maxNum == queue[k])
				{
					
				}
			}
			
			for (int k = 0; k < queue.size(); k++)
			{
				if (queue[M] == maxNum)
				{
					cout << cnt << '\n';
					isPrinted = true;
					break;
				}
				else if (queue[k] == maxNum)
				{
					queue[k] = -1; // ���� �ִ밪�� -1�� ���� (-1�� ��µ��� ǥ��)
					break;
				}
			}
		}
	}
}
