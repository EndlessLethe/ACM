#include <stdio.h>

int main()
{
	double a, b;
	int c;
	scanf("%lf%lf%d", &a, &b, & c);
	printf("%.*lf", c, a / b);
	return 0; 
} 
