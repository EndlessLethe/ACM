#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define MAX 100010

int x[MAX];

int main() {
	int n, q, money;
//	freopen("input_2017_ACMÑµÁ·¶þ__D_Interesting drink.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x+n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> money;
		cout << upper_bound(x, x+n, money) - x << endl;
	}
	return 0;
}
