#include <stdio.h>
#include<string.h>


char inputa[100005];
char inputb[100005];
//��֪��Ϊʲô����������ˡ�
//�ĵ�ʱ���Ż��˺ܶ� 
int main()
{
	#ifdef LOCAL
		freopen("input_�㷨�������ž���3-9_All in All && UVa10340.txt", "r", stdin);
	#endif
	
	int i, k, ok, k1, k2;
	while ((scanf("%s%s", inputa, inputb)) == 2) {
		ok = 1;
		k = 0;
		for (i = 0; inputa[i] != '\0'; i++) {
			if (i == 0) {
				k1=strlen(inputa);
        		k2=strlen(inputb);
        		if(k1 > k2)
      		    {
            		ok = 0;
					break;
       			}
			}
			while (inputa[i] != inputb[k] && inputb[k] != '\0') {
				k++;
			}
			if (inputb[k] == '\0') {
				ok = 0;
				break;
			}
		}
		if (ok == 1) printf("Yes\n");
		else if (ok == 0) printf("No\n");
	}
	return 0;
}
