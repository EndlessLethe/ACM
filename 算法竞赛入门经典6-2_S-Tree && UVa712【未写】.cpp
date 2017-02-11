#include <stdio.h>
#include <string.h>
#include <stack>
using namespace::std;
stack<char> s;
char input[100000];

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典6-2_S-Tree && UVa712.txt", "r", stdin);
	#endif
	
	int i;
	char temp;
	scanf("%s", input);
	for (i = 0; input[i] != '\0'; i++) {
		if (input[i] == '(' || input[i] == '[') s.push(input[i++]);
		if (input[i] == ')' || input[i] == ']') {
			if (s.empty()) {
				printf("error");
				return 0;
			}
			temp = s.top();
			s.pop();
			if (temp == '(') {
				if (input[i] == ')') ;
				else {
					printf("error");
					return 0;
				}
			}
			else if (temp == '[') {
				if (input[i] == ']') ;
				else {
					printf("error");
					return 0;
				}
			}
		}
	}
	printf("ok");
	return 0;
}
