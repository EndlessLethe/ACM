//���룺a, b�������� 
//�����a, b�����Լ�� 
long long gcd(long long a,long long b) {
    return b == 0  ? a : gcd(b, a%b);
}

//���룺a, b�������� 
//�����a, b����С������ 
long long lcm(long long a,long long b) {
    return a / gcd(a,b) * b;
}

