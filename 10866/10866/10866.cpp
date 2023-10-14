#include <iostream>
#include <deque>

using namespace std;

int main() {

	deque<int> deque;
	int N;
	int X;
	string commend;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> commend;

		if (commend == "push_front") {
			cin >> X;
			deque.push_front(X);
		}
		else if (commend == "push_back") {
			cin >> X;
			deque.push_back(X);
		}
		else if (commend == "pop_front") {
			if (deque.empty())
				cout << -1 << "\n";
			else {
				cout << deque.front() << '\n';
				deque.pop_front();
			}
		}
		else if (commend == "pop_back") {
			if (deque.empty())
				cout << -1 << "\n";
			else {
				cout << deque.back() << '\n';
				deque.pop_back();
			}
		}
		else if (commend == "size") {
			cout << deque.size() << '\n';
		}
		else if (commend == "empty") {
			if (deque.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (commend == "front") {
			if (deque.empty())
				cout << -1 << "\n";
			else {
				cout << deque.front() << '\n';
			}
		}
		else {
			if (deque.empty())
				cout << -1 << "\n";
			else {
				cout << deque.back() << '\n';
			}
		}
	}
	return 0;

}