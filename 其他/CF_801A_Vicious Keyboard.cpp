/**
 * @Date:   25-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: CF_801A_Vicious Keyboard.cpp
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
map<char, int> mp;
char input[105];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	scanf("%s", input);
	mp['V'] = 0;
	mp['K'] = 0;
	mp[input[0]]++;
	int flag = 0, cnt = 0, I;
	for (int i = 1; input[i] != '\0'; i++) {
		if (input[i-1] != input[i]) {
			mp[input[i]] = 1;
			if (input[i] == 'K') {
				mp[input[i]] = 0;
				mp[input[i-1]]--;
				cnt++;
				//printf("%c %c %d %d\n", input[i-1], input[i], input[i] != input[i-1], i);
			}
			if (mp[input[i-1]] > 1) flag = 1;
		}
		else {
			mp[input[i]]++;
		}
		I = i;
	}
	if (mp[input[I-1]] > 1) flag = 1;
	if (flag) cnt++;
	printf("%d\n", cnt);
	return 0;
}
