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
int gcd(int a, int b)
{return b==0?a:gcd(b,a%b);}

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
	int a, b, c, q, w, e, r;
	scanf("%d%d%d%d", &q, &w, &e, &r);
//		if (a == c) {
//			if ((d-b)%a == 0) printf("%d\n", max(b, d));
//			else printf("-1\n");
//			continue;
//		}
	a = q, b = -e, c = r-q;
	int t = exgcd(a, b, x, y);
	printf("%d %d %d\n", t, x, y);
	a /= t;
	b /= t;
	c /= t;
	exgcd(a, b,x,y);
	x=((c*x)%b+b)%b;
    if(!x)x+=b;
    printf("%d\n",x);
	return 0;
}
