/**
 * @Date:   12-Dec-2017
 * @Email:  809810527@qq.com
 * @Filename: B.cpp
 * @Last modified time: 12-Dec-2017
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

typedef long long ll;
long long gcd(long long a,long long b) {
    return b == 0  ? a : gcd(b, a%b);
}
const ll INF = 0x7fffffff;
ll a, b, c, g;

ll cal() {
	ll pos = 0, now = INF;
	while (true) {
		if (now == c) return pos;
		now = a / b;
		a %= b;
		a *= 10;
		pos++;
//		cout << a << " " << b << " " << now << endl; 
		if (pos > 100000) return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	cin >> a >> b >> c;
	g = gcd(a, b);
	a /= g;
	b /= g;
	a *= 10;
	cout << cal() << endl;
	return 0;
}
