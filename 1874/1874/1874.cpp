#include <iostream>
#include <string>
#include <stack>
#include <queue>

// 1부터 차례대로 스택에 넣고, 넣다가 만약에 입력받은 숫자와 동일하면 푸시
// 전체 숫자를 다 입력받고 나서야 출력...? 음...
// 범위를 넘어가???

using namespace std;

int main() {

	int N;
	int num;
	stack<int> seq;		// 수열 스택 선언
	queue<char> output;		// 수열 스택 선언
	int index = 0;
	int j = 0;
	bool IsPossible = true;

	seq.push(0);

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> num;

		while (seq.top() != num)			// 입력받은 숫자가 스택의 탑과 같지 않다면 정수 푸시
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

		if (seq.top() == num) {	// 입력받은 숫자가 스택의 탑과 같아지면
			seq.pop();			// 맨 위에 있는 숫자 팝
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
