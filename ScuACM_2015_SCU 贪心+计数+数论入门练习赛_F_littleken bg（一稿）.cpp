
#include <stdio.h>
#include <iostream>
    #define MAXSIZE 500
    using namespace std;
    int f[MAXSIZE],c[MAXSIZE];//c是大小，w是价值
    int N,V;//N为物品数，V表示背包大小
    int i = 0;
    
    int main()
    {

	
	while(scanf("%d", &V) != EOF) {
        for (i = 0; i < MAXSIZE; i++) {
        	f[i] = 0;
			c[i] = 0;
		}
        scanf("%d", &N);
        for (i=0;i<N;i++)
        {
            cin>>c[i];
        }
		for (int i=0;i<N;i++)
        {
            for (int v = V; v >= c[i]; v--) //c[i]可优化为bound,bound = max {V - sum c[i,...n],c[i]}
            {
                f[v]=max(f[v], f[v - c[i]] + c[i]);
				//与状态转移公式f[v]=max{f[v],f[v-c[i]]+w[i]}等价
            }
        }
        //当i=N时，可以跳出循环单独计算F[V]
        cout << f[V] << '\n';
    }
}
