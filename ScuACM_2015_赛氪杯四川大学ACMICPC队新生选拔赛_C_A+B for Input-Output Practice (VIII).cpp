#include <stdio.h>
#include <string.h>



char a[1000000] = {0}, b[1000000] = {0};
int CASE, N;
long long i, j, k, lenth;


int main()
{

	#ifdef LOCAL
	freopen("input_ScuACM_2015_赛氪杯四川大学ACMICPC队新生选拔赛_C_A+B for Input-Output Practice (VIII).txt", "r", stdin);
	#endif
	
	scanf("%d", &CASE);
	for (i = 0; i < CASE; i++) {
		scanf("%d", &N);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (k = 0; k < N; k++) {
			scanf("%s", &b);
			lenth = strlen(b);
			for (j = 0; j < lenth; j++) {
				a[j] = a[j] + b[lenth-j-1] - '0';
				if (a[j] >= 10) {
					a[j] -= 10;
					a[j+1]++;					
				}
				else if (a[j] < 0) {
					a[j] += 10;
					a[j+1]--;
				}
			}		
		}
		
		for (j = 1000000-100; a[j] == 0; j--) {
			;
		}
	
		for (;j >= 0; j--) {
			printf("%d",a[j]);
		}
		
		if (i+1 != CASE) printf("\n\n");
		else printf("\n");
	}
	return 0;
}
