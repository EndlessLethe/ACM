#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib>  
int main(void)  
{  
    freopen("in.txt", "w", stdout);  
    srand(time(NULL));  
    int n=100;//n多少自己定  
//    printf("100\n");
    while (n--) {
    	int k = rand() % 10;
    	printf("%d\n", k);
    	int q = rand();
        for (int j = 0; j < k; j++) {
        	printf("%d ", q-j);
		}
		printf("\n");
		for (int j = 0; j < k; j++) {
			printf("%d ", q-j);
			printf("%d ", rand());
			int m = rand() % k;
			int s = rand() % k;
			printf("%d ", s);
			for (int t = 0; t < m; t++) {
				if (q-k+m+s <= q) printf("%d\n", q-k+m+s);
				else printf("%d\n", q-k+m+s);
			}
		}
		printf("\n");
    }  
    return 0;  
}
