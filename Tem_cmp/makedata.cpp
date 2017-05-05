#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib>  
void connected_graph(int n);
int main(void)  
{  
//    freopen("in.txt", "w", stdout);  
    srand(time(NULL));  
    int t = 1;//t多少自己定  
    while (t--) {
    	int n = 10;
    	connected_graph(n);
    }  
    return 0;  
}

void connected_graph(int n) {//生成一棵树 
	next[2] = 1;
	for (int i = 3; i < n; i++) {
		next[i] = rand() % (i-1)+1;//rand()%i属于[0, i-1] 
	}
}

void print_graph() {
	for (int i = 2; i <= n; i++) printf("%d %d\n", i, next[i]);
}
