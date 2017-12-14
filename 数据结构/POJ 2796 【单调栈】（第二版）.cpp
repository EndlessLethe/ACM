#include <bits/stdc++.h>
using namespace::std;

typedef long long ll;
const ll MAXN = 100000+50;
ll ms[MAXN], r;
ll L[MAXN], R[MAXN];
ll n, pos, maxNum, x[MAXN];
ll sum[MAXN];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	while (scanf("%d", &n) == 1) {
		r = pos = 0;
		maxNum = -1;
		for (ll i = 1; i <= n; i++) {
			scanf("%I64d", &x[i]);
			sum[i] = x[i] + sum[i-1];
		}
		for (ll i = 1; i <= n; i++) {
			while (r != 0 && x[ms[r]] >= x[i]) {
				R[ms[r]] = i - ms[r] -1;
				r--;
			}
			L[i] = i - ms[r] - 1;
			ms[++r] = i;
		}
		while (r) {
			R[ms[r]] = n - ms[r];
			r--;
		}
		for (ll i = 1; i <= n; i++) {
			int l = i - L[i], r = i+R[i];
			if ((sum[r] - sum[l-1]) * x[i] > maxNum) {
				maxNum = (sum[r] - sum[l-1]) * x[i];
				pos = i;
			}
		}
		printf("%I64d\n", maxNum);
		printf("%I64d %I64d\n", pos - L[pos], pos + R[pos]);
	}
	return 0;
}
