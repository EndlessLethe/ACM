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

const int MAX_N = 220000;//LR����1e5������ɢ��ʱ�������������ҵ������� ��
const int MAX_Q = 100010; 
vector <int> v;
map <int, int> H1, H2;//��������ʹ��H1, ������ʹ��H2 
 
int n;//ע����벻��n 
int dat[2 * MAX_N - 1], mark[2*MAX_N-1];
int comm[MAX_Q], L[MAX_Q], R[MAX_Q];

//��dat�г�ʼֵ��ʱ��ͨ���ݹ齨��������Ҫ�ȵ���init���㣩 
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

void update(int k, int a) {//�����޸� �ѵ�k������Ϊa 
	k += n-1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = dat[2*k+1]+dat[2*k+2];
	}
}

//���裺1.�޸Ķ��ӱ�� 2.�´����޸Ķ������ݣ�3.�޸������� 
void push_down(int k, int l, int r) {//����ֻʹ����һ��mark 
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

//x=1ʱΪ�ռ������� 
//������[a,b)���޸� mark��ͬʱ��Ϊ������
void updata(int a, int b, int x, int k, int l, int r) {
	if (r <= a || b <= l) return;
	if (a <= l && r <= b) {//����ǲ��޸ĵ�ǰֵ 
		mark[k] = x;
		if (x == 1) dat[k] = 0;
	}
	else {//�г���[a, b)����Ĳ��� 
		push_down(k, l, r);
		updata(a, b, x, ls, l, mid);//����Ҫ if (a <= mid)
		updata(a, b, x, rs, mid, r);
		maintain(k);
	}
}

//ͳ�����ǵ����� 
int query(int a, int b, int k, int l, int r) {//��ѯ���� [a,b)
	if (r <= a || b <= l) return 0;//���䲻�ཻ 
	if (a <= l && r <= b) return dat[k];//��ѯ������ȫ������ǰ���� 
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
    	v.push_back(L[i]); v.push_back(L[i]-1);//���ұյ��߶���MSֻ��Ҫǰ��ӵ�Ϳ����� 
    	v.push_back(R[i]); v.push_back(R[i]+1);
	}
	v.push_back(N+1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	init(v.size());
	for (int i = 0; i < v.size(); i++) {
		H1[v[i]] = i; H2[i] = v[i];
		if (i != 0) dat[i+n-2] = H2[i] - H2[i-1];//��������ҿ� 
	}
	build(0, 0, n);
	
	for (int i = 0; i < Q; i++) {
		if (comm[i] == 1) updata(H1[L[i]], H1[R[i]]+1, 1, 0, 0, n);
		else cout << query(H1[L[i]], H1[R[i]]+1, 0, 0, n) << endl;
	}
	
    return 0;
}
