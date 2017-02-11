

#include <stdio.h>
#define MID ((l+r)>>1)
const int MAX_N = 820000;

int n;//注意读入不是n 
int dat[2 * MAX_N - 1], mark[2*MAX_N-1];

//当dat有初始值的时候，通过递归建树（还是要先调用init清零） 
int get(int k, int l, int r) {
	if (l == r-1) return dat[k];
	int v1 = get(2*k+1, l, MID);
	int v2 = get(2*k+2, MID, r);
	return (dat[k] = v1 + v2);
}


void init(int n_) {
	n = 1;
	while (n < n_) n *= 2;
	for (int i = 0; i < 2 * n - 1; i++) {
		dat[i] = 0;
		mark[i] = 0;
	}
}

void update(int k, int a) {//单点修改 把第k个更新为a 
	k += n-1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = dat[2*k+1]+dat[2*k+2];
	}
}

//步骤：1.修改儿子标记 2.下传（修改儿子数据）3.修改自身标记 
void push_down(int k, int l, int r) {
	if (mark[k] == 1) {
		mark[2*k+1] = 1;
		dat[2*k+1] = MID-l;
		mark[2*k+2] = 1;
		dat[2*k+2] = r-MID;
		mark[k] = 0;
	}
	else if (mark[k] == -1) {
		mark[2*k+1] = -1;
		dat[2*k+1] = 0;
		mark[2*k+2] = -1;
		dat[2*k+2] = 0;
		mark[k] = 0;
	}
}

void maintain(int k) {
	dat[k] = dat[2*k+1] + dat[2*k+2];
}

//全空0 x=-1or全满0 x = 1 
//把区间[a,b)都修改 mark可同时成为多个标记
void updata(int a, int b, int x, int k, int l, int r) { 
	if (r <= a || b <= l) return;
	if (a <= l && r <= b) {//则打标记并修改当前值 
		mark[k] = x;
		if (x == -1) dat[k] = 0;
		else dat[k] = r-l;//区间长度为r-l，因为区间是左闭右开的 
	}
	else {//这里肯定不是叶节点 
		push_down(k, l, r);
		updata(a, b, x, 2*k+1, l, MID);//不需要 if (a <= MID)
		updata(a, b, x, 2*k+2, MID, r);
		maintain(k);
	}
}

int query(int a, int b, int k, int l, int r) {//查询区间 [a,b)的0的个数 
	if (r <= a || b <= l) return 0;//区间不相交 
	if (a <= l && r <= b) return dat[k];//查询区间完全包含当前区间 
	else {
		push_down(k, l, r); 
		int v1 = query(a, b, 2*k+1, l, MID);
		int v2 = query(a, b, 2*k+2, MID, r);
		maintain(k);
		return v1+v2;
	}
}

//查询在[a,b)区间内dat为x的位置，返回在0~n-1的下标  //dat为满足区间减法的东西 eg:sum\rank 
int find(int a, int b, int x, int k, int l, int r) {
	if (r == l+1) return l;
	else {
		push_down(k, l, r);
		int pos;
		if (b < MID) pos = find(a, b, x, 2*k+1, l, MID);
		else if (a > MID) pos = find(a, b, 2*k+2, x, MID, r);
		else {
			if (dat[2*k+1] >= x) pos = find(a, b, x, 2*k+1, l, MID);
			else pos = find(a, b, x-dat[2*k+1], 2*k+2, MID, r);
		}
		maintain(k);
		return pos;
	}	
}

//			for (int i = 0; i < 2 * n; i++) cout << dat[i] << " " << endl;
