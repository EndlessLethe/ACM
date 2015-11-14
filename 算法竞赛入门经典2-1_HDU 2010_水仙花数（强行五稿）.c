#include <stdio.h>
#include <stdlib.h>
 

int main()
{
int n = 0, m = 0;
while (scanf("%d%d", &n, &m) != EOF){
	if (n > 407) {
		printf("no\n");
	}

	else if (n >  371) {
		if (m > 407) {
			printf("407\n");
		}
		else if (m > 371) {
			printf("no\n");
		}
	}
	else if (n ==  371) {
		if (m > 407) {
			printf("371 407\n");
		}
		else if (m > 371) {
			printf("371\n");
		}
		else if (m == 370) {
			printf("");
		}
		else if (m > 153) {
			printf("");
		}
	}
	else if (n == 370) {
		if (m > 407) {
			printf("");
		}
		else if (m > 371) {
			printf("");
		}
		else if (m == 370) {
			printf("");
		}
		else if (m > 153) {
			printf("");
		}
	}
	else if (n >= 153 ) {
		if (m > 407) {
			printf("");
		}
		else if (m > 371) {
			printf("");
		}
		else if (m == 370) {
			printf("");
		}
		else if (m > 153) {
			printf("");
		}
	}
	else {
		if (m > 407) {
			printf("");
		}
		else if (m > 371) {
			printf("");
		}
		else if (m == 370) {
			printf("");
		}
		else if (m > 153) {
			printf("");
		}
	}
		

return 0;
}

