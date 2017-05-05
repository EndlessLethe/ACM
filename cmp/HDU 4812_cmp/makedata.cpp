#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib>  

#define P 1000003
void connected_graph();
void print_graph();
int v[1005];
int next[1005];
int t, n, k, m;

int main(void)  
{  
    freopen("in.txt", "w", stdout);
    srand(time(NULL));  
    t = 100;//t多少自己定  
    while (t--) {
    	n = 20, k = 1;
    	printf("%d ", n);
    	for (int i = 1; i <= n; i++) {
    		v[i] = rand() % P +1;
		}
		connected_graph();
		printf("%d\n", k);
		for (int i = 1; i <= n; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		print_graph();
    }  
    return 0;  
}

void connected_graph() {//生成一棵树 
	int flag = 0, tmp;
	next[2] = 1;
	for (int i = 3; i <= n; i++) {
		next[i] = rand() % (i-1)+1;//rand()%i属于[0, i-1] 
		if (i == 5) {
			flag = 1;
			tmp = next[5];
			k = v[tmp];
		}
		if (i == 12) flag = 0;
		if (flag) {
			if (tmp == next[i]) {
				k = k * v[tmp] % P;
				tmp = i;
				if (k < 0) k = 1;
			}
		}
	}
}

void print_graph() {
	for (int i = 2; i <= n; i++) printf("%d %d\n", i, next[i]);
}
