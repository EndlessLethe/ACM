
#include <stdio.h>
#include <iostream>
    #define MAXSIZE 500
    using namespace std;
    int f[MAXSIZE],c[MAXSIZE];//c�Ǵ�С��w�Ǽ�ֵ
    int N,V;//NΪ��Ʒ����V��ʾ������С
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
            for (int v = V; v >= c[i]; v--) //c[i]���Ż�Ϊbound,bound = max {V - sum c[i,...n],c[i]}
            {
                f[v]=max(f[v], f[v - c[i]] + c[i]);
				//��״̬ת�ƹ�ʽf[v]=max{f[v],f[v-c[i]]+w[i]}�ȼ�
            }
        }
        //��i=Nʱ����������ѭ����������F[V]
        cout << f[V] << '\n';
    }
}
