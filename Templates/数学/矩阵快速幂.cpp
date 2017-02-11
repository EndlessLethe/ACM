//初始的矩阵B只能手动填
//注意有MOD 

const int N = 2;//按照递推式修改 
//int MOD = 0;
struct mat{long long a[N+1][N+1];};

mat operator + (mat a,mat b) {
    mat c;
    memset(c.a, 0, sizeof(c.a));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            c.a[i][j] = a.a[i][j] + b.a[i][j];
    return c;
}
mat operator * (mat a,mat b) { 
    mat c;
    memset(c.a,0,sizeof(c.a));
    for(int i =1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int k = 1; k <= N; k++)
                c.a[i][j] = (c.a[i][j] + a.a[i][k]*b.a[k][j]);// % MOD;
    return c;
}

mat matinit(void) {
    mat c;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
	        c.a[i][j] = 0;
	        if(i == j) c.a[i][j] = 1;
	    }
    }
    return c;
}

mat fastmat(mat a, long long k) {
    mat c = matinit();
    while(k > 0) {
        if(k % 2 == 1) c = c*a;
        k = k / 2;
        a = a * a;
    }
    return c;
}

//	mat A ;
//	A.a[1][1] = A.a[1][2] = A.a[2][1] = 1;//F矩阵是竖着的 
//	A.a[2][2] = 0;
//	mat p = fastmat(A, n);
//	cout << p.a[2][1]*b + p.a[2][2]*a << endl;
//	cout << ((p.a[2][1]*b + p.a[2][2]*a) % MOD + MOD) % MOD  << endl;

