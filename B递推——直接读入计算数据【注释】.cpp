#include <bits/stdc++.h>

#define MAX ******
//����Ŀ�ķ�Χ������û���ṩ���������Դ���������Ŀ������̫������� 

long long int f(int a, long long int* val);

int main()
{
	int a = 0, i = 0, k = 0;
	long long int res[MAX], val[MAX];//res��������val�Ǽ�����̵����� 
	while (scanf("%d", &a) != ****) {
		res[i++] = f(a, val);
		//���е�ϸ�ڶ���������f��ʵ�֣�ֻ������ 
	}

	for (k = 0; k < i; k++) {	
		printf("%d\n", res[k]);	
	}
	//���˶��ٸ�����������ٸ��� 
}

long long int f(int a, int* val) {
	if (val[a-1]){
	//�����0��ʼ���� 
		;
	}
	//����Ѿ������ֱ����� 
	else if (a < ***) {
		val[a-1] = 1;
		//����ʹѭ���ܹ���ֹ������ʱ���߳�ѭ�� 
		//ǰ��������� 
	}
	else {	
		//��������ƵĹ�ʽ 
	}
	return val[a-1];
}
