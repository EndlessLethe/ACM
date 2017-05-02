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

char input[100010];
int alpha[30];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int T, n, flag;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", input);
		flag = 0;
		memset(alpha, 0, sizeof(alpha));
		// if (n > 26) flag = 1;
		for (int i = 0; i < n; i++) {
			alpha[input[i]-'a']++;
		}
		for (int i = 0; i < 27; i++) {
			if (alpha[i] > 1) flag = 1;
		}
		if (flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
