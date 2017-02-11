#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib>  
int main(void)  
{  
    freopen("in.txt", "w", stdout);  
    srand(time(NULL));  
    int n=100;//n多少自己定  
    printf("100\n");
    while (n--) {
        for (int j = 0; j < 1; j++) {
        	int q = rand();
			for (int i = 15; i >= 0; i--) {  
			  printf("%d", (q >> i) & 1);  
			} 
		}
		printf("\n");
    }  
    return 0;  
}
