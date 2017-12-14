#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib>  

int t, n, x;

int main(void)  
{  
    freopen("in.txt", "w", stdout);
    srand(time(NULL));  
    t = 10;//t多少自己定  
    while (t--) {
    	int n = rand() % 100007;
    	printf("%d\n", n);
    	for (int i = 0; i < n; i++) {
    		x = rand() % 10;
    		printf("%d ", x);
		}
		printf("\n");
    }  
    return 0;  
}


