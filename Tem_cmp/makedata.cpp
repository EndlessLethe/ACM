#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib>  
void connected_graph(int n);
int main(void)  
{  
//    freopen("in.txt", "w", stdout);  
    srand(time(NULL));  
    int t = 1;//t�����Լ���  
    while (t--) {
    	int n = 10;
    	connected_graph(n);
    }  
    return 0;  
}

void connected_graph(int n) {//����һ���� 
	next[2] = 1;
	for (int i = 3; i < n; i++) {
		next[i] = rand() % (i-1)+1;//rand()%i����[0, i-1] 
	}
}

void print_graph() {
	for (int i = 2; i <= n; i++) printf("%d %d\n", i, next[i]);
}
