/**
 * @Date:   18-Mar-2017
 * @Email:  809810527@qq.com
 * @Filename: test.cpp
 * @Last modified time: 24-Nov-2017
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

#define MOD 9973

struct mat {
	long long a[10][10];
};

mat input, ans;

int n, k, T;


void init(mat *C) {
	for (int i = 0; i < n; i++)
		for (int j = 0;  j < n; j++)
			C->a[i][j] = 0;
}

void check(mat te) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%I64d ", te.a[i][j]);
		}
		printf("\n");
	}
}

mat mul(mat A, mat B) {
	mat C;
	init(&C);
//	check(C);
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++) {
				C.a[i][j] = (A.a[i][k] * B.a[k][j] + C.a[i][j]) % MOD;
//				printf("%d %d %d: %I64d %I64d %I64d\n", i, k, j, A.a[i][k], B.a[k][j], C.a[i][j]);
			}
//	check(C);
	return C;
}

long long sum() {
	long long res = 0;
	for (int i = 0; i < n; i++) res = (res + ans.a[i][i]) % MOD;
	return res;
}



void fast_pow() {
	for (int i = 0; i < n; i++) ans.a[i][i] = 1;
	while (k > 0) {
		if (k & 1) ans = mul(ans, input);
		input = mul(input, input);
		k >>= 1;
//		check();
	}
	
	printf("%I64d\n", sum());
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		init(&ans);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%I64d", &input.a[i][j]);
				input.a[i][j] = input.a[i][j] % MOD;
			}
		}
		fast_pow();
		
	}
	return 0;
}
