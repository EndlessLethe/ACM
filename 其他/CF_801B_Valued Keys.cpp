/**
 * @Date:   25-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: CF_801B_Valued Keys.cpp
 * @Last modified time: 25-Apr-2017
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
char a[105], b[105], out[105];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    bool flag = 0;
	scanf("%s%s", a, b);
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] < b[i]) flag = 1;
		else out[i] = b[i];
	}
	if (flag) {
		printf("-1\n");
		flag = 0;
		return 0;
	}
	for (int i = 0; a[i] != '\0'; i++) {
		printf("%c", out[i]);
	}
	printf("\n");
	return 0;
}
