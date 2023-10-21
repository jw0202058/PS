#include <iostream>

using namespace std;

int main() {
	int X;
	int Y;
	static int num[1000001];

	cin >> X >> Y;

	for (int i = 0; i <= Y; i++) {				// Y���� ������� �迭�� ����
		num[i] = i;
	}

	num[1] = 0;									// 1�� �Ҽ� �ƴϴϱ� ���� 0

	for (int i = 2; i * i <= Y; i++) {			// 2���� �ִ� ���� �����ٱ��� (�����ٱ����� ���� ��)
		if (num[i] != 0) {						// ���� ���� �ִ� ���� �Ҽ����!
			for (int j = i * i; j <= Y; j += i) {			// ���� ���� �ִ� �� �����ϰ�, ����� ��� 0���� ġȯ~
				num[j] = 0;
			}
		}
	}

	for (int i = X; i <= Y; i++) {				// 0�� �ƴϸ� ���
		if (num[i] != 0)
			cout << num[i] << '\n';
	}

	return 0;
}
