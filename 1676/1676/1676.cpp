#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

// ���� ������ ���� ������ ��� �˻��� ������ ��, 5�� ��� ����, 25�� ��� ����, 125�� ��� ���� �� ���ؼ� ���ϱ�

int main(void) {
	FAST_IO;

	int X;
	ll f = 1;
	int count = 0;
	int res = 0;

	cin >> X;

	if (X == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 5; i <= X; i*=5)
	{
		count = X / i;
		res += count;
	}

	cout << res << '\n';

	return 0;
}
