#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int N = 0, M = 0;
int c;
int i, j = 0, t;
int num[3000 + 5] = {0};

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
	for (i=0; i < q; i++) {
		string1[i] = (temp1 / (int)pow(10, q-i) ) % 10;
	}
	int p = 0;
	temp2 = *(int *)b;
	while(temp2 / 10 > 0) {
		temp2=temp2/10;
		p = p + 1;
	}
	for (i=0; i < p; i++) {
		string2[i] = (temp2 / (int)pow(10, p-i) ) % 10;
	}
	
//	if (temp2 > temp1) {
//		boolnum = 1;
//	}
//	else if ()
//    return boolnum;
	i = 0;
//	while(i < q && i < p && string1[i]== string2[i]){
//        i++;
//    }


//	while(*string1 && *string2 && *string1==*string2){
//              string1++;
//              string2++;
//        }
//这我是真不懂 

    if (string1[i] == string2[i]) {
    	boolnum = 0;
	}
	else if (string1[i] < string2[i]) {
		boolnum = 1;
	}
    return boolnum;
}  


int main()
{
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
		printf("\n");
	}
	return 0;
}
