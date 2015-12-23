/** *
 *Created by JYZ.
 *2015-12-18.
 ***/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define sa(n) scanf("%d", &(n))
int a[100007], b[100007];

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, m;
        sa(n),sa(m);
        rep (i, 0, n) sa(a[i]);
        rep (i, 0, m) sa(b[i]);
        sort(a, a + n);
        sort(b, b + m);
        int last = n - 1, ans = 0;
        for (int i = m - 1; i >= 0; i--, last--) {
            while (b[i] < a[last] && last > 0) last--;
            if (b[i] >= a[last]) ans++;
            if (!last) break;
        }
        cout << ans << endl;
        
    }
    return 0;
}

