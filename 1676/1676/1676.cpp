#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

// 현재 수보다 작은 수들을 모두 검사해 보았을 때, 5의 배수 개수, 25의 배수 개수, 125의 배수 개수 다 구해서 더하기

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
