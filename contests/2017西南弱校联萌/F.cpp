/**
 * @Date:   29-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: F.cpp
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
const double EPS = 1e-3;
double input[1000010];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int T, m, n;
	double d;
	scanf("%d", &T);
	while (T--) {
		int cnt = 0;
		scanf("%d%d%lf", &n, &m, &d);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &input[i]);
			// printf("%lf\n", input[i]);
		}
		double pos = input[0]-d/2;
		for (int i = 0; i < n; i++) {
			if (input[i]-d/2+EPS > pos) {
				pos = input[i] + d/2;
				cnt++;
			}
		}
		if (cnt == m) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
