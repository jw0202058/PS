#include <iostream>

using namespace std;

int main() {
	int X;
	int Y;
	int LCM;		// 최소공배수
	int GCD;		// 최대공약수

	cin >> X >> Y;

	for (int i = 1; i <= max(X, Y); i++) {
		if (X % i == 0 && Y % i == 0) {
			LCM = i;
		}
	}

	// GCF = (X / LCM * Y / LCM) * LCM;
	GCD = X * Y / LCM;

	cout <<  LCM << '\n' << GCD;

}
