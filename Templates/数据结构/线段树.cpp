
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1

const int maxn = 1e5 + 7;


int sum[maxn<<2];
int col[maxn<<2];

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown(int rt)
{
    if (col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = 0;
        sum[rt<<1|1] = 0;
        col[rt] = 0;
    }
}

// 注意建树的方式  根节点为1 
void build(int l, int r, int rt) {
    col[rt] = 0;
    sum[rt] = 0;
    if (l == r) {
        sum[rt] = H2[l+1] - H2[l];
	//    	cout << rt << " " << l  << endl;
    }
    else {
    	int mid = (l + r) >> 1;
	    build(lson);
	    build(rson);
	    PushUp(rt);
	} 
}

//更新区间[a,b] //update(a, b, x, 1, N, 1);
void update(int a, int b, int val, int l, int r, int rt) {
    if (a <= l && r <= b)
    {
        col[rt] = 1;
        sum[rt] = 0;
        return ;
    }
    PushDown(rt);
    int mid = (l + r) >> 1;
    if (a <= mid) update(a, b, val, lson);
    if (b > mid) update(a, b, val, rson);
    PushUp(rt);
}

//查询区间[a,b] //query(a, b, 1, N, 1)
int query(int a, int b, int l, int r, int rt) {
    if (a <= l && r <= b)
    {
        return sum[rt];
    }
    PushDown(rt);
    int mid = (l + r) >> 1;
    int ans = 0;
    if (a <= mid) ans += query(a, b, lson);
    if (b > mid) ans += query(a, b, rson);
    PushUp(rt);
    return ans;
}

