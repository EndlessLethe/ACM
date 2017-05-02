/**
 * @Date:   27-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: D_Bazinga.cpp
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

void BuildNext(char* P, int* next) {
	int length = strlen(P);
	int i, t;
	i = 1;
	t = 0;
	next[1] = 0;
	while(i < length + 1) {
		while(t > 0 && P[i - 1] != P[t - 1]) t = next[t];
		++t;
		++i;
		if(P[i - 1] == P[t - 1]) next[i] = next[t];
		else next[i] = t;
	}
	//P末尾的结束符控制，用于寻找目标字符串中的所有匹配结果用
	while(t > 0 && P[i - 1] != P[t - 1]) t = next[t];
	++t;
	++i;
	next[i] = t;
}

int find(char* T, char* P, int* matches) {
	int T_length = strlen(T), P_length = strlen(P);
	int i, j, n;
	int next[P_length + 2];
	BuildNext(P, next);
	i = 0;
	j = 1;
	n = 0;
	while(P_length + 1 - j <= T_length - i) {
		if(T[i] == P[j - 1]) {
			++i;
			++j;
			//发现匹配结果，将匹配子串的位置，加入结果
			if(j == P_length + 1) {
				matches[n++] = i - P_length;
				j = next[j];
			}
		}
		else {
			j = next[j];
			if(j == 0) {
				++i;
				++j;
			}
		}
	}
	return n;//返回发现的匹配数
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        freopen("input_D_Bazinga.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int T, N, ans;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		int ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", input[i]);
			// printf("%s", input[i]);
		}
		for (int i = 0; i < N; i++) {
			cnt = 0;
			for (int j = 0; j < i; j++) {
				find(input[i], input[j], kmp);
				printf("%d %d:", i, j);
				for (int i = 0; i < 10; i++) printf("%d", kmp[i]);
				printf("\n");
			}
			if (cnt != i) ans = i+1;
		}
		// if (ans) printf("%d\n", ans);
		// else printf("-1\n");

	}
	return 0;
}
