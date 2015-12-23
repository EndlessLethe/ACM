#include <stdio.h>
#include <string.h>
#include <queue>
using namespace::std;

long long w[100000+10];
int CASE, i;
long long N, j, ans;

int main()
{
	
//	#ifdef LOCAL
//	freopen("input_ScuACM_2015_赛氪杯四川大学ACMICPC队新生选拔赛_G_skysky's game.txt", "r", stdin);
//	#endif
	
	priority_queue <int, vector<int>, greater<int> > candy;
	
	scanf("%d", &CASE);
	for (i = 0; i < CASE; i++) {
		scanf("%lld", &N);
		ans = 0;
		
		for (j = 0; j < N; j++) {
			scanf("%lld", &w[i]);
			candy.push(w[i]);
		}
		
		while (candy.size() > 1) {
			int one, two;
			one = candy.top();
			candy.pop();
			two = candy.top();
			candy.pop();
			
			ans += one + two;
			candy.push(one + two);
		}
		
		while (candy.size()) {
		candy.pop();
		}
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
