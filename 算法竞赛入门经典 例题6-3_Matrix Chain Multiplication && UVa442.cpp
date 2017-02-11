#include <cstdio>
#include <iostream>
#include<string.h>
#include <stack>
using namespace::std;

struct Matrix {
	int l, r;
} m[30];

stack<Matrix> s;
char cmd[100];
long long res;
//读入数据学一下 
int main()
{
    #ifdef LOCAL
	freopen("input_算法竞赛入门经典 例题6-3_Matrix Chain Multiplication && UVa442.txt", "r", stdin);
    #endif
    int n, i, j, ok, t, cnt = 0;
	struct Matrix temp, temp1, temp2;

	scanf("%d", &n);
    for (i = 0; i < n; i++) {
    	string name;
		cin >> name;
		int k = name[0] - 'A';
    	scanf("%d%d", &m[k].l, &m[k].r);
	} 
	
    for (;;) {
    	j = 0;
    	ok = 1;
    	res = 0;
    	while (!s.empty()) s.pop();
		if (scanf("%s", cmd) != 1) break;
    	while (cmd[j] != '\0') {
    		if (cmd[j] != ')') {
    			if (cmd[j] == '(') j++;
				else {
					s.push(m[cmd[j]-'A']);
					j++;
				}
			}
			if (cmd[j] == ')') {
				temp1 = s.top();
				s.pop();
				temp2 = s.top();
				s.pop();
				if (temp1.l == temp2.r) {
					temp.l = temp2.l;
					temp.r = temp1.r;
					res += temp1.l * temp2.l * temp1.r;
					s.push(temp);
				}
				else {
					ok = 0;
					break;
				}
				j++;
			}
		}
		if (ok == 1) printf("%lld\n", res);
		else (printf("error\n"));
	}
    
    return 0;
}

