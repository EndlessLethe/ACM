/**
 * @Date:   29-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: B.cpp
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

int input[100010];
set<int> s;
vector<int> v;
int mi[15];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	mi[0] = 1; mi[1] = 1;
	for (int i = 1; i < 12; i++) {
		mi[i] = mi[i-1] * i;
		// printf("mi %d %d\n", i, mi[i]);
	}
	// for (int i = 0; i < 12; i++)
	int T, n, flag, end, beg;
	scanf("%d", &T);
	while (T--) {
		// printf("%d", T);
		beg = 0;
		end = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &input[i]);
		}
		s.insert(input[beg]);
		while (end < n) {
			printf("a; %d %d %d %d\n", beg, end, input[beg], input[end]);
			// for (set<int>::iterator it = s.begin(); it != s.end(); it++) printf("s: %d\n", (*it));
			if (s.count(input[end])) {
				s.erase(input[beg]);
				v.push_back(end-beg);
				printf("now %d %d\n", beg, end);
				beg++;
			}
			else {
				s.insert(input[end]);
				end++;
			}
		}
		v.push_back(end-beg);
		long long ans = 0;
		for (int i = 0; i < v.size(); i++) {
			// printf("v[i] :%d\n", v[i]);
			ans += mi[v[i]];
		}
		printf("%lld\n", ans);
		s.clear();
		v.clear();
	}
	return 0;
}
//存在反例1231会导致重合部分呢重复计数
