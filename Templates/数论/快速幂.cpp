//返回x的m次幂 p为模数 

long long fast_mod(long long x, long long m, long long p){
    long long s = x;
    long long ans = 1;
    while (m) {
        if (m & 1) ans = s * ans % p;
        s = s * s % p;
        m >>= 1;
    }
    return ans;
}

long long fast_mod(long long x, long long m){
    long long s = x;
    long long ans = 1;
    while (m) {
        if (m & 1) ans = s * ans;
        s = s * s;
        m >>= 1;
    }
    return ans;
}
