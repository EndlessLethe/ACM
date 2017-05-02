//��kΪ���������� 
//�����ʽ������a,b,t=gcd(a, b), ax+by=tһ���н� 
//��һ���Ƶ÷���ax+by=cһ����c=kt�������޽� 
//�ʶ��ڷ���ax+by=c
//���󷽳�ax+by=t�Ľ�
//���c % t != 0, �򷽳��޽� 
//���� x*=k;y*=k;(c= kt)��õ�ԭ���̵�һ����
//However,��ʱ�Ľⲻһ��������Ŀ������
//�������е�ͨ��x,y�� x = x0 + k* b/t, y = y0 - k* a/t
//����ȡ����ֵb/t��Ȼ������������Ľ� 
 

//���룺a, b��������, x, y����������������Ӧ��
//�����a��b�����Լ��
//���ú�x, y����ax+by=gcd(a, b) 

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
