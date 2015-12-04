#include <stdio.h>

#define MAX_N 1000+100


#include<iostream>
#include<cstring>
using namespace std;

int a[MAX_N], b[MAX_N], c[MAX_N];
int ch;
int i, j, k, l, m, n, o, p;

//链表要更好一点吧 

int main()
{
	#ifdef LOCAL
	freopen("input_SCU 1003_A x B Problem (Big integer version).txt", "r", stdin);
	#endif
	ch = getchar();
	while (ch >= 48 && ch <= 57) { //(c = getchar()) != '\n'
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		 i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
		for (i = 0; ch != ' '; i++) {
			a[i] = ch - '0';
			ch = getchar();
		}
		ch = getchar();
		for (j = 0; ch != '\n'; j++) {
			b[j] = ch - '0';
			ch = getchar();
		}
		ch = getchar();
		
		for (k = 0; k < i; k++) {
			for (l = 0; l < j; l++) {
					if (a[k] * b[l] / 10 != 0) {
						c[k+l] += a[k] * b[l] / 10;
						c[k+l+1] += a[k] * b[l] % 10;
					}
					else {
						c[k+l+1] += a[k] * b[l];
					}
			}
		}
		
	bool boolnum = true;
	while (boolnum) {
		boolnum = false;
		for (m = i+j-1; m >= 0; m--) {
			if (c[m] / 10 > 0 && c[m] / 10 < 10) {
				c[m-1] += c[m] / 10;
				c[m] %= 10;
			}
			else if (c[m] / 10 >= 10 && c[m] / 10 < 100) {
				c[m-2] += c[m] / 100;
				c[m-1] += (c[m] / 10) % 10;
				c[m] %= 10;
			}
			else if (c[m] / 10 >= 100) {
				c[m-3] += c[m] / 1000;
				c[m-2] += (c[m] / 100) % 10;
				c[m-1] += (c[m] / 10) % 10;
				c[m] %= 10;
			}
			else {
				;
			}
			 
//			//此时从末尾开始进位
//			for (p = m-1; c[m] > 0; c[m] = c[m] / 10, p--) {
//				c[p] += c[m] % 10;
//			} 
		}
			//肿么办，肿么提取中间那一位？ 
			//和直觉一样，的确累计不了多少 
		
		for (n = 0; n < i + j + 5; n++) {
			if (c[n] > 10) {
				boolnum = true;
			}
		}
	}

		
		for (n = 0; c[n] == 0; n++) {
			;
		}
		
		for (; n < i + j; n++) {
			printf("%d", c[n]);
		}
		printf("\n");
	}
}
