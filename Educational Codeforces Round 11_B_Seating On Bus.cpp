#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace::std;

int main()
{
	#ifdef LOCAL
		freopen("input_Educational Codeforces Round 11_B_Seating On Bus.txt", "r", stdin);
	#endif
	int n, m;
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i < n+1; i++) {
		if (2 * n + 2 * i -1 <= m) printf("%d ", 2 * n + 2 * i -1);
		if (2 * i -1 <= m) printf("%d ", 2 * i -1);
		if (2 * n + 2 * i <= m) printf("%d ", 2 * n + 2 * i);
		if (2 * i <= m) printf("%d ", 2 * i );
	}
	return 0;
}

