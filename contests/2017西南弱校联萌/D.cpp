/**
 * @Date:   29-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: D.cpp
 * @Last modified time: 29-Apr-2017
 * @Copyright: Copr. 2017 EndlessLethe. All rights reserved.
 * @Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stack>
//#include <bits/stdc++.h>
using namespace::std;

long long x,y;
long long exgcd(long long a, long long b, long long& x, long long& y) {
	long long d = a;
	if (b != 0) {
		d = exgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3) {
		if (c == 0) {
			printf("0\n");
			continue;
		}
		if (a == 0) {
			if (b != 0 && c % b == 0) printf("0\n");
			else printf("-1\n");
			continue;
		}
		long long t = exgcd(a, b, x, y);
//		 printf("%d %d %d\n", t, x, y);
		if (c % t == 0) {
			long long tem = c/t;
			x *= tem;
			y *= tem;
			//printf("%d\n", x);
			long long scale = abs(b/t);
			if (scale == 0) {
				printf("%lld\n", x);
				continue;
			}
			//printf("%d\n", scale);
			if (x > 0) {
				while (x >= 0) {
					x -= scale;
				}
				x += scale;
			}
			else {
				while (x < 0) {
					x += scale;
				}
			}
			printf("%lld\n", x);
		}
		else printf("-1\n");
	}
	return 0;
}
