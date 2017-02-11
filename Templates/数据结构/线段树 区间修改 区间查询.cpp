

#include <stdio.h>
#define MID ((l+r)>>1)
const int MAX_N = 820000;

int n;//ע����벻��n 
int dat[2 * MAX_N - 1], mark[2*MAX_N-1];

//��dat�г�ʼֵ��ʱ��ͨ���ݹ齨��������Ҫ�ȵ���init���㣩 
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

void update(int k, int a) {//�����޸� �ѵ�k������Ϊa 
	k += n-1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = dat[2*k+1]+dat[2*k+2];
	}
}

//���裺1.�޸Ķ��ӱ�� 2.�´����޸Ķ������ݣ�3.�޸������� 
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

//ȫ��0 x=-1orȫ��0 x = 1 
//������[a,b)���޸� mark��ͬʱ��Ϊ������
void updata(int a, int b, int x, int k, int l, int r) { 
	if (r <= a || b <= l) return;
	if (a <= l && r <= b) {//����ǲ��޸ĵ�ǰֵ 
		mark[k] = x;
		if (x == -1) dat[k] = 0;
		else dat[k] = r-l;//���䳤��Ϊr-l����Ϊ����������ҿ��� 
	}
	else {//����϶�����Ҷ�ڵ� 
		push_down(k, l, r);
		updata(a, b, x, 2*k+1, l, MID);//����Ҫ if (a <= MID)
		updata(a, b, x, 2*k+2, MID, r);
		maintain(k);
	}
}

int query(int a, int b, int k, int l, int r) {//��ѯ���� [a,b)��0�ĸ��� 
	if (r <= a || b <= l) return 0;//���䲻�ཻ 
	if (a <= l && r <= b) return dat[k];//��ѯ������ȫ������ǰ���� 
	else {
		push_down(k, l, r); 
		int v1 = query(a, b, 2*k+1, l, MID);
		int v2 = query(a, b, 2*k+2, MID, r);
		maintain(k);
		return v1+v2;
	}
}

//��ѯ��[a,b)������datΪx��λ�ã�������0~n-1���±�  //datΪ������������Ķ��� eg:sum\rank 
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
