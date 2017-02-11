#include <stdio.h>

int main()
{
	double a, b, sum = 0;
	scanf("%lf%lf", &a, &b);
	while(a < b+1) {
		sum += 1 / (a * a);
		a++;
	}
	printf("%.5lf", sum);
	return 0; 
} 
