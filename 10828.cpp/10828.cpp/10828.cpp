#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string commend;
    int N;
    int X;
    stack<int> s; // ������ �κ�

	cin >> N;                 // ù ��° �ٿ� �� ���� ��ɾ �Է��� ������ ���

	for (int i = 0; i < N; i++) {           // ��� �Է�
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
