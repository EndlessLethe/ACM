//线性递推 
#define P 1000003
long long ine[P];//不然中间过程可能爆int ll18位 
void pre() {
    ine[1] = 1;
    for (int i  = 2; i < P; i++) {
        int a = P-P/i, b = P%i;
        ine[i] = ine[b]*a%P;
		// if (i < 20) printf("%d %lld\n", i, ine[i]);
    }
}
 

//exgcd   调用inversion(4, P) 
typedef long long ll;
void exgcd(ll a,ll b,ll&d ,ll& x,ll& y) {
    if(!b) {
		d = a, x = 1, y = 0;
	}
    else {
		exgcd(b, a%b, d, y, x);
		y -= x*(a/b);
	}
}

ll inversion(ll a,ll n)
{
    ll d, x, y;
    exgcd(a, n, d, x, y);
    return d==1?(x+n)%n:-1;
}
