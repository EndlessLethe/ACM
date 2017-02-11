/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/5/12 15:02:40
File Name     :UVa12096 The SetStack Computer.cpp
Description   :使用set来查重合并
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;
stack<int> s;
char in[10];
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int ID (Set x) {
	if (IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() -1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int cases, N;
    scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			memset(in, 0, sizeof(in));
			scanf("%s", in);
			if (in[0] == 'P') {
				s.push(ID(Set()));
			}
			else if (in[0] == 'D') s.push(s.top());
			else {
				Set x1 = Setcache[s.top()];
				s.pop();
				Set x2 = Setcache[s.top()];
				s.pop();
				Set x;
				if (in[0] == 'A') {
					x = x2; x.insert(ID(x1));
				}
				if (in[0] == 'U') set_union (ALL(x1), ALL(x2), INS(x));
				if (in[0] == 'I') set_intersection (ALL(x1), ALL(x2), INS(x));
				s.push(ID(x));
			}
			printf("%d\n", Setcache[s.top()].size());
		}
	}
    return 0;
}
