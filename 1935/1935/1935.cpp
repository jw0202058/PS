#include <iostream>
#include <stack>
#include <string>
#include <iomanip>

// 숫자 + 48 = 문자
// 문자 - 48 = 숫자

using namespace std;

int main() {

	int N;			// 피연산자의 개수
	string postfix;
	stack<double> operand;		// 피연산자
	double num[27];		// 피연산자
	double X;
	double res = 0;
	double first;
	double second;

	cin >> N;				// 문자의 개수
	cin >> postfix;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < postfix.length(); i++) {
		for (int j = 0; j < 26; j++) {

			if (postfix[i] == 'A' + j) {
				postfix[i] = num[j] + 48;
			}
		}									// 후위연산식에 숫자를 대입해 놓음

		if (postfix[i] >= '1' && postfix[i] <= '100') {		// 피연산자를 만나면 스택에 저장
			operand.push(postfix[i] - 48);
		}
		else {			// 연산자를 만나면 두 개 꺼내서 연산한 후에 스택에 저장
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