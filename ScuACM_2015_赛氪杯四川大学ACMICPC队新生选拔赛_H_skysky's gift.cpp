#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long a[100000+10], b[100000+10];
long long T, i, N, M, j, len, temp, token, sum;


int compDec(const void *a, const void *b)
{
	return *(long long*)b-*(long long*)a;
}

int main()
{
	
	
	#ifdef LOCAL
	freopen("input_ScuACM_2015_赛氪杯四川大学ACMICPC队新生选拔赛_H_skysky's gift.txt", "r", stdin);
	#endif
	
	
	scanf("%lld", &T);
	for (i = 0; i < T; i++) {
		scanf("%lld%lld", &N, &M);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		sum = 0;
		
		for (j = 0; j < N; j++) {
			scanf("%lld", &a[j]);

		}
		for (j = 0; j < M; j++) {
			scanf("%lld", &b[j]);

		}
		
		len = 0, temp = 0;
		len = sizeof(a) / sizeof(a[0]);   
		qsort(a, len, sizeof(a[0]), compDec);
			
		len = 0, temp = 0;
		len = sizeof(b) / sizeof(b[0]);   
		qsort(b, len, sizeof(b[0]), compDec); 
//		
//		for (j = 0; j < M; j++) {
//			printf("b[j]=%d\n", b[j]);
//		}
//
//		for (j = 0; j < N; j++) {
//			printf("a[j]=%d\n", a[j]);
//		}



		
		for (j = 0, token = 0; j < M && token < N; j++) {
			while (b[j] < a[token]) {

				token++;
			}
			if (b[j] >= a[token]) {
				sum++;
//				printf("now b[j]=%d, a[token]=%d\n", b[j], a[token]);
//				printf("j=%d token=%d", j, token);
//				printf("bbbbbbbbbbbb%d\n", sum);
				token++;
			}

		}
		printf("%lld", sum);
		if (i+1 != T) printf("\n");
	}

	return 0;
}
