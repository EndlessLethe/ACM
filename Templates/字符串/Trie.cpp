#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#define MAXN 1000
#define alphaNum 26

struct Trie {
    char ch[MAXN][alphaNum];
    int val[MAXN];
	int sz;
    void init() {
		sz = 1;//节点数or已经存在的最大节点编号+1
		memset(ch[0], 0, sizeof(ch[0]));//ch[0]作为根节点，不储存信息
	}

	void insert(char* x, int v) {
        int c, u = 0;
        for (int i = 0; x[i] != '/0'; i++) {
            c = x[i] - 'a';
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[u][c] = sz;
                val[sz++] = 0;
            }
            u = ch[u][c];
        }
        val[u] = v;
	}

    int find(char* x) {
        int c, u = 0;
        for (int i = 0; x[i] != '/0'; i++) {
            c = x[i] - 'a';
            if (!ch[u][c]) return 0;
            u = ch[u][c];
        }
        return val[u];
    }
};

char s[300010];
char tem[15];

int main(int argc, char const *argv[]) {
    Trie trie;
    while (scanf("%s", s) == 1) {
        trie.init();
        int t;
        scanf("%d", &t);
        while (t--) {
            scanf("%s", tem);
            trie.insert(tem, 1);
            memset(tem, 0, sizeof(tem));
        }
        int len = strlen(s);
        for ()
    }
    return 0;
}
