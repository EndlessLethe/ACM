#include <bits/stdc++.h>
using namespace::std;

int a[1000+50], b[1000+50];
int n, m, c, p;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%d%d%d", &n, &m, &c);
	int lena = 0, lenb = 0;
	while (scanf("%d", &p) == 1) {
		if (p <= c/2) {
			for (int i = 0; i <= lena; i++) {
				if (a[i] == 0) {
					a[i] = p;
					lena++;
					printf("%d\n", i+1);
					fflush(stdout);
					break;
				}
				if (a[i] > p) {
					a[i] = p;
					printf("%d\n", i+1);
					fflush(stdout);
					break;
				}
			}
		}
		else {
			for (int i = 0; i <= lenb; i++) {
				if (b[i] == 0) {
					b[i] = p;
					lenb++;
					printf("%d\n", n-i);
					fflush(stdout);
					break;
				}
				if (b[i] < p) {
					b[i] = p;
					printf("%d\n", n-i);
					fflush(stdout);
					break;
				}
			}
		}
		if (lena + lenb == n) break;
	}
	return 0;
}
