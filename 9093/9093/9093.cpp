#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// ���� �������� �迭�� �Է� �� �迭 �����ŭ �Ųٷ� ���
// �ִ� ���̰� 1000�� ���ڸ� �Է¹޴µ�, ���ڸ� ��ȸ�ؼ� ������ ������ �迭�� ����ְ�, 

int main() {

	int N;
	string word;
	string str;
	//stringstream stream;

	cin >> N;			// �׽�Ʈ ���̽� ����
	//cout << "����: " << N << '\n';
	cin.ignore();

	for (int j = 0; j < N ; j++) {
		//cout << "����";

		getline(cin, str);				// ������ ������ ���ڿ� �Է¹ޱ�

		stringstream stream(str);		// stream�� str�� ����

		while (stream >> word)		// �����̳� \n�� ���� ������ 
		{
			for (int i = word.size(); i > 0; i--) {
				cout << word[i - 1];
			}											// ���ڿ� �Ųٷ� ����ϱ�
			cout << ' ';
		}
		cout << '\n';
	}
}
