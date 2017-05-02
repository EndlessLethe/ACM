#define MAX_N 100010
int n, dat[2 * MAX_N - 1];

void init(int n_) {
	n = 1;
	while (n < n_) n *= 2;
	for (int i = 0; i < 2 * n - 1; i++) dat[i] = 0;
}

void update(int k, int a) {
	k += n-1;
	dat[k] += a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = max(dat[2*k+1], dat[2*k+2]);
	}
}

int query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) return 0;
	if (a <= l && r <= b) return dat[k];
	else {
		int v1 = query(a, b, 2*k+1, l, (l+r)/2);
		int v2 = query(a, b, 2*k+2, (l+r)/2, r);
		return max(v1, v2);
	}
}

//
//Ê¾Àý³ÌÐò 
//

/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/4/22 13:14:56
File Name     :A.cpp
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

#define MAX_N 100010
long long n, dat[2 * MAX_N - 1];

void init(long long n_) {
	n = 1;
	while (n < n_) n *= 2;
	for (long long i = 0; i < 2 * n - 1; i++) dat[i] = 0;
}

void update(long long k, long long a) {
	k += n-1;
	dat[k] += a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = max(dat[2*k+1], dat[2*k+2]);
	}
}

long long query(long long a, long long b, long long k, long long l, long long r) {
	if (r <= a || b <= l) return 0;
	if (a <= l && r <= b) return dat[k];
	else {
		long long v1 = query(a, b, 2*k+1, l, (l+r)/2);
		long long v2 = query(a, b, 2*k+2, (l+r)/2, r);
		return max(v1, v2);
	}
}

int main()
{
//    freopen("A.txt","r",stdin);
//	ios_base::sync_with_stdio(0);cin.tie(0);
	long long N, Q, action, a, b;
	cin >> N >> Q;
	init(N);
	for (long long times = 0; times < Q; times++) {
		cin >> action;
		cin >> a >> b;
		if (action == 1) {
			update(a, b);
		}
		else {
			long long temp = query(a, b+1, 0, 0, n);
			cout << temp << endl;
		}
	}
    return 0;
}
