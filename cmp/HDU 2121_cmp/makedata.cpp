#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib> 

int map[1000][1000];
 
int main(void)  
{  
    freopen("in.txt", "w", stdout);  
    srand(time(NULL));  
    int n=100;//n多少自己定  
//    printf("100\n");
    while (n--) {
    	int k = rand() % 10;
    	if (k == 0) continue;
    	printf("%d\n", k);
    	k = rand() % 10;
    	printf("%d\n", k);
    	for (int i = 0; i < k; i++) {
    		printf("%d %d %d\n", rand()%10, rand()%10, rand()%10);
		}
		printf("\n");
    }  
    return 0;  
}
