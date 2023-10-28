#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>

// 수빈이의 위치와 동생들의 위치들의 여러 수 최대 공약수 구하기

using namespace std;

int getGCD(int x, int y) {
	
	int r;

	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}

	return x;

}

int main(void) {
	FAST_IO;

	int N, S;
	int _A;

	cin >> N >> S;

	int* A = new int[N];

	int res;


	if (N == 1) {				// 동생이 한 명이라면...!!
		cin >> _A;

		if (S - _A >= 0) {
			cout << S - _A;
		}
		else
			cout << _A - S;
		return 0;
	}

	// 동생이 한 명이 아니라면!
	for (int i = 0; i < N; i++) {
		cin >> _A;

		if (S - _A >= 0) {
			A[i] = S - _A;
		}
		else
		{
			A[i] = _A - S;
		}
	}

	res = A[0];

	for (int i = 1; i < N; i++) {
		res = getGCD(res, A[i]);
	}

	cout << res;

	return 0;
}