#include <bits/stdc++.h>
using namespace::std;

typedef long long ll;
const int MAXN = 500000+50;
struct M {
    ll x; ll len;
} x[MAXN];
 
stack <M> ms;
ll cnt, n;
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    while (scanf("%d", &n) == 1) {
        cnt = 0;
        while (!ms.empty()) ms.pop();
        for (ll i = 0; i < n; i++) {
        	scanf("%d", &x[i].x);
            x[i].len = 1;
            M tmp = x[i];
            while (!ms.empty() && ms.top().x < x[i].x) {
                cnt += ms.top().len;
                ms.pop();
            }

        	if (!ms.empty() && ms.top().x == x[i].x) {
        		cnt += ms.top().len;
           	    tmp.len = ms.top().len + 1;
                ms.pop();
			}
        	if (!ms.empty()) cnt++;

            ms.push(tmp);
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
