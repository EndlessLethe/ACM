//�����1��ʼ 
//ע��ÿ�γ�ʼ��b 
//i~j������sum��sum(i)-sum(i-1) 

const int MAX_N = 500100;

int N; //��Ҫ����N 
long long b[MAX_N+1];

long long sum(int i) {//[1, i] 
	long long s = 0;
	while (i > 0) {
		s += b[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, long long v) {
	while (i <= N) {
		b[i] += v;//���Ը�Ϊ =  
		i += i & -i;
	}
}
