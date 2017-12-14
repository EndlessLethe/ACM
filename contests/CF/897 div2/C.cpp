#include <bits/stdc++.h>
using namespace::std;

typedef long long ll;
ll len[100000 + 50];
const ll INF = 1000000000000000000 + 50;

string a = "What are you doing while sending \"", b = "\"? Are you busy? Will you send \"", c = "\"?";
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
ll lena = a.length(), lenb = b.length(), lenf = f0.length(), lenc = c.length();

char cal(ll n, ll k) {
//	cout << n << " " << k << endl;
	if (k > len[n]) return '.';
	if (n == 0) return f0[k-1];
	if (k <= lena) return a[k-1];
	
	if (k <= lena + len[n-1]) return cal(n-1, k-lena);
	if (k <= lena + len[n-1] + lenb) return b[k-lena-len[n-1]-1];
	if (k <= lena + len[n-1]*2 + lenb) return cal(n-1, k-lena-len[n-1]-lenb);
	return c[k-lena-len[n-1]*2-lenb-1];
}

ll Q, n, k;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    len[0] = lenf;
    for (ll i = 1; i < 100000 + 50; i++) {
    	if (len[i-1] * 2 < INF) len[i] = len[i-1] * 2 + lena + lenb + lenc;
    	else {
    		len[i] = INF;
		}
	}
	cin >> Q;
	for (ll i = 0; i < Q; i++) {
		cin >> n >> k;
		cout << cal(n, k);
	}
	cout << endl;
	return 0;
}
