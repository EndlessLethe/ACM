#include <stdio.h> 
#include <string.h> 


char input[100];

//�����Ӧ��һ��AC�ģ�����Ϊ��ȷ�����û�����������Ƕ��ٵ����⣬ WA�� 
//  ����֮������ǹ����ˣ���֪֪��Ϊʲô������ 


int main()
{
	#ifdef LOCAL
		freopen("input_�㷨�������ž���3-4_Periodic Strings && UVa455.txt", "r", stdin);
	#endif
	int n, i, j, k, ans, flag;
	scanf("%d", &n);
	for (k = 0; k < n; k++) {
		ans = 0;
		scanf("%s", input);
		for (i = 1; input[i] != '\0'; i++) {
			flag = 1;
			if (input[i] == input[0]) {
				for (j = 0; input[j+i] != '\0'; j++) {
					if (input[j+i] != input[j]) {
						flag = 0;
					}
				}
				ans = i;
				if (flag == 1) {
					printf("%d\n", ans);
					goto end;
				}
			}
		}
		printf ("%d\n", strlen(input));
		end:
		if (k != n-1) printf("\n");
	}
	return 0;
}
