#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#define MAXN 10010;
using namespace std;
struct matrix {
	int a, b, c, d;
	bool operator < (const matrix v) const {
		return (a < v.a) || (a == v.a && c < v.c);
	}
};
vector <matrix> M;
priority_queue <pair<int, int> > q;
set <int> s;
typedef pair<int, int> P;

int main() {
	int N, a, b, c, d;
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		M.push_back(matrix{a, b, c, d});
		//M[i].id = i;
		q.push(P(a, i));
		q.push(P(c, i));
	}
	int pos;
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		while (!s.empty){//对每个当前序列里的矩形，计算重叠线段长len 
			for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
				
			}
		}
		if (!s.count(temp.second)) s.insert(temp.second);
		else s.erase(temp.second);
		cnt += (temp.first - pos) * len;
		pos = temp.first;
	}
//	sort(M.begin(), M.end());
//	for (vector<matrix>::iterator it = M.begin(); it != M.end(); it++) {
//		printf("%d", (*it).a);
//	}
	
	
	//printf("%d\n", cnt);
	return 0;
}
