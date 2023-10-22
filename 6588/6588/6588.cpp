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

	num[1] = 0;			// 1�� �Ҽ��� �ƴ�

	// Ȧ�� �Ҽ��� �Ǻ��ϸ� �ȴ�

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

		for (int i = 3; i <= X / 2; i += 2) {			// Ȧ���� ���� �Ǵϱ�
			if (num[i] != 0) {
				p = num[i];					// ���� ���� �Ҽ�

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
