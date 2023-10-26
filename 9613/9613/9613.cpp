#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#include <queue>

using namespace std;

int getGCD(int x, int y) {			// �ִ� ����� ���ϴ� ��

	ll GCD = 0;			// �ִ� ����� : �� ���� ������� �� ���� ū ��... 
	
	// �� ����� �ð� �ʰ�!
	
	//for (int i = 1; i <= min(x, y); i++)		// 100
	//{
	//	if (x % i == 0 && y % i == 0) {
	//		GCD = i;
	//	}
	//}

	// ��Ŭ���� ȣ������ ����ϸ� �ð� �ʰ��� ���� �ʴ´�

	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	GCD = x;

	return GCD;
}

int main(void) {
	FAST_IO;

	ll GCD = 0;
	int t;
	int n;
	int a;

	queue<int> temp;
	queue<int> oper;

	int x, y;

	cin >> t;

	for (int i = 0; i < t; i++) {		
		GCD = 0;

		cin >> n;

		for (int j = 0; j < n; j++) {		
			cin >> a;
			oper.push(a);
		}

		while (!oper.empty()) {				
			x = oper.front();
			oper.pop();
			temp = oper;

			while (!temp.empty()) {			
				GCD += getGCD(x, temp.front());
				temp.pop();
			}

		}
		cout << GCD << '\n';
	}
	return 0;
}
