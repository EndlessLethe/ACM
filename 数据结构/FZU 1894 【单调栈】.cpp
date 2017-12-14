#include <bits/stdc++.h>
using namespace::std;

const int MAXN = 1000000 + 50;
int mq[MAXN], q[MAXN];

int T, x, index, front, r, l;
char input[10];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	scanf("%d", &T);
	while (T--) {
		index = front = r = l = 0;
		scanf("%s", input);
		while (scanf("%s", input) == 1) {
			if (input[0] == 'E') break;
			if (input[0] == 'C') {
				scanf("%s%d", input, &x);
				while (l != r && mq[r] <= x) r--;
				mq[++r] = x;
				q[r] = ++index;
			}
			else if (input[0] == 'Q') {
				if (l != r) printf("%d\n", mq[l+1]);
				else printf("-1\n");
			}
			else if (input[0] == 'G') {
				if (front < index) front++;
				if (l != r && front == q[l+1]) l++;
			}

		}
	}
	return 0;
}
