#include <stdio.h>
#include <stdlib.h>


int N = 0;
int c;
int i, j = 0, t;
int num[3000 + 5] = {0};

int compDec(const void *a, const void *b)  
{  
    return *(int *)b - *(int *)a;  
}  


int main()
{
	#ifdef LOCAL
	freopen("input_ScuACM_2015_SCU ̰��+����+����������ϰ��_L_�������.txt", "r", stdin);
	#endif
//  ��������Ϊʲô�����ض��� 

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		c = getchar();
		c = getchar();
		while(c!='\n') {
			ungetc(c,stdin);
			scanf("%d",&num[j++]);
			c=getchar();
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
