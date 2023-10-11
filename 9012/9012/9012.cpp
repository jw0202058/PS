#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	int N;
	bool IsVPS;			// 오픈 스택이 비어 있으면 true가 되게
	string str;

	cin >> N;
	cin.ignore();

	// 한번 열렸으면 반드시 한번 닫혀야 함. ( 다음에는 적어도 하나의 )가 있어야 하고, ) 이전에는 적어도 하나의 (가 있어야 한다?!
	// ( )는 한 쌍...
	// 열린 게 한번 닫혔으면 

	for (int i = 0; i < N; i++) {
		stack<char> open;			// (가 나올 때마다 스택에 추가
		stack<char> close;			// )가 나올 때마다 스택에 추가, 만약에 맨 처음이 )이면 바로 break
		
		IsVPS = false;		// 일단 처음에는 VPS가 아니다
		

		cin >> str;

		for (int j = 0; j < str.size(); j++) {			// 입력한 스트링의 길이만큼
			if (str[0] == ')')							// 맨 처음이 )이면 바로 NO 반환
			{
				close.push(str[j]);
				break;
			}

			if (str[j] == '(')							// (이면 오픈 스택에 저장
				open.push(str[j]);
			else {										// )이면 클로즈 스택에 저장, 한번 나올 때, 오픈 스택이 비어 있지 않다면 오픈 스택 팝, 클로즈 스택 팝
				if (!open.empty()) {
					open.pop();
					//close.pop();
				}
				else
					close.push(str[j]);
			}
		}

		if (open.empty() && close.empty())			// 남은 (, )가 없으면 VPS가 맞다
			IsVPS = true;
		else
			IsVPS = false;

		if (IsVPS) {			// VPS가 맞으면 YES 반환
			cout << "YES" << "\n";
		}
		else {					// VPS가 아니면 NO 반환
			cout << "NO" << "\n";
		}
	}
}