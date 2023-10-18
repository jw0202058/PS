#include <iostream>
#include <stack>		// ���� �ְ� ���� ��
#include <list>		// �ڷ� �ְ� ������ ��
#include <deque>		// ����� �־��� ��

using namespace std;

int main() {

	int N;
	int num;
	int arr[1000001];
	int count;
	stack<int> seq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		count = 0;

		cin >> num;
		arr[i] = num;

		if (seq.empty())		// ������ ��� �ִٸ� Ǫ��				
			seq.push(i);

		else {					// ������ ��� ���� �ʴٸ�, ���� ���� ������ ž�� �ִ� ���� ��
			while (1) {
				if (num < seq.top()) {
					seq.push(i);
					break;
				}
				else {
					count++;
					seq.pop();
				}
			}
			for (int j = 0; j < count; j++) {
				seq.push(i);
			}
		}


	}

}

