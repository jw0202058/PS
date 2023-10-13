#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

struct NODE {
	char data;
	NODE* llink;
	NODE* rlink;
};

NODE* head;
NODE* tail;

struct NODE* makenode(char word) {
	struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
	node->llink = NULL;
	node->data = word;
	node->rlink = NULL;
	return node;
}

void init() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	tail = (struct NODE*)malloc(sizeof(struct NODE));
	head->data = NULL;
	tail->data = NULL;

	head->rlink = tail;
	head->llink = head;
	tail->rlink = tail;
	tail->llink = head;

}

int main() {
	init();

	string sentence;
	int N;
	char word;
	char commend;
	NODE* cursor = makenode(NULL);
	NODE* newNode;
	NODE* temp = head;;

	cin >> sentence;
	// sentence�� �� �� �� �� ��忡 ����
	for (int i = 0; i < sentence.length(); i++) {	
		newNode = makenode(sentence[i]);		// �� �� �� �ڸ� ���� �ִ� ��带 ����
		temp->rlink = newNode;
		temp->rlink->llink = temp;
		temp = temp->rlink;
	}

	temp->rlink = cursor;
	temp->rlink->llink = temp;
	cursor->rlink = tail;
	tail->llink = cursor;

	// �Ϸ�

	cin >> N;

	for (int i = 0; i < N; i++) {	
		
		cin >> commend;

		switch (commend) {
		case 'P':				// word�� Ŀ�� ���ʿ� �߰�
			cin >> word;
			newNode = makenode(word);		// ���ο� ��带 �߰��ϰ�
			newNode->llink = cursor->llink;
			newNode->rlink = cursor;
			cursor->llink->rlink = newNode;
			cursor->llink = newNode;

			break;

		case 'L':				// Ŀ���� �������� �̵� (�� ���� �ƴ� ���)
			if (cursor->llink != head) {
				cursor->llink->rlink = cursor->rlink;
				cursor->rlink->llink = cursor->llink;			// ���� �ִ� Ŀ�� ����

				cursor->rlink = cursor->llink;					// Ŀ�� �� �� ����
				cursor->llink = cursor->llink->llink;

				cursor->llink->rlink = cursor;
				cursor->rlink->llink = cursor;
			}
			break;
		
		case 'D':				// Ŀ���� ���������� �̵� (�� �ڰ� �ƴ� ���)
			if (cursor->rlink != tail) {
				cursor->llink->rlink = cursor->rlink;
				cursor->rlink->llink = cursor->llink;			// ���� �ִ� Ŀ�� ����

				cursor->llink = cursor->rlink;
				cursor->rlink = cursor->rlink->rlink;

				cursor->rlink->llink = cursor;
				cursor->llink->rlink = cursor;
			}
			break;
		
		case 'B':				// Ŀ�� ���� ���ڸ� ���� (�� ���� �ƴ� ���)
			if (cursor->llink != head) {
				cursor->llink->llink->rlink = cursor;
				cursor->llink = cursor->llink->llink;
			}
			break;
		}
	}
	for (NODE* pp = head->rlink; pp != tail; pp = pp->rlink)
		if (pp->data)
			cout << pp->data;
	cout << '\n';

	return 0;
}
