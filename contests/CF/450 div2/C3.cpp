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
int n, x[100000+50], flaga, flagb, minNum = INF;

int cal(int a, int b) {
	int resa = 0, resb = 0;
	for (int i = 1; i < n; i++) {
		if (i == a) {
			
		}
		if (x[i] < x[i+1])
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i < n; i++) {
		if (x[i] < x[i-1] && !flagb) {
			if (!flaga) {
				flaga = 1;
				minNum = cal(i-1, i);
			}
			else flagb = 1;
		}
		if (flagb) minNum = min(minNum, x[i]); 
	}
	if (flaga) cout << minNum << endl;
	else cout << x[0] << endl;
	return 0;
}
//5
//5 1 2 3 4 
//
//5
//5 1 2 4 3
//
//5
//1 2 4 3 5
//
//5
//1 3 4 2 5
//
//7
//1 5 2 3 4 6 7
