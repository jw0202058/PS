#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main(void) {
//
//	int num[1000];
//	int n, k, p, c;
//	int order = 0;
//
//	scanf("%d %d", &n, &k);		// 10 
//
//	if (1 > k || n > 1000 || k > n)
//		return 0;
//
//	for (int i = 0; i < n - 1; i++) {
//		num[i] = i + 2;
//		//printf("%d", num[i]);		// 2 3 4 5 6 7 8 9 10  2���� N���� ��� ������ ���´�
//	}
//
//	p = num[0];		// �� ���� �� �� ���� ���� ���� �Ҽ�
//
//	//printf("\n");
//
//	while (p > 0) {		// ���� ��� ���� �������� �ʾ��� ���...
//		
//		p = num[0];		// �� ���� �� �� ���� ���� ���� �Ҽ�
//		
//		order++;
//		if (order == k) {
//			printf("%d", p);
//			return 0;
//		}
//
//		for (int i = 0; i < n - 1; i++) {
//			num[i] = num[i + 1];
//			//printf("%d", num[i]);			// p�� �����,
//		}
//
//		//printf("\n");
//
//		for (int i = 0; i < n - 1; i++) {	// ��ü�� �� ���� ������ ��
//			for (c = 2; c * p < n + 1; c++) {
//				if (num[i] == p * c) {		// ���� ���� �ִ� ���� �Ҽ��� ������
//					order++;
//					if (order == k) {
//						printf("%d", num[i]);
//						return 0;
//					}
//					num[i] = 0;				// 0���� �ΰ� ���ݴٰ� ġ��
//				}
//			}
//		}
//	}
//	return 0;
//}

// ����� ���� ī��Ʈ�� �ø���, ī��Ʈ�� k�� ���ٸ� �� ���� ����ϱ�
// �ð� �ʰ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!1


int main(void) {

	int num[1000];
	int n, k, p, c;
	int count = 0;
	int order = 0;

	scanf("%d %d", &n, &k);		// 10 

	if (1 > k || n > 1000 || k > n)
		return 0;


	for (int i = 0; i < n - 1; i++) {
		num[i] = i + 2;
		//printf("%d", num[i]);		// 2 3 4 5 6 7 8 9 10  2���� N���� ��� ������ ���´�
	}
	p = num[0];		// �� ���� �� �� ���� ���� ���� �Ҽ�

	while (p > 0) {		// ���� ��� ���� �������� �ʾ��� ���...

		for (int i = 0; i < n - 1; i++) {
			if (num[i] != 0) {
				p = num[i];
				order++;
				if (order == k) {
					printf("%d", num[i]);
					return 0;
				}
				num[i] = 0;
				break;			// 0�� �ƴ� ���� �߰��ϸ� �� ��� p�� �ְ�, num[i]�� 0���� �ٲ� ����(p�� �����) �ݺ��� ����������
			}
		}

		for (int i = 0; i < n - 1; i++) {	// ��ü�� �� ���� ������ ��
			for (c = 2; c * p <= n; c++) {
				if (num[i] == p * c) {		// ���� ���� �ִ� ���� �Ҽ��� ������
					order++;
					if (order == k) {
						printf("%d", num[i]);
						return 0;
					}
					num[i] = 0;				// 0���� �ΰ� ���ݴٰ� ġ��
				}
			}
		}
	}
	return 0;
}