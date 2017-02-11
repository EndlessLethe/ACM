//memset(tt, -1, sizeof(trie)*MAX_N); 

const int MAX = 150010;
const int MAX_N = 32 * MAX;

struct trie {
    int a[2], num;
} tt[MAX_N];

int cnt, ans;

//insert(N, 0, 31) // insert x into the root which id is u, the deep is num
void insert(int x, int u, int len) {  
    int k;
    for (int i = len; i >= 0; i--) {
        k = ((1 << i) & x) ? 1 : 0;
        if (tt[u].a[k] == -1) {
            tt[u].a[k] = ++cnt;
        }
        u = tt[u].a[k];
    }
    tt[u].num = x;
}

void query(int x, int u, int len) {//query(M, 0, 31)
    int k;
    for (int i =len; i >= 0; i--) {
        k = ((1 << i) & x) ? 1 : 0;
        if (tt[u].a[!k] != -1) {
            u = tt[u].a[!k];
        }
        else u = tt[u].a[k];
    }
    ans = max(ans, tt[u].num ^ x);
}
