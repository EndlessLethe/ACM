#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	#ifdef LOCAL
//	freopen("test1.txt","r",stdin);
	#endif
	int m, n;
	cin >> m >> n;
	printf("%d%d", m, n);
	return 0;
}
