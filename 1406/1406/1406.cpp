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
	// sentence를 한 자 한 자 노드에 삽입
	for (int i = 0; i < sentence.length(); i++) {	
		newNode = makenode(sentence[i]);		// 한 자 한 자를 갖고 있는 노드를 생성
		temp->rlink = newNode;
		temp->rlink->llink = temp;
		temp = temp->rlink;
	}

	temp->rlink = cursor;
	temp->rlink->llink = temp;
	cursor->rlink = tail;
	tail->llink = cursor;

	// 완료

	cin >> N;

	for (int i = 0; i < N; i++) {	
		
		cin >> commend;

		switch (commend) {
		case 'P':				// word를 커서 왼쪽에 추가
			cin >> word;
			newNode = makenode(word);		// 새로운 노드를 추가하고
			newNode->llink = cursor->llink;
			newNode->rlink = cursor;
			cursor->llink->rlink = newNode;
			cursor->llink = newNode;

			break;

		case 'L':				// 커서를 왼쪽으로 이동 (맨 앞이 아닌 경우)
			if (cursor->llink != head) {
				cursor->llink->rlink = cursor->rlink;
				cursor->rlink->llink = cursor->llink;			// 원래 있던 커서 삭제

				cursor->rlink = cursor->llink;					// 커서 양 옆 연결
				cursor->llink = cursor->llink->llink;

				cursor->llink->rlink = cursor;
				cursor->rlink->llink = cursor;
			}
			break;
		
		case 'D':				// 커서를 오른쪽으로 이동 (맨 뒤가 아닌 경우)
			if (cursor->rlink != tail) {
				cursor->llink->rlink = cursor->rlink;
				cursor->rlink->llink = cursor->llink;			// 원래 있던 커서 삭제

				cursor->llink = cursor->rlink;
				cursor->rlink = cursor->rlink->rlink;

				cursor->rlink->llink = cursor;
				cursor->llink->rlink = cursor;
			}
			break;
		
		case 'B':				// 커서 왼쪽 글자를 삭제 (맨 앞이 아닌 경우)
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
