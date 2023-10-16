#include <iostream>
#include <stack>

using namespace std;

int main() {

	string str;
	int laser;
	int piece;
	int total = 0;
	stack<char> bar;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {

		if (str[i] == '(' && str[i + 1] != ')') {		// ����� ����
			bar.push(str[i]);							// ����� ���ÿ� ����ֱ�
		}

		if (i > 0 && str[i - 1] != '(' && str[i] == ')') {								// ����Ⱑ ������
			total++;										// ��ü ���� �ϳ� �߰�
			bar.pop();										// ����� ���� ��
		}

		if (str[i] == '(' && str[i + 1] == ')') {			// �������� ������
			total += bar.size();
		}
	}

	cout << total << '\n';

}
