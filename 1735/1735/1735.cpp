#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

int getGCD(int x, int y) {

	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

int main(void) {
	FAST_IO;

	int A_1, B_1;
	int A_2, B_2;

	int A_, B_;
	int A, B;

	cin >> A_1 >> B_1 >> A_2 >> B_2;

	// B와 A가 공배수가 있다면 나눠 줄 것 -> 최대공배수로 나눠 주자

	B_ = B_1 * B_2;
	A_ = B_2 * A_1 + B_1 * A_2;

	A = A_ / getGCD(A_, B_);
	B = B_ / getGCD(A_, B_);

	cout << A << ' ' << B << ' ';

	return 0;
}
