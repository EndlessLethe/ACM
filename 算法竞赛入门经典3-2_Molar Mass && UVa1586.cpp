#include <stdio.h>
#include <ctype.h>
char input[100];

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典3-2_Molar Mass && UVa1586.txt", "r", stdin);
	#endif
	int n, i, j;
	double sum;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", input);
		sum = 0;
		for (j = 0; input[j] != '\0'; j++) {
			if (input[j] == 'C') {
				if (isdigit(input[j+1]) && isdigit(input[j+2])) {
					sum += ((input[j+2] - '0') + 10 * (input[j+1] - '0')) * 12.01;
					j += 2;
				}
				else if(isdigit(input[j+1])) {
					sum += (input[j+1] - '0') * 12.01;
					j += 1;
				}
				else {
					sum += 12.01;
				}
			}
			else if (input[j] == 'N') {
				if (isdigit(input[j+1]) && isdigit(input[j+2])) {
					sum += ((input[j+2] - '0') + 10 * (input[j+1] - '0')) * 14.01;
					j += 2;
				}
				else if(isdigit(input[j+1])) {
					sum += (input[j+1] - '0') * 14.01;
					j += 1;
				}
				else {
					sum += 14.01;
				}
			}
			else if (input[j] == 'O') {
				if (isdigit(input[j+1]) && isdigit(input[j+2])) {
					sum += ((input[j+2] - '0') + 10 * (input[j+1] - '0')) * 16.00;
					j += 2;
				}
				else if(isdigit(input[j+1])) {
					sum += (input[j+1] - '0') * 16.00;
					j += 1;
				}
				else {
					sum += 16.00;
				}
			}
			else if (input[j] == 'H') {
				if (isdigit(input[j+1]) && isdigit(input[j+2])) {
					sum += ((input[j+2] - '0') + 10 * (input[j+1] - '0')) * 1.008;
					j += 2;
				}
				else if(isdigit(input[j+1])) {
					sum += (input[j+1] - '0') * 1.008;
					j += 1;
				}
				else {
					sum += 1.008;
				}
			}
		}
		printf("%.3lf\n", sum);
	}
	return 0;
}
