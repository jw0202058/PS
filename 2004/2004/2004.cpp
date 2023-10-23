#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

// 

int main(void) {
	FAST_IO;

	int n, r, m;
	int n_two = 0, r_two = 0, m_two = 0;
	int n_five = 0, r_five = 0, m_five = 0;
	int n_zero = 0, r_zero = 0, m_zero = 0;
	int five = 0, two = 0;
	int res = 0;

	cin >> n >> m;
	r = n - m;

	for (ll j = 5; j <= n; j *= 5) {          // n, r, m 차례대로 구하고 n-r-m 하기
		n_five += n / j;
	}
	for (ll j = 5; j <= r; j *= 5) {          // n, r, m 차례대로 구하고 n-r-m 하기
		r_five += r / j;
	}
	for (ll j = 5; j <= m; j *= 5) {          // n, r, m 차례대로 구하고 n-r-m 하기
		m_five += m / j;
	}
	
	for (ll j = 2; j <= n; j *= 2) {          // n, r, m 차례대로 구하고 n-r-m 하기
		n_two += n / j;
	}
	for (ll j = 2; j <= r; j *= 2) {          // n, r, m 차례대로 구하고 n-r-m 하기
		r_two += r / j;
	}
	for (ll j = 2; j <= m; j *= 2) {          // n, r, m 차례대로 구하고 n-r-m 하기
		m_two += m / j;
	}

	five = n_five - m_five - r_five;
	two = n_two - m_two - r_two;

	res = min(five, two);

	cout << res;

	return 0;
}
