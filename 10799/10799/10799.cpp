#include <iostream>
#include <stack>

using namespace std;

int main() {

	string str;
	int laser;
	int piece;
	int total = 0;
	stack<char> bar;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {

		if (str[i] == '(' && str[i + 1] != ')') {		// 막대기 시작
			bar.push(str[i]);							// 막대기 스택에 집어넣기
		}

		if (i > 0 && str[i - 1] != '(' && str[i] == ')') {								// 막대기가 닫히면
			total++;										// 전체 개수 하나 추가
			bar.pop();										// 막대기 스택 팝
		}

		if (str[i] == '(' && str[i + 1] == ')') {			// 레이저가 나오면
			total += bar.size();
		}
	}

	cout << total << '\n';

}
