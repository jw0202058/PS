#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 뒤로 넣고 앞으로 뺀다

int main() {
	queue<int> queue;
	int N;
	string commend;
	int X;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> commend;
		if (commend == "push") {
			cin >> X;
			queue.push(X);
		}

		else if (commend == "pop") {
			if (!queue.empty()) {
				cout << queue.front() << '\n';
				queue.pop();
			}
			else
				cout << -1 << '\n';
		}

		else if (commend == "size") {
			cout << queue.size() << '\n';
		}

		else if (commend == "empty") {
			if (queue.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		else if (commend == "front") {
			if (!queue.empty())
				cout << queue.front() << '\n';
			else
				cout << -1 << '\n';
		}

		else if (commend == "back") {
			if (!queue.empty())
				cout << queue.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}

	return 0;
	
}