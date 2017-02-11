#include <stdio.h>
#include <stdlib.h>

int main()
{
	double m = 0, n = 0;
	int i = 0;
	double sum = 0;
	scanf("%lf %lf", &n, &m);
	while ( n != 0 || m!= 0) {
		sum = 0;
		i++;
		for (;n <= m; n++) {
			sum += 1.0 / (n * n);
		}
		printf("Case %d: %.5lf\n", i, sum);
		scanf("%lf%lf", &n, &m);
	}
	return 0;
}
