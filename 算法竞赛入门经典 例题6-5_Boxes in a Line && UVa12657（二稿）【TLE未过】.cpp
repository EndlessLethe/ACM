#include <cstdio>
#include <iostream>
#include<string.h>
#include <stack>
using namespace::std;

int l[100010];
int r[100010];

//可能需要link优化 

int main()
{
    #ifdef LOCAL
	freopen("input_算法竞赛入门经典 例题6-5_Boxes in a Line && UVa12657.txt", "r", stdin);
    #endif
    int n, m, act, x, y, i, cnt, cnt4, point, temp, testcase = 0;
    long long sumnum;
	while ((scanf("%d%d", &n, &m)) == 2 && n && m) {
		testcase ++;
		for (i = 1; i <= n; i++) {
			l[i] = i-1;
			r[i] = i+1;
		}
		cnt4 = 0;
		sumnum = 0;
		while (m--) {
			scanf("%d", &act);
			if (act == 1) {
				scanf("%d%d", &x, &y);
				l[r[x]] = l[x];
				r[l[x]] = r[x];
				r[x] = y;
				l[x] = l[y];
				r[l[y]] = x;
				l[y] = x;
			}
			else if (act == 2) {
				scanf("%d%d", &x, &y);
				r[l[x]] = r[x];
				l[r[x]] = l[x];
				r[x] = r[y];
				l[x] = y;
				l[r[y]] = x;
				r[y] = x;
			}
			else if (act == 3) {
				scanf("%d%d", &x, &y);
				r[l[x]] = y;
				l[r[x]] = y;
				
				r[l[y]] = x;
				l[r[y]] = x;
				
				temp = r[x];
				r[x] = r[y];
				r[y] = temp;
				
				temp = l[x];
				l[x] = l[y];
				l[y] = temp;
			}
			else if (act == 4) {
				cnt4++;
			}
		}
		if (cnt4 % 2 == 0 || n % 2) cnt = 0;
		else cnt = 1;
		for (i = 1; l[i] != 0; i++) {
				;
		}
		point = i;
		while (point < n+1) {
			if (cnt % 2 == 0) {
				sumnum += point;
			}
			point = r[point];
			cnt++;
		}
		printf("Case %d: %lld\n", testcase, sumnum);
	}
    
    return 0;
}

