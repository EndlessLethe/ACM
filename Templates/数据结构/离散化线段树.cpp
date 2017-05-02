#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define mid ((l+r)/2)

using namespace std;

#define mid ((l+r)/2)
#define ls (2*k+1)
#define rs (2*k+2)

const int MAX_N = 220000;//LR各有1e5，而离散化时还加了区间左右的两个点 、
const int MAX_Q = 100010; 
vector <int> v;
map <int, int> H1, H2;//程序运算使用H1, 输出结果使用H2 
 
int n;//注意读入不是n 
int dat[2 * MAX_N - 1], mark[2*MAX_N-1];
int comm[MAX_Q], L[MAX_Q], R[MAX_Q];

//当dat有初始值的时候，通过递归建树（还是要先调用init清零） 
int build(int k, int l, int r) {
	if (l == r-1) return dat[k];
	int v1 = build(ls, l, mid);
	int v2 = build(rs, mid, r);
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
void push_down(int k, int l, int r) {//这里只使用了一个mark 
	if (mark[k] == 1) {
		mark[ls] = 1;
		dat[ls] = 0;
		mark[rs] = 1;
		dat[rs] = 0;
		mark[k] = 0;
	}
}

void maintain(int k) {
	dat[k] = dat[ls] + dat[rs];
}

//x=1时为普及基本法 
//把区间[a,b)都修改 mark可同时成为多个标记
void updata(int a, int b, int x, int k, int l, int r) {
	if (r <= a || b <= l) return;
	if (a <= l && r <= b) {//则打标记并修改当前值 
		mark[k] = x;
		if (x == 1) dat[k] = 0;
	}
	else {//有超出[a, b)区间的部分 
		push_down(k, l, r);
		updata(a, b, x, ls, l, mid);//不需要 if (a <= mid)
		updata(a, b, x, rs, mid, r);
		maintain(k);
	}
}

//统计弱智的数量 
int query(int a, int b, int k, int l, int r) {//查询区间 [a,b)
	if (r <= a || b <= l) return 0;//区间不相交 
	if (a <= l && r <= b) return dat[k];//查询区间完全包含当前区间 
	else {
		push_down(k, l, r); 
		int v1 = query(a, b, ls, l, mid);
		int v2 = query(a, b, rs, mid, r);
		maintain(k);
		return v1+v2;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
//        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
    	cin >> comm[i] >> L[i] >> R[i];
    	v.push_back(L[i]); v.push_back(L[i]-1);//左开右闭的线段树MS只需要前后加点就可以了 
    	v.push_back(R[i]); v.push_back(R[i]+1);
	}
	v.push_back(N+1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	init(v.size());
	for (int i = 0; i < v.size(); i++) {
		H1[v[i]] = i; H2[i] = v[i];
		if (i != 0) dat[i+n-2] = H2[i] - H2[i-1];//满足左闭右开 
	}
	build(0, 0, n);
	
	for (int i = 0; i < Q; i++) {
		if (comm[i] == 1) updata(H1[L[i]], H1[R[i]]+1, 1, 0, 0, n);
		else cout << query(H1[L[i]], H1[R[i]]+1, 0, 0, n) << endl;
	}
	
    return 0;
}
