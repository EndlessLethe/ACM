/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/6/11 10:30:45
File Name     :HDU 1160.cpp
Description   :
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAX = 1010;
struct mouse {
	int w, s, n;
	bool operator < (const mouse& x) {
		return w < x.w;
	}
} m[MAX];
int dp[MAX], max_pos[MAX];
stack <int> res;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int W, S, N = 0, Max_pos, Max, pos;
	while (cin >> W >> S) {
		m[N].w = W;
		m[N].s = S;
		m[N].n = N;
		N++;
	}
	sort(m, m+N);
//	for (int i = 0; i < N; i++) printf("%d ", m[i].w);
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		max_pos[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		Max = -1;
		for (int j = 0; j < N; j++) {
			if (m[i].s < m[j].s && m[i].w > m[j].w && Max < dp[j]) {
				Max = dp[j];
				max_pos[i] = j;
			}
		}
		if (Max == -1) dp[i] = 1;
		else dp[i] = Max + 1;
	}
	Max = -1;
	for (int i = 0; i < N; i++) {
		if (Max < dp[i]) {
			Max = dp[i];
			Max_pos = i;
		}
	}
	cout << Max << endl;
	pos = Max_pos;
	
	while (max_pos[pos] != -1) {
		res.push(m[pos].n+1);
		pos = max_pos[pos];
//		cout << m[pos].w << m[pos].s << endl;
	}
	if (max_pos[pos] == -1) {
		cout << m[pos].n+1 << endl;
//		cout << m[pos].w << m[pos].s << endl;
	}
	while (!res.empty()) {
		cout << res.top() << endl;
		res.pop();
	}
    return 0;
}
