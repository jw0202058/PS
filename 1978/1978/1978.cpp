#include <iostream>

using namespace std;

int main() {

	int X;
	int Y;
	int count = 0;
	bool IsPrime = false;

	cin >> X;

	for (int i = 0; i < X; i++) {
		cin >> Y;
		if (Y == 2) {
			IsPrime = true;
		}
		else {
			for (int j = 2; j < Y; j++) {
				if (Y % j == 0) {
					IsPrime = false;
					break;
				}
				else
					IsPrime = true;
			}
		}
		if (IsPrime)
			count++;
	}

	cout << count;
}