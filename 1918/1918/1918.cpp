#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	string input;

	stack<char> oper;
	queue<char> postfix;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {			// �ǿ����ڸ� ������ ������ ���
			postfix.push(input[i]);
		}

		else if (input[i] == '(')			// (�� ������ push
		{
			oper.push(input[i]);
		}

		else if (input[i] == '+' || input[i] == '-') {			// �����ڸ� ������ �켱������ ���ų� ���� ��� pop (�켱������ ���� �ֵ� ���� pop �� ��� �ϴϱ�)
			while (!oper.empty() && oper.top() != '(') {
				postfix.push(oper.top());
				oper.pop();
			}
			oper.push(input[i]);
		}

		else if (input[i] == '*' || input[i] == '/')
		{
			while (!oper.empty() && (oper.top() == '*' || oper.top() == '/'))
			{
				postfix.push(oper.top());
				oper.pop();
			}
			oper.push(input[i]);
		}

		else if (input[i] == ')')					// )�� ������ (�� ���� ������ ���
		{
			while (oper.top() != '(') {
				postfix.push(oper.top());
				oper.pop();
			}
			oper.pop();
		}
	}

	while (!oper.empty()) {
		postfix.push(oper.top());
		oper.pop();
	}

	while (!postfix.empty()) {
		cout << postfix.front();
		postfix.pop();
	}

	return 0;
}
