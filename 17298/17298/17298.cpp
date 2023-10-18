#include <iostream>
#include <stack>		// 위로 넣고 위로 빼
#include <list>		// 뒤로 넣고 앞으로 빼
#include <deque>		// 맘대로 넣었다 빼

using namespace std;

int main() {

	int N;
	int num;
	int arr[1000001];
	int count;
	stack<int> seq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		count = 0;

		cin >> num;
		arr[i] = num;

		if (seq.empty())		// 스택이 비어 있다면 푸시				
			seq.push(i);

		else {					// 스택이 비어 있지 않다면, 현재 수와 스택의 탑에 있는 수와 비교
			while (1) {
				if (num < seq.top()) {
					seq.push(i);
					break;
				}
				else {
					count++;
					seq.pop();
				}
			}
			for (int j = 0; j < count; j++) {
				seq.push(i);
			}
		}


	}

}

