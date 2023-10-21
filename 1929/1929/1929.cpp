#include <iostream>

using namespace std;

int main() {
	int X;
	int Y;
	static int num[1000001];

	cin >> X >> Y;

	for (int i = 0; i <= Y; i++) {				// Y까지 순서대로 배열에 저장
		num[i] = i;
	}

	num[1] = 0;									// 1은 소수 아니니까 냅다 0

	for (int i = 2; i * i <= Y; i++) {			// 2부터 최대 수의 제곱근까지 (제곱근까지만 보면 됨)
		if (num[i] != 0) {						// 지금 보고 있는 수가 소수라면!
			for (int j = i * i; j <= Y; j += i) {			// 지금 보고 있는 수 제외하고, 배수는 모두 0으로 치환~
				num[j] = 0;
			}
		}
	}

	for (int i = X; i <= Y; i++) {				// 0이 아니면 출력
		if (num[i] != 0)
			cout << num[i] << '\n';
	}

	return 0;
}
