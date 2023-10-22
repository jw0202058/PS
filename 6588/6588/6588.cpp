#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

int main() {
	FAST_IO

	int X;
	static int num[1000001];
	int p;
	int n = 1;
	bool IsGoldbach = false;

	int b;

	X = 1000001;

	for (int i = 0; i < X; i++) {
		num[i] = i;
	}

	num[1] = 0;			// 1은 소수가 아님

	// 홀수 소수만 판별하면 된다

	for (int i = 3; i * i <= X; i += 2) {
		if (num[i] != 0) {
			p = num[i];
			for (int j = i * i; j <= X; j += i) {
				num[j] = 0;
			}
		}
	}

	while (1) {
		IsGoldbach = false;
		cin >> X;

		if (X == 0)
			return 0;

		for (int i = 3; i <= X / 2; i += 2) {			// 홀수만 보면 되니깐
			if (num[i] != 0) {
				p = num[i];					// 가장 작은 소수

				if (num[X - p] != 0) {
					b = X - p;
					IsGoldbach = true;
					break;
				}
			}
		}
		if (!IsGoldbach) {
			cout << "Goldbach's conjecture is wrong\n";
			return 0;
		}

		cout << X << " = " << p << " + " << b << '\n';
	}
	return 0;
}
