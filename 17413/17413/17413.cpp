#include <iostream>
#include <string>
#include <stack>

// 공백을 포함한 문자열을 입력받은 후, 

using namespace std;

int main() {

	string str;
	stack<char> word;

	getline(cin, str);

	for (int i = 0; i < str.length(); ) {
		if (str[i] == '<') {					// <가 나왔으면
			for (i; ; i++) {		// >가 나올 때까지 그냥 출력
				cout << str[i];
				if (str[i] == '>')
					break;
			}
			i++;

		}
		else {			// <가 안 나왔으면
			while (str[i] != ' ' && str[i] != '<' && i != str.length()) {		// 공백도, <도 아니면
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
