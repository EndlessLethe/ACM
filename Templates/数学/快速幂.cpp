//����x��m���� pΪģ�� 
typedef ll ll;
#define MOD xxxx

ll fast_pow(ll x, ll m){
    ll ans = 1;
    while (m) {
        if (m & 1) ans = s * ans % MOD;
        s = s * s % MOD;
        m >>= 1;
    }
    return ans;
}

ll fast_pow(ll x, ll m){
    ll ans = 1;
    while (m) {
        if (m & 1) ans = s * ans;
        s = s * s;
        m >>= 1;
    }
    return ans;
}
