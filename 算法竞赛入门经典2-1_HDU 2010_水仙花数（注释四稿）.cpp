#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int cubesum(int a, int b, int c);
int compDec(const void *a, const void *b)  
{  
    return *(int *)b - *(int *)a;  
}  
 

int main()
{
	int m = 0, n = 0, k = 0, i = 0;
	int a = 0, b = 0, c = 0;
	int res[MAX] = {0};
	//�������ü��仯�������ӿ��ٶȣ�����ÿ�ε����� a * a * a + b * b * b + c * c * c��Ȼ������ˡ����� 
	while (scanf("%d %d", &m, &n) != EOF) {
		for (i = 0; i < MAX-1; i++){
			res[i] = 0;
		}
		a = 0, b = 0, c = 0;
		while ((res[k] = cubesum(a, b, c)) <= n) {
			if ((res[k] = cubesum(a, b, c)) >= m && (res[k] == 100 * a + 10 * b + c) && res[k] <= n) {
						k++;
					}
			while ((res[k] = cubesum(a, b, c)) <= n) {
				if ((res[k] = cubesum(a, b, c)) >= m && (res[k] == 100 * a + 10 * b + c) && res[k] <= n) {
						k++;
					}
				while ((res[k] = cubesum(a, b, c)) <= n) {
					if ((res[k] = cubesum(a, b, c)) >= m && (res[k] == 100 * a + 10 * b + c) && res[k] <= n) {
						k++;
					}
					c++;
				}
				c = 0;
				b++;
			}
			b = 0, c = 0;
			a++;
		}
		//�õ�����ѭ�����ҷ�ɵT T��������Ӧ��Ҫ����mod��һ�� 
		//���������¾�����ѭ���ҵ���Щ�����������ڽ��result������ 
		if (k == 0) {
			printf("no\n");
		}
		//���û�У����no 
		else {
			int len = 0, temp = 0;
			len = sizeof(res) / sizeof(res[0]);  
			int i;  
  			qsort(res, len, sizeof(res[0]), compDec); 
  			//���˿��š����� 
			while (k > 0) {
				if (res[k] == res[temp]) {
					;
				}
				//�����ظ��Ľ�������� 
				else {
					printf("%d", res[k]);
					temp = k;
					if (k != 1){
					printf(" ");
					}
					//�������ĩβ��ӡ�� �� 
				}
				k--;

			}
			printf("\n");
			//���ѭ�����У��ȴ��´����� 
		}
			k = 0;
	}
	return 0;
}

int cubesum(int a, int b, int c) {
	return a * a * a + b * b * b + c * c * c;
}
