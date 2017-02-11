#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	return a>b?a:b;
}

char A[100010];
int max_position[100010], sum[100010];

int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);
//	#ifdef LOCAL
		freopen("in.txt","r", stdin);
		freopen("b.out","w", stdout);
//	#endif
	int cases;
	scanf("%d", &cases);
	for (int u = 1; u < cases+1; u++) {
		scanf("%s", A);
		int pre = A[0] - '0', cnt = 1, max1= 0;
		int min1 = 1<<17, k = 0, s = 0, i = 0,  all_max = -1, mark = -1;
		long long sum_num = 0;
		bool is_bound = 0;
		for (i = 1; A[i] != '\0'; i++) {
			if (pre != A[i] - '0') {
				pre = A[i] - '0';
				sum[s++] = cnt;
				cnt = 1;
			}
			else cnt++;
		}
		sum[s++] = cnt; 
		//预处理一下 
		int j = 0;
		for (j = 0; j < s; j++) {
			if (j-1 >= 0 && j+1 < s && sum[j] == 1) {
				if (max1 < sum[j] + sum[j-1] + sum[j+1]) {
					max1 = sum[j] + sum[j-1] + sum[j+1];
					is_bound = 1;
					memset(max_position, 0, sizeof(max_position));
					k = 0;
					max_position[k++] = j;
				}
				else if (max1 == sum[j] + sum[j-1] + sum[j+1] && is_bound == 1) {
					if (max(sum[max_position[0]-1], sum[max_position[0]+1]) > 
					    max(sum[j-1], sum[j+1])) {
						max_position[0] = j;
						continue;
					}
				}
			}//不可能与后面的情况同时发生 
			if (max1 < sum[j]) {
				max1 = sum[j];
				mark = sum[j];
				is_bound = 0;
				memset(max_position, 0, sizeof(max_position));
				k = 0;
				max_position[k++] = j;
				continue;
			}
			if (max1 == sum[j]) {
				if (is_bound == 1) continue; 
				max_position[k++] = j;
			}//如果bound之后的值等于最长子序列，那么肯定取这个最长子序列 //错了，还是取bound 
			//如果bound之后的值比最长子序列大（大1），那么肯定取这个bound 
		}
		if (is_bound) {
			sum[max_position[0]-1] += sum[max_position[0]] + sum[max_position[0]+1];
			sum[max_position[0]] = 0;
			sum[max_position[0]+1] = 0;
		}
		else {
			for (j = 0; j < k; j++) {
				if (max_position[j]-1 >= 0) {//判断边界 
					if (sum[max_position[j]-1] < min1) {
						min1 = sum[max_position[j]-1];
						all_max = max_position[j];
						mark = max_position[j]-1;
					}//这种情况肯定前后不会有1 
				}
				if (max_position[j]+1 < s) {
					if (sum[max_position[j]+1] < min1) {
						min1 = sum[max_position[j]+1];
						all_max = max_position[j];
						mark = max_position[j]+1;
					}
				}
			}
			if (all_max >= 0 && mark >=0) {
				sum[all_max]++;
				sum[mark]--;
			}
		}
		sum_num = 0;
		for (int j = 0; j < s+1; j++) {
			sum_num += sum[j] * sum[j];
		}
		printf("Case #%d: ", u);
		printf("%I64d\n", sum_num);
		memset(max_position, 0, sizeof(max_position));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
}
