/**
 * @Date:   13-Dec-2017
 * @Email:  809810527@qq.com
 * @Filename: POJ 2796 【单调栈】.cpp
 * @Last modified time: 13-Dec-2017
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
const ll MAXN = 100000+50;
ll ms[MAXN], r;
ll in[MAXN], index;
ll L[MAXN], R[MAXN];

ll n, pos, maxNum, x[MAXN];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	while (scanf("%d", &n) == 1) {
		r = index = pos = maxNum = 0;
		for (ll i = 1; i <= n; i++) {
			scanf("%I64d", &x[i]);
			index++;
			while (r != 0 && ms[r] >= x[i]) {
				R[ms[r]] = index - in[ms[r]] -1;
				r--;
			}
			in[x[i]] = index;
			L[x[i]] = in[x[i]] - in[ms[r]]-1;
			ms[++r] = x[i];
		}
		while (r) {
			R[ms[r]] = index - in[ms[r]];
			r--;
		}
//		for (ll i = 1; i <= n; i++) {
//			printf("i: %d L: %d R: %d l: %d r: %d\n", i, L[i], R[i], in[i]-L[i], in[i]+R[i]);	
//		}
		for (ll i = 1; i <= n; i++) {
			ll tmp = 0;
			for (ll j = in[i]-L[i]; j <= in[i]+R[i]; j++) {
				tmp += x[j];
			}
			if (tmp * i > maxNum) {
				pos = i;
				maxNum = tmp * i;
			}
		}
		printf("%I64d\n", maxNum);
		printf("%I64d %I64d\n", in[pos] - L[pos], in[pos] + R[pos]);
	}
	return 0;
}



