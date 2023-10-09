#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string commend;
    int N;
    int X;
    stack<int> s; // 수정된 부분

	cin >> N;                 // 첫 번째 줄에 몇 개의 명령어를 입력할 것인지 출력

	for (int i = 0; i < N; i++) {           // 명령 입력
		cin >> commend;
		if (commend == "push") {
			cin >> X;
			s.push(X);
		}
		else if (commend == "pop") {
			if (s.empty())
				cout << -1 << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (commend == "size")
			cout << s.size() << "\n";
		else if (commend == "empty") {
			if (s.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (commend == "top") {
			if (s.empty())
				cout << -1 << "\n";
			else
				cout << s.top() << "\n";
		}

	}

	return 0;
}
