#include <cstdio>
#include <iostream>
#include<string.h>
#include <stack>
using namespace::std;

char letters[100000];
int r[100000];
//tempΪǰһ����Ч�ַ� 
int main()
{
    #ifdef LOCAL
	freopen("input_�㷨�������ž��� ����6-4_Broken Keyboard && UVa11988.txt", "r", stdin);
    #endif
    int len, i, start, end, temp;
    char ch;
    char pre_is_same;
	while (scanf("%s", letters+1) == 1) {
		len = strlen(letters+1)+1;
		r[0] = 1;
		start = 1, end = 1;
		temp = 0;
		pre_is_same = 0;
		for (i = 1; i < len; i++) {
			if (letters[i] == '[') {
				if (letters[i+1] == '[' || letters[i+1] == ']') continue;
				if (pre_is_same == 0) continue;
				if (pre_is_same == letters[i]) {
					r[temp] = start;
					temp = end;
				}
				pre_is_same = letters[i];
				start = r[0];
				end = temp;
				temp = 0;
			}
			else if (letters[i] == ']') {
				if (letters[i+1] == '[' || letters[i+1] == ']') continue;
				if (pre_is_same == letters[i]) {
					start = r[0];
					end = temp;
					temp = 0;
				}
				pre_is_same = letters[i];
				r[temp] = start;
				temp = end;
			}
			else {
				r[temp] = i;
				temp = i;
			}
		}
		if (!(start == 1 && end == 1)) {
			r[temp] = start;
			temp = end;
		}
		i = 0;
		while (r[i] != 0) {
			printf("%c", letters[r[i]]);
			i = r[i];
		}
		printf("\n");
		memset(letters, 0, sizeof(letters));
		memset(r, 0, sizeof(r));
	}
    
    return 0;
}

