#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cstdlib>  
#include<iostream>
using namespace std;
void connected_graph(int n);
int main(void)  
{  
    freopen("in.txt", "w", stdout);  
    srand(time(NULL));  
    int t = 10000;//t多少自己定  
    cout << t << endl;
    while (t--) {
    	cout << rand() << endl;
    }  
    return 0;  
}

