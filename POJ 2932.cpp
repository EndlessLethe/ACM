/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/6/9 20:43:04
File Name     :POJ 2932.cpp
Description   :…®√Ëœﬂ
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
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int N;
const int MAX = 40010;
double x[MAX], y[MAX], r[MAX];

bool inside(int i, int j) {
	double dx = x[i] - x[j], dy = y[i] - y[j];
	return dx * dx + dy * dy <= r[j] * r[j];
}

void solve() {
	
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
    	scanf("%lf%lf%lf", &r[i], &x[i], &y[i]);
	}
//	for (int i = 0; i < N; i++) {
//    	printf("%f%f%f\n", r[i], x[i], y[i]);
//	}
	vector<pair<double, int> > events;
	for (int i = 0; i < N; i++) {
		events.push_back(make_pair(x[i] - r[i], i));
		events.push_back(make_pair(x[i] + r[i], i+N));
	}
	sort(events.begin(), events.end());

	set<pair<double, int> > outers;
	vector <int> res;
	for (int i = 0; i < events.size(); i++) {
		int id = events[i].second % N;
		if (events[i].second < N) {
			set<pair<double, int> >::iterator iter = outers.lower_bound(make_pair(y[id], id));
			if (iter != outers.end() && inside(id, (iter)->second)) continue;
			if (iter != outers.begin() && inside(id, (--iter)->second)) continue;
			res.push_back(id);
			outers.insert(make_pair(y[id], id));
		}
		else {
			outers.erase(make_pair(y[id], id));
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d%c", res[i]+1, i+1==res.size()? '\n':' ');
	}
    return 0;
}
