#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	int N;
	bool IsVPS;			// ���� ������ ��� ������ true�� �ǰ�
	string str;

	cin >> N;
	cin.ignore();

	// �ѹ� �������� �ݵ�� �ѹ� ������ ��. ( �������� ��� �ϳ��� )�� �־�� �ϰ�, ) �������� ��� �ϳ��� (�� �־�� �Ѵ�?!
	// ( )�� �� ��...
	// ���� �� �ѹ� �������� 

	for (int i = 0; i < N; i++) {
		stack<char> open;			// (�� ���� ������ ���ÿ� �߰�
		stack<char> close;			// )�� ���� ������ ���ÿ� �߰�, ���࿡ �� ó���� )�̸� �ٷ� break
		
		IsVPS = false;		// �ϴ� ó������ VPS�� �ƴϴ�
		

		cin >> str;

		for (int j = 0; j < str.size(); j++) {			// �Է��� ��Ʈ���� ���̸�ŭ
			if (str[0] == ')')							// �� ó���� )�̸� �ٷ� NO ��ȯ
			{
				close.push(str[j]);
				break;
			}

			if (str[j] == '(')							// (�̸� ���� ���ÿ� ����
				open.push(str[j]);
			else {										// )�̸� Ŭ���� ���ÿ� ����, �ѹ� ���� ��, ���� ������ ��� ���� �ʴٸ� ���� ���� ��, Ŭ���� ���� ��
				if (!open.empty()) {
					open.pop();
					//close.pop();
				}
				else
					close.push(str[j]);
			}
		}

		if (open.empty() && close.empty())			// ���� (, )�� ������ VPS�� �´�
			IsVPS = true;
		else
			IsVPS = false;

		if (IsVPS) {			// VPS�� ������ YES ��ȯ
			cout << "YES" << "\n";
		}
		else {					// VPS�� �ƴϸ� NO ��ȯ
			cout << "NO" << "\n";
		}
	}
}