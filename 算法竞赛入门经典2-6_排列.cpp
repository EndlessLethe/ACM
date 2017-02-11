#include <stdio.h>
#include <stdlib.h>

int used[10] = {0};
int all_usedint (int i);

int main()
{
	int i = 0, m = 0; 
	for (i = 100; i < 334; i ++) {
		for(m = 0; m < 10; m++) {
			used[m] = 0;
		} 
		if(3 * i < 1000 && all_used(i)) {
			printf("%d %d %d\n", i, 2*i, 3*i);
		}
	}
	return 0; 
}

#其实可以看sum和乘积 

int all_used(i2)
{
	int flag = 1;
	int j;
	int b = 2 * i2, c = 3 * i2;
	while (i2 > 0) {
		used[i2%10] = 1;
		used[b%10] = 1;
		used[c%10] = 1;
		i2 /= 10;
		b /= 10;
		c /= 10;
	}
	
	for (j = 1; j < 10; j++) {
		if (used[j] == 0) {
			flag = 0;
		}
	}
	return flag;
}
