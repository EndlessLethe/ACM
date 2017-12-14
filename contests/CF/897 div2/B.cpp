#include <bits/stdc++.h>
using namespace::std;

typedef long long ll;
long long a[100000 + 50] = {0}, res[100000 + 50] = {0};
int tmp[10];
int k, p;

long long cal(int x) {
	long long res = 0;
	for (int i = 0; i < 10; i++) tmp[i] = 0;
	int zz = x, len = 0;
	long long tenp = 1;
	while (zz != 0) {
		tmp[len] = zz % 10;
		zz /= 10;
		len++;
	}
	for (int i = 0; i < len; i++) {
		res  += tenp * tmp[len-1-i];
		tenp *= 10;
	}
	res += tenp * x;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	cin >> k >> p;
	res[0] = 0;
	for (int i = 1; i <= k; i++) {
		res[i] = (res[i-1] + cal(i)) % p;
	 }
	cout << res[k] << endl;
	return 0;
}
