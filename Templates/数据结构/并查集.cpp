long long int sum[MAX];//����ͬʱά���ܶ��ֵ����������sum 
int p[MAX];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {//Ϊ�˷�����д��ͳһ��y����x
	x = find(x), y = find(y);
	if (x == y) return ;
	pa[x] += pa[y];
	pa[y] = x;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = -1;
//		sum[i] = 0; 
	}
}
