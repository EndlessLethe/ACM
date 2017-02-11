#include <cstdio>
#include <iostream>
#include<string.h>
#include <stack>
using namespace::std;

int l[100010];
int r[100010];
//对数组链表的理解实在不深刻，地址和l、r几个有些混淆 
int main()
{
    #ifdef LOCAL
	freopen("input_算法竞赛入门经典 例题6-5_Boxes in a Line && UVa12657.txt", "r", stdin);
    #endif
    int n, m, act, x, y, i, cnt, cnt4, point;
    long long sumnum;
	while ((scanf("%d%d", &n, &m)) == 2) {
		for (i = 1; i <= n; i++) {
			l[i] = i-1;
			r[i] = i+1;
		}
		while (m--) {
			scanf("%d", &act);
			if (act == 1) {
				scanf("%d%d", &x, &y);
				r[l[x]] = r[x];
				l[r[x]] = l[x];
				r[l[y]] = x;
				l[x] = l[y];
				l[y] = x;
				r[x] = y;
				
			}
			else if (act == 2) {
				scanf("%d%d", &x, &y);
				r[l[x]] = r[x];
				l[r[x]] = l[x];
				l[r[y]] = x;
				r[x] = r[y];
				r[y] = x;
				r[x] = y; 
			}
			else if (act == 3) {
				scanf("%d%d", &x, &y);
				r[l[x]] = y;
				l[r[x]] = y;
				r[l[y]] = x;
				l[r[y]] = x;
			}
			else if (act == 4) {
				cnt4++;
			}
		}
		if (cnt4 % 2 == 0 || n % 2 == 0) cnt = 1;
		else cnt = 0;
		for (i = 1; l[i] != 0; i++) {
				;
		}
		point = i;
		while (r[point] != n+1) {
			if (cnt % 2 == 0) {
				sumnum += point;
			}
			point = r[point];
			cnt++;
		}
		printf("%lld\n", sumnum);
	}
    
    return 0;
}

