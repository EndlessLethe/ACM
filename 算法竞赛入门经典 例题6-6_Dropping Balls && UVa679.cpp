#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	#ifdef LOCAL
		freopen("test.txt", "r", stdin);
	#endif
	int n, m, i, k;
	long long sum, tree;
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &n, &m);
		sum = 0;
		m--;
		for (i = 1; i < n; i++) {
			sum *= 2; 
			sum += m & 1; 
			sum++;
			m /= 2;
		}
		printf("%lld\n", sum+1);
	} 
	return 0;
} 
