#include <stdio.h>
#include <string.h>

int temp = 0, CASE, i;
long long sum, start, end, N, j;
int all_zero = 1, all_nagtive = 1, zerosum = 0, min_nagtive = -10000;


int main()
{
	
	#ifdef LOCAL
	freopen("input_ScuACM_2015_赛氪杯四川大学ACMICPC队新生选拔赛_B_Max Sum.txt", "r", stdin);
	#endif
	
	scanf("%d", &CASE);
	for (i = 0; i < CASE; i++) {
		scanf("%d", &N);
		sum = 0;
		start = 1;
		end = 0;
		all_zero = 1, all_nagtive = 1, zerosum = 0;
		if (N == 1) {
			scanf("%d", &temp);
			printf("Case %d\n%d 1 1\n\n", i+1, temp);
			continue;
		} 
		
		for (j = 0; j < N; j++) {
			scanf("%d", &temp);
			if (temp > 0) {
				all_zero = 0, all_nagtive = 0;
			}
			if (temp == 0) all_nagtive = 1;
			zerosum += temp;
			if(min_nagtive < temp && temp < 0) min_nagtive = temp;
			
			
			
			
			if (temp + sum >= 0) {
				if (j+1 == N) {
					if (temp > 0) {
						sum += temp;
						end++;
					}
					else break;
				}
				sum += temp;
				end++;
			}
			else {
				start = end = j;
				sum = 0;
			}
		}
		
		if (zerosum != 0)  all_zero = 0;
		if (all_nagtive) {
			printf("Case %d\n%d 1 1\n\n", i+1, min_nagtive);
			continue;
		}
		else if (all_zero) {
			printf("Case %d\n0 1 1\n\n", i+1);
			continue;
		}
		else {
			printf("Case %d\n", i+1);
			printf("%lld %lld %lld\n\n", sum, start, end);	
		}

	}
	
	
	return 0;
}
