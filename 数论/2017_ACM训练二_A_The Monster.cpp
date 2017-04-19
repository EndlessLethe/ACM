/**
 * @Author: EndlessLethe
 * @Date:   14-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: 2017_ACM训练二_A_The Monster.cpp
 * @Last modified by: EndlessLethe
 * @Last modified time: 14-Apr-2017
 * @Copyright: ©2017 EndlessLethe. All rights reserved.
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

int x,y;
int exgcd(int a, int b, int& x, int& y) {
	int d = a;
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
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4) {
//		if (a == c) {
//			if ((d-b)%a == 0) printf("%d\n", max(b, d));
//			else printf("-1\n");
//			continue;
//		}
		int t = exgcd(a, -c, x, y);
		printf("%d %d %d\n", t, x, y);
		if ((d-b) % t == 0) {
			int tem = (d-b)/t;
			x *= tem;
			y *= tem;
			//printf("%d\n", x);
			int scale = abs(-c/t);
			//printf("%d\n", scale);
			if (x > 0) {
				while (x > 0) {
					x -= scale;
				}
				x += scale;
			}
			else {
				while (x < 0 && y >= 0) {
					x += scale;
				}
			}
			printf("%d\n", a*x+b);
		}
		else printf("-1\n");
	}
	return 0;
}
