//设k为任意正整数 
//裴蜀等式：对于a,b,t=gcd(a, b), ax+by=t一定有解 
//进一步推得方程ax+by=c一定有c=kt，否则无解 
//故对于方程ax+by=c
//先求方程ax+by=t的解
//如果c % t != 0, 则方程无解 
//否则 x*=k;y*=k;(c= kt)则得到原方程的一个解
//However,此时的解不一定满足题目的条件
//对于所有的通解x,y有 x = x0 + k* b/t, y = y0 - k* a/t
//考虑取绝对值b/t，然后求满足题意的解 
 

//输入：a, b两个整数, x, y两个用来储存结果的应用
//输出：a和b的最大公约数
//调用后x, y满足ax+by=gcd(a, b) 

int a,b;
int x,y;
int exgcd(int a, int b, int& x, int& y) {
	int d = a;
	if (b != 0) {
		d = ecgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

int main() {
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4) {
		int t = exgcd(a, -c, x, y);
//		printf("%d %d %d\n", t, x, y);
		if ((d-b) % t == 0) {
			int tem = (d-b)/t;
			x *= tem;
			int scale = abs(-c/t);
			if (x > 0) {
				while (x > 0) {
					x -= scale;
				}
				x += scale;
			}
			else {
				while (x < 0) {
					x += scale;
				}
			}
			printf("%d\n", a*x+b);
		}
		else printf("-1\n");
	}
	return 0;
}
