double EPS = 1e-12;
const int MAX = 50010;

double add(double a, double b) {
	if (fabs(a+b) < EPS * (fabs(a) + fabs(b))) return 0;
	return a+b;
}

struct P{
	double x, y;
	P() {};
	P(double x, double y):x(x), y(y) {
	}
	P operator + (P p) {
		return P(add(x, p.x), add(y, p.y));
	}
	P operator - (P p) {
		return P(add(x, -p.x), add(y, -p.y));
	}
	P operator * (double d) {
		return P(x* d, y*d);
	}
	double dot(P p) {
		return add(x*p.x, y*p.y);
	}
	double det(P p) {
		return add(x*p.y, -y*p.x);
	}
};
P ps[MAX];

bool cmp_x(const P &p, const P &q) {
	if (p.x != q.x) return p.x < q.x;
	return p.y < q.y;
}

vector <P> convex_hull(P* ps, int n) {
	sort(ps, ps+n, cmp_x);
	int k = 0;
	vector<P>  qs(n*2);//����͹�� 
	for (int i = 0; i < n; i++) {//͹���²� 
		while (k > 1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	for (int i = n-2, t = k; i >= 0; i--) {//͹���ϲ� 
		while (k > t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}

double dist(P p, P q) {//����ƽ�� 
	return (p-q).dot(p-q);
}

int main()
{
//    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int N;
    scanf("%d", &N);
    for (int i= 0; i < N; i++) {
    	scanf("%lf%lf", &ps[i].x, &ps[i].y);
	}
    vector<P> qs = convex_hull(ps, N);
	int n = qs.size();
	if (n == 2) {//����͹���˻� 
		printf("%.0f\n", dist(qs[0], qs[1]));
		return 0;
	}
	int i = 0, j = 0;//ĳ�����ϵĶ����� 
	for (int k = 0; k < n; k++) {//���x�����ϵ� 
		if (!cmp_x(qs[i], qs[k])) i = k;
		if (cmp_x(qs[j], qs[k])) j = k;
	}
	double res = 0;
	int si = i, sj = j;
	while (i != sj || j != si) {//����������ת180�� 
		res = max(res, dist(qs[i], qs[j]));
		if ((qs[(i+1)%n] - qs[i]).det(qs[(j+1)%n] - qs[j]) < 0) {
			i = (i+1) % n;//��ת����i-(i+1)�ķ��߷��� 
		}
		else {
			j = (j+1) % n;//��ת����j-(j+1)�ķ��߷��� 
		}
	}
	printf("%.0f\n", res);
    return 0;
}
