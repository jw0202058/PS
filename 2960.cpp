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
//		//printf("%d", num[i]);		// 2 3 4 5 6 7 8 9 10  2부터 N까지 모든 정수를 적는다
//	}
//
//	p = num[0];		// 안 지운 수 중 가장 작은 수가 소수
//
//	//printf("\n");
//
//	while (p > 0) {		// 아직 모든 수가 지워지지 않았을 경우...
//		
//		p = num[0];		// 안 지운 수 중 가장 작은 수가 소수
//		
//		order++;
//		if (order == k) {
//			printf("%d", p);
//			return 0;
//		}
//
//		for (int i = 0; i < n - 1; i++) {
//			num[i] = num[i + 1];
//			//printf("%d", num[i]);			// p를 지우고,
//		}
//
//		//printf("\n");
//
//		for (int i = 0; i < n - 1; i++) {	// 전체를 다 살펴 보았을 때
//			for (c = 2; c * p < n + 1; c++) {
//				if (num[i] == p * c) {		// 지금 보고 있는 수가 소수의 배수라면
//					order++;
//					if (order == k) {
//						printf("%d", num[i]);
//						return 0;
//					}
//					num[i] = 0;				// 0으로 두고 없앴다고 치기
//				}
//			}
//		}
//	}
//	return 0;
//}

// 지우기 전에 카운트를 올리고, 카운트가 k와 같다면 그 수를 출력하기
// 시간 초과!!!!!!!!!!!!!!!!!!!!!!!!!!!!1


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
		//printf("%d", num[i]);		// 2 3 4 5 6 7 8 9 10  2부터 N까지 모든 정수를 적는다
	}
	p = num[0];		// 안 지운 수 중 가장 작은 수가 소수

	while (p > 0) {		// 아직 모든 수가 지워지지 않았을 경우...

		for (int i = 0; i < n - 1; i++) {
			if (num[i] != 0) {
				p = num[i];
				order++;
				if (order == k) {
					printf("%d", num[i]);
					return 0;
				}
				num[i] = 0;
				break;			// 0이 아닌 수를 발견하면 그 즉시 p에 넣고, num[i]를 0으로 바꿔 놓고(p를 지우고) 반복문 빠져나오기
			}
		}

		for (int i = 0; i < n - 1; i++) {	// 전체를 다 살펴 보았을 때
			for (c = 2; c * p <= n; c++) {
				if (num[i] == p * c) {		// 지금 보고 있는 수가 소수의 배수라면
					order++;
					if (order == k) {
						printf("%d", num[i]);
						return 0;
					}
					num[i] = 0;				// 0으로 두고 없앴다고 치기
				}
			}
		}
	}
	return 0;
}