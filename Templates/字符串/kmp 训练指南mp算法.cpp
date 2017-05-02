/**
 * @Date:   27-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: kmp 训练指南mp算法.cpp
 * @Last modified time: 27-Apr-2017
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
char input[505][2005];
int kmp[2005];
int cnt;

void getFail(char *P, int *f) {
	int m = strlen(P);
	f[0] = 0;
	f[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j] ? j+1 : 0;
	}
}

void find(char *T, char *P, int *f) {//T为文本串 P为模板串 文本串为长的串
	int n = strlen(T), m = strlen(P);
	getFail(P, f);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j && P[j] != T[i]) j = f[j];
		if (P[j] == T[i]) j++;
		if (j == m) {
			cnt++;
			// printf("%d\n", i-m+2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        freopen("input_D_Bazinga.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int T, n, ans;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		int ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", input[i]);
			// printf("%s", input[i]);
		}
		for (int i = 0; i < n; i++) {
			cnt = 0;
			for (int j = 0; j < i; j++) {
				find(input[i], input[j], kmp);
			}
			if (cnt != i) ans = i+1;
		}
		if (ans) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}
