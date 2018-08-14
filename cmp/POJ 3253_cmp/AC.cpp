#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct T{
   int x;
   const bool operator<(T a) const{
       return a.x<x;
   }
};
T a[20019];
int main(){
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		freopen("AC.txt","w",stdout);	
	#endif
    int n;
    long long res;
    priority_queue<T> q;
    while(!q.empty()) q.pop();
    while(scanf("%d",&n)!=EOF){
         res = 0;
         for(int i = 0;i<n;i++)  {
               scanf("%d",&a[i].x);
               q.push(a[i]);
         }
         for(int i = 0;i<n-1;i++){
               T temp;
               T x = q.top();q.pop();
               T y = q.top();q.pop();
               res = res + x.x + y.x;
               temp.x = x.x + y.x;
               q.push(temp);
         }
         while(!q.empty()) q.pop();
         cout<<res<<endl;
    }
    return 0;
}
