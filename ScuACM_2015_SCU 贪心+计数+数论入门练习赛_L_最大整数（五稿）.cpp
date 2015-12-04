#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

int N = 0, M = 0;
int c;
int i, j = 0, t, k;
//ll num[3000+5] = {0};
long long num[5] = {0};
//当数组小一点 就可以， 大一点就不行。。。 

int compDec(const void *a, const void *b)
{
	int q = 0;
	ll temp1 = *(ll *)a;
	ll temp2 = *(ll *)b;
	int string1[100] = {0};
	int string2[100] = {0};
	int boolnum = -1;
	while(temp1 / 10 > 0) {
		temp1=temp1/10;
		q=q+1;
	}
	temp1 = *(ll *)a;
	for (k=0; k <= q; k++) {
		string1[k] = (temp1 / (int)pow(10, q-k) ) % 10;
	}
	int p = 0;
	while(temp2 / 10 > 0) {
		temp2=temp2/10;
		p = p + 1;
	}
	temp2 = *(ll *)b;
	for (k=0; k <= p; k++) {
		string2[k] = (temp2 / (ll)pow(10, p-k) ) % 10;
	}
	k = 0;
	while(k < 100 && string1[k]== string2[k]){
        k++;
    }

    if (string1[k] == string2[k]) {
    	boolnum = 0;
	}
	else if (string1[k] < string2[k]) {
		boolnum = 1;
	}
    return boolnum;
}  


int main()
{
	#ifdef LOCAL
	freopen("input_ScuACM_2015_SCU 贪心+计数+数论入门练习赛_L_最大整数.txt", "r", stdin);
	#endif

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &M);
		for (j = 0; j < M; j++) {
			scanf("%lld", &num[j]);
		}
		int len = 0, temp = 0;
		len = sizeof(num) / sizeof(num[0]);   
  		qsort(num, len, sizeof(num[0]), compDec);  
		for (t = 0; t < j; t++) {
			printf("%lld", num[t]);
			num[t] = 0;
		}

		printf("\n");
	}
	return 0;
}
