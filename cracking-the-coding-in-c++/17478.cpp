// ���� �¶��� ���� 17478�� https://www.acmicpc.net/problem/17478
// ���� �ð� : 1��
// ���� �ð� : 0ms

#include <iostream>
#include <string>
using namespace std;

string dash;
int recursive_function_2(int N)
{
	if (N <= 0)
	{
		cout << "��� �亯�Ͽ���.\n";
		return 0;
	}

	cout << dash << "��� �亯�Ͽ���.\n";
	dash.erase(0, 4);

	return recursive_function_2(N - 1);
}

int dashNum = 0;
int recursive_function_1(int N)
{
	if (N <= 0)
	{
		dash.append("_");
		dash.append("_");
		dash.append("_");
		dash.append("_");
		cout << dash << "\"����Լ��� ������?\"\n";
		cout << dash << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";

		return recursive_function_2(dashNum + 1);
	}

	dash.append("_");
	dash.append("_");
	dash.append("_");
	dash.append("_");
	cout << dash << "\"����Լ��� ������?\"\n";
	cout << dash << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	cout << dash << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	cout << dash << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	
	dashNum++;

	return recursive_function_1(N - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	cout << dash << "\"����Լ��� ������?\"\n";
	cout << dash << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	cout << dash << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	cout << dash << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	recursive_function_1(N - 1);
}