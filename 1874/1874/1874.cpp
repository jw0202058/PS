#include <iostream>
#include <string>
#include <stack>
#include <queue>

// 1���� ���ʴ�� ���ÿ� �ְ�, �ִٰ� ���࿡ �Է¹��� ���ڿ� �����ϸ� Ǫ��
// ��ü ���ڸ� �� �Է¹ް� ������ ���...? ��...
// ������ �Ѿ???

using namespace std;

int main() {

	int N;
	int num;
	stack<int> seq;		// ���� ���� ����
	queue<char> output;		// ���� ���� ����
	int index = 0;
	int j = 0;
	bool IsPossible = true;

	seq.push(0);

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> num;

		while (seq.top() != num)			// �Է¹��� ���ڰ� ������ ž�� ���� �ʴٸ� ���� Ǫ��
		{
			if (num < j) {
				IsPossible = false;
				break;
			}

			j++;
			seq.push(j);
			output.push('+');
			index++;
//			cout << "+" << "\n";
		}

		if (seq.top() == num) {	// �Է¹��� ���ڰ� ������ ž�� ��������
			seq.pop();			// �� ���� �ִ� ���� ��
			output.push('-');
			index++;
//			cout << "-" << "\n";
		}
	}

	index = 0;

	if (!IsPossible) {
		cout << "NO" << "\n";
		return 0;
	}

	while (!output.empty()) {
		cout << output.front() << "\n";
		output.pop();
	}

	return 0;
}
