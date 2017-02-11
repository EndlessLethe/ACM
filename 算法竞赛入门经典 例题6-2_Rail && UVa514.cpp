#include <cstdio>
#include<string.h>
#include <stack>
using namespace::std;

int input[1005];
//输入输出带不带空格都试了，不知道为什么。。。
//基本上跟书上的一样了。。。 
int main()
{
    #ifdef LOCAL
	freopen("input_算法竞赛入门经典 例题6-2_Rail && UVa514.txt", "r", stdin);
    #endif

    stack<int> s;
    int n, i, j, ok, t, cnt = 0;

    while ((scanf("%d", &n)) == 1 && n ) {
    	if (cnt++ != 0) printf("\n");
        while ((scanf("%d", &input[0])) == 1 && input[0]) {
	    	j = 1;
	    	ok = 1;
	    	t = 0;
	    	while (!s.empty()) s.pop();
			
			for (i = 1; i < n; i++) {
				scanf("%d", &input[i]);
	    	}
	    	i = 0;
			while (i < n) {
//				if(j == input[i]) {
//					j++;
//					i++;
//				}
//				else 
				if (!s.empty() && s.top() == input[i]) {
					s.pop();
					i++;
				}
				else if (j < n+1) s.push(j++);
				else {
					ok = 0;
					break;
				}
	    	}
	    	printf("%s\n", ok ? "YES" : "NO");
		}
//		printf("\n");
    }
    return 0;
}

