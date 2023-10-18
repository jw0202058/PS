#include <iostream>
#include <stack>
#include <string>
#include <iomanip>

// ���� + 48 = ����
// ���� - 48 = ����

using namespace std;

int main() {

	int N;			// �ǿ������� ����
	string postfix;
	stack<double> operand;		// �ǿ�����
	double num[27];		// �ǿ�����
	double X;
	double res = 0;
	double first;
	double second;

	cin >> N;				// ������ ����
	cin >> postfix;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < postfix.length(); i++) {
		for (int j = 0; j < 26; j++) {

			if (postfix[i] == 'A' + j) {
				postfix[i] = num[j] + 48;
			}
		}									// ��������Ŀ� ���ڸ� ������ ����

		if (postfix[i] >= '1' && postfix[i] <= '100') {		// �ǿ����ڸ� ������ ���ÿ� ����
			operand.push(postfix[i] - 48);
		}
		else {			// �����ڸ� ������ �� �� ������ ������ �Ŀ� ���ÿ� ����
			second = operand.top();
			operand.pop();
			first = operand.top();
			operand.pop();

			if (postfix[i] == '*') {
				res = first * second;
			}

			else if (postfix[i] == '+') {
				res = first + second;
			}

			else if (postfix[i] == '/') {
				res = first / second;
			}

			else if (postfix[i] == '-') {
				res = first - second;
			}
			operand.push(res);
		}
	}

	cout << fixed;
	cout << setprecision(2) << operand.top();

	return 0;

}