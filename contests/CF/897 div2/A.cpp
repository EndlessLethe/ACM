#include <bits/stdc++.h>
using namespace::std;

string str, s;
int n, m, x, y;

int main() {
//	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	cin >> n >> m;
	cin >> str;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--, y--;
		cin >> s[0] >> s[1];
		for (int j = x; j <= y; j++) {
			if (str[j] == s[0]) str[j] = s[1];
		}
	}
	cout << str << endl;
	return 0;
}
