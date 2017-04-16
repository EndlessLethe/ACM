#include <stdio.h>
#include <set>
using namespace std;
#define MAX 1010

int N;
int pa[MAX];
set <int> s;

int findSet (int x) {
	return pa[x] != x ? pa[x] = findSet(pa[x]) : x;
}
//pa[y] = x; //unite过程 
//以上是两行并查集 

int main() {
//	freopen("input_2017_ACM训练二__C_How Many Tables.txt", "r", stdin);
	int T, cnt, M, a, b;
	scanf("%d", &T);
	while (T--) {
		cnt = 0;
		s.clear();
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {pa[i] = i;}
		for (int i = 0; i < M; i++) {
			scanf("%d%d", &a, &b);
			if (findSet(a-1) != findSet(b-1)) pa[findSet(a-1)] = findSet(b-1);
		}
		for (int i = 0; i < N; i++) {
			if (!s.count(findSet(i))) {
				s.insert(findSet(i));
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
