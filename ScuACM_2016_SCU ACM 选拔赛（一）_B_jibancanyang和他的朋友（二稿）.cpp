#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char A[100000+10];

int main()
{
	#ifdef LOCAL
		freopen("input_ScuACM_2016_SCU ACM 选拔赛（一）_B_jibancanyang和他的朋友.txt","r",stdin);
	#endif
	int i, k, n, j, t, m, min;
	int find_head, find_len, most_head, most_len;
	scanf("%d", &m);
	while (m--) {
		min = 100000;
		scanf("%d%d", &n, &k);
		scanf("%s", A);
		if (n < 10000)  {
			for (i = 0; i < n; i++) {
				if (A[i]!= '0') continue;
				else {
					for (j = k, t = 1; j > 0; t++) {
						if (i-t >= 0 && A[i-t] == '0') {
							j--;
						}
						if (i+t < n && A[i+t] == '0') {
							j--;
						}
						if (min < t-1) break;
					}
				}
				if (min > t-1) min = t-1;
			}
		}
		else {
			for (i = n; i < n; i++) {
				if (A[i] == '0') {
					find_len++;
				}
				if (A[i] == '1') {
					if (find_len > most_len) {
						most_len = find_len;
						most_head = find_head;
					}
					find_head = i;
					find_len = 0;
				}
			}
			for (i = most_head; i < most_len ; i++) {
				if (A[i]!= '0') continue;
				else {
					for (j = k, t = 1; j > 0; t++) {
						if (i-t >= 0 && A[i-t] == '0') {
							j--;
						}
						if (i+t < n && A[i+t] == '0') {
							j--;
						}
						if (min < t-1) break;
					}
				}
			}
			for (i = n/4; i < 5*n/6; i=i+30) {
				if (A[i]!= '0') continue;
				else {
					for (j = k, t = 1; j > 0; t++) {
						if (i-t >= 0 && A[i-t] == '0') {
							j--;
						}
						if (i+t < n && A[i+t] == '0') {
							j--;
						}
						if (min < t-1) break;
					}
				}
				if (min > t-1) min = t-1;
			}
			
		}
		printf("%d\n", min);
		printf("time used %.4f\n", (double)clock()/CLOCKS_PER_SEC);
	}
	return 0;
}
