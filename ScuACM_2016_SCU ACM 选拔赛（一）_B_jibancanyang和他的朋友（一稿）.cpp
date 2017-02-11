#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;
char A[100000+10];
queue <int> q;

int main()
{
	#ifdef LOCAL
		freopen("test1.txt","r",stdin);
	#endif
	int i, k, n, j, t, m, end, head, min;
	int find_head, find_len, most_head, most_len;
	scanf("%d", &m);
	while (m--) {
		min = 30000;
		scanf("%d%d", &n, &k);
		scanf("%s", A);
		find_head = 0;
		find_len = 0;
		most_head = 0;
		most_len = 0;
		for (i = n/3; i < n; i++) {
			if (A[i] == '0') {
				find_len++;
			}
			if (find_len > k) {
				q.push(find_head);
				q.push(j);
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
		for (i = most_head; i < most_len; i++) {
			if (A[i]!= '0') continue;
			else {
				head = i-1;
				end = i+1;
				for (j = k, t = 1; j > 0; t++) {
					if (min < t-1) break;
					if (i-t >= 0) {
						if (A[i-t] == '0') j--;
					}
					if (i+t < n) {
						if (A[i+t] == '0') j--;
					}
				}
			}
			if (min > t-1) min = t-1;
		}
		for (i = 0; i < n; i++) {
			if (A[i]!= '0') continue;
			else {
				head = i-1;
				end = i+1;
				for (j = k, t = 1; j > 0; t++) {
					if (min < t-1) break;
					if (i-t >= 0) {
						if (A[i-t] == '0') j--;
					}
					if (i+t < n) {
						if (A[i+t] == '0') j--;
					}
				}
			}
			if (min > t-1) min = t-1;
		}
		printf("%d\n", min);
		printf("time used %.2f\n", (double)clock()/CLOCKS_PER_SEC);
	}
	return 0;
}
