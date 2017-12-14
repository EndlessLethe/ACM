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
 
const int MAXN = 500000+50;
struct M {
    int x; int len;
} x[MAXN];
 
stack <M> ms;
int cnt, n;
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    while (scanf("%d", &n) == 1) {
        cnt = 0;
        while (!ms.empty()) ms.pop();
        for (int i = 0; i < n; i++) {
        	scanf("%d", &x[i].x);
            x[i].len = 1;
            M tmp = x[i];
            while (!ms.empty() && ms.top().x <= x[i].x) {
                if (ms.top().x == x[i].x) {
                    tmp.len = ms.top().len + 1;
                }
                cnt += ms.top().len;
                ms.pop();
            }
            if (!ms.empty()) cnt += ms.top().len;
            ms.push(tmp);
//          printf("i: %d cnt: %d\n", i, cnt);
        }
        printf("%d\n", cnt);
    }
    return 0;
}
