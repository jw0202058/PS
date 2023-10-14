#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {

	int K;
	int N;
	list<int> circle;
	list<int>::iterator iter;
	list<int>::iterator end;

	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++) {
		circle.push_back(i);		// ���� �ϳ��ϳ� �߰�
	}

	iter = circle.begin();			// ���� ����Ű�� �ִ� ���� ����Ʈ�� �� ó��


	cout << "<";

	for (int i = 0; i < N; i++)			// ��� ����� ������ ������
	{
		end = circle.end();
		end--;

		for (int i = 0; i < K - 1; i++) {
			if (iter == end)							// ���� ����Ű�� �ִ� ���� ����Ʈ�� �� �������̶��, �� ó������ ���ư��� �ٽ� ����ų ��
			{
				iter = circle.begin();
			}
			else
				iter++;
		}

		if (i != N-1)
			cout << *iter << ", ";
		else
			cout << *iter << ">";

		if (iter == end) {
			circle.erase(iter);
			iter = circle.begin();
		}
		else {
			iter = circle.erase(iter);
		}
	}

	return 0;

}