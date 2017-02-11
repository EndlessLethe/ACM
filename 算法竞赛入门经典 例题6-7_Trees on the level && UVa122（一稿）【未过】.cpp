#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace::std;

char A[10];
int tree[300];
int output[300];
queue<int> s;

int main()
{
	#ifdef LOCAL
		freopen("test1.txt", "r", stdin);
	#endif
	bool is_broken, is_entered = true;
	int m, cur, i, temp;
	while (is_entered == true) {
		is_entered = false;
		is_broken = false;
		tree[1] = -1;
		while (scanf("(%d,%[^)]", &m, A) && m) {
			getchar();
			getchar();
			is_entered = true;
			cur = 1;
			for (i = 0; A[i] != '\0'; i++) {
				if (A[i] == 'L') {
					cur *= 2;
				}
				else if (A[i] == 'R') { 
					cur = 2 * cur + 1;
				}
			}
			memset(A, 0, sizeof(A));
			tree[cur] = m;
		}
		
		s.push(1);
		while (!s.empty()) {
			temp = s.front();
			s.pop();
			if (tree[temp] != 0) {
				s.push(2 * temp);
				s.push(2 * temp + 1);
				output[temp] = tree[temp];
				tree[temp] = 0; 
			}
		} 
		for (i = 0; i < 300; i++) {
			if (tree[i] != 0) {
				printf("-1");
				is_broken = 1;
				break;
			}
		}
		if (is_broken == 1) {
			;
		}
		else {
			for (i = 0; i < 300; i++) {
				if (output[i] != 0) printf("%d ", output[i]);
			}
		}
		printf("\n"); 
		memset(A, 0, sizeof(A));
		memset(tree, 0, sizeof(tree));
		memset(output, 0, sizeof(output));
		
	}
	return 0;
} 
