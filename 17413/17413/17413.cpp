#include <iostream>
#include <string>
#include <stack>

// ������ ������ ���ڿ��� �Է¹��� ��, 

using namespace std;

int main() {

	string str;
	stack<char> word;

	getline(cin, str);

	for (int i = 0; i < str.length(); ) {
		if (str[i] == '<') {					// <�� ��������
			for (i; ; i++) {		// >�� ���� ������ �׳� ���
				cout << str[i];
				if (str[i] == '>')
					break;
			}
			i++;

		}
		else {			// <�� �� ��������
			while (str[i] != ' ' && str[i] != '<' && i != str.length()) {		// ���鵵, <�� �ƴϸ�
				word.push(str[i]);
				i++;
			}
			while (!word.empty()) {
				cout << word.top();
				word.pop();
			}
			if (str[i] == ' ') {
				cout << ' ';
				i++;
			}
		}
	}
}
