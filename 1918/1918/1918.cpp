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
		if (input[i] >= 'A' && input[i] <= 'Z') {			// 피연산자를 만나면 무조건 출력
			postfix.push(input[i]);
		}

		else if (input[i] == '(')			// (를 만나면 push
		{
			oper.push(input[i]);
		}

		else if (input[i] == '+' || input[i] == '-') {			// 연산자를 만나면 우선순위가 높거나 같은 경우 pop (우선순위가 높은 애들 먼저 pop 해 줘야 하니까)
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

		else if (input[i] == ')')					// )를 만나면 (가 나올 때까지 출력
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
