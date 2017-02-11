#include <stdio.h>
#include <string.h>
using namespace::std;

char pre_order[100000], in_order[100000], lch[100000], rch[100000];

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典6-3_Tree Recovery && UVa536.txt", "r", stdin);
	#endif
	while (scanf("%s%s", pre_order, in_order) == 2) {
		build(0, n-1, 0, n-1);
		dfs(pre_oder[0], 0);
	}
	
	return 0;
}

int build(L1, R1, L2, R2) {
	if (L1 > R1) return 0;
	int root = pre_order[L1];
	int p = in_order[L2];
	while (in_order != root) p++;
	int cnt = p - L1;
	lch[root] = build(L1, p-1, L2, L2+cnt-1);//肯定需要修改 
	rch[root] = build(p+1, R1, L2+cnt, R2-1)
	return root;
}

void dfs(root) {
	dfs(lch[root]);
	printf()
	dfs(lch[root]);
}
