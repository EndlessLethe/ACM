//输入：a, b两个整数 
//输出：a, b的最大公约数 
long long gcd(long long a,long long b) {
    return b == 0  ? a : gcd(b, a%b);
}

//输入：a, b两个整数 
//输出：a, b的最小公倍数 
long long lcm(long long a,long long b) {
    return a / gcd(a,b) * b;
}

