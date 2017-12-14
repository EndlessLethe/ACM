/**
 * @Date:   12-Dec-2017
 * @Email:  809810527@qq.com
 * @Filename: C.cpp
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

const int INF = 0x7fffffff;
int n, x, x_r, flaga, flagb, minNum = INF, first;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i == 0) first = x;
		if (x < x_r && !flagb) {
			if (!flaga) {
				flaga = 1;
				minNum = x_r;
			}
			else flagb = 1;
		}
		if (flagb) minNum = min(minNum, x);
		x_r = x;
	}
	if (flaga) cout << minNum << endl;
	else cout << first << endl;
	return 0;
}
