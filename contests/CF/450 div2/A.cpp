/**
 * @Date:   12-Dec-2017
 * @Email:  809810527@qq.com
 * @Filename: A.cpp
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

int n, x, y, cntx, cnty;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > 0) cntx++;
		else cnty++;
	}
	if (cntx > 1 && cnty > 1) printf("No");
	else printf("Yes");
	return 0;
}
