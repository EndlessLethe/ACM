#include <bits/stdc++.h>

#define MAX ******
//����Ŀ�ķ�Χ������û���ṩ���������Դ���������Ŀ������̫������� 

int f(int a, int* val);

int main()
{
	int n = 0, i = 0, k = 0;
	scanf("%d",&n);
	int res[MAX], val[MAX];//res��������val�Ǽ�����̵����� 
	while (n != ****) {
		i = 0;
		res[i++] = f(n, val);
		//���е�ϸ�ڶ���������f��ʵ�֣�ֻ������ 
		scanf("%d",&n);
	}

	for (k = 0; k < i; k++) {	
		printf("%d\n", res[k]);	
	}
	//���˶��ٸ�����������ٸ��� 
}

int f(int a, int* val) {
	if (val[a-1]){
	//�����0��ʼ���� 
		;
	}
	//����Ѿ������ֱ����� 
	if else (a < ***) {
		val[a-1] = 1;
		//����ʹѭ���ܹ���ֹ������ʱ���߳�ѭ�� 
		//ǰ��������� 
	}
	else {	
		//��������ƵĹ�ʽ 
	}
	return val[a-1];
}
