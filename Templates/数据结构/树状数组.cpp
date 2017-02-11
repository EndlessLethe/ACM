//读入从1开始 
//注意每次初始化b 
//i~j区间求sum是sum(i)-sum(i-1) 

const int MAX_N = 500100;

int N; //需要读入N 
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
		b[i] += v;//可以改为 =  
		i += i & -i;
	}
}
