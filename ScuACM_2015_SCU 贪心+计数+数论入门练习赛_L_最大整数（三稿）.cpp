#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int N = 0, M = 0;
int c;
int i, j = 0, t, k;
int num[3000+5] = {0};

int compDec(const void *a, const void *b)
{
	int q = 0;
	int temp1 = *(int *)a;
	int temp2 = *(int *)b;
	int string1[5] = {0};
	int string2[5] = {0};
	int boolnum = -1;
	while(temp1 / 10 > 0) {
		temp1=temp1/10;
		q=q+1;
	}
	temp1 = *(int *)a;
	for (k=0; k <= q; k++) {
		string1[k] = (temp1 / (int)pow(10, q-k) ) % 10;
	}
	int p = 0;
	temp2 = *(int *)b;
	while(temp2 / 10 > 0) {
		temp2=temp2/10;
		p = p + 1;
	}
	for (k=0; k <= p; k++) {
		string2[k] = (temp2 / (int)pow(10, p-k) ) % 10;
	}
	
//	if (temp2 > temp1) {
//		boolnum = 1;
//	}
//	else if ()
//    return boolnum;
	k = 0;
	while(k < q && k < p && string1[k]== string2[k]){
        k++;
    }


//	while(*string1 && *string2 && *string1==*string2){
//              string1++;
//              string2++;
//        }
//这我是真不懂 

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
//  不懂这里为什么不能重定向   应该是多了空格。。。以后直接复制名字比较好 
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &M);
		for (j = 0; j < M; j++) {
			scanf("%d", &num[j]);
		}
		int len = 0, temp = 0;
		len = sizeof(num) / sizeof(num[0]);   
  		qsort(num, len, sizeof(num[0]), compDec);  
		for (t = 0; t < j; t++) {
			printf("%d", num[t]);
			num[t] = 0;
		}
		//必须倒着打印，否则000000 
		printf("\n");
	}
	return 0;
}
