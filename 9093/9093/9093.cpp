#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// 공백 기준으로 배열에 입력 후 배열 사이즈만큼 거꾸로 출력
// 최대 길이가 1000인 문자를 입력받는데, 문자를 순회해서 공백이 있으면 배열에 집어넣고, 

int main() {

	int N;
	string word;
	string str;
	//stringstream stream;

	cin >> N;			// 테스트 케이스 개수
	//cout << "개수: " << N << '\n';
	cin.ignore();

	for (int j = 0; j < N ; j++) {
		//cout << "시작";

		getline(cin, str);				// 공백을 포함한 문자열 입력받기

		stringstream stream(str);		// stream에 str을 대입

		while (stream >> word)		// 공백이나 \n이 나올 때까지 
		{
			for (int i = word.size(); i > 0; i--) {
				cout << word[i - 1];
			}											// 문자열 거꾸로 출력하기
			cout << ' ';
		}
		cout << '\n';
	}
}
