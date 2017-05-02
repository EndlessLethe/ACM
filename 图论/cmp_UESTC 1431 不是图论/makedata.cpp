#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib> 

 
int main(void)  
{  
	freopen("in.txt", "w", stdout);
    srand(time(NULL));  
    int T=100;//n多少自己定  
//    printf("100\n");
    while (T--) {
    	int n = rand() % 10;
    	if (n == 0) continue;
    	printf("%d ", n);//n
    	int m = rand() % (n*n);//m
    	printf("%d\n", m);
    	for (int i = 0; i < n; i++) printf("%d ", rand()%20);//val值 
    	for (int i = 0; i < m; i++) {
    		printf("%d %d\n", rand()%(n-1)+1, rand()%(n-1)+1);
		}
		printf("\n");
    }  
    return 0;  
}
