#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;

char input[105];
stack <int> s;

int main() {
	input[0] = '(';
	scanf("%s", input+1);
	int len = strlen(input);
	input[len++] = ')';
	//printf("%s", input);
	for (int i = 0; i < len; i++) {
		if (input[i] == '(') {
			s.push(-2);
			s.push(0);
		}
		if (input[i] == 'x') {
			int temp = s.top();
			s.pop();
			s.push(temp+1);
		}
		if (input[i] == '|') {
			s.push(0);
			s.push(0);
		}
		if (input[i] == ')') {
			int maxNum = 0;
			while (s.top() != -2) {
				maxNum = max(maxNum, s.top());
				s.pop();
			}
			s.pop();
			if (!s.empty()){
				int temp = s.top();
				s.pop();
				s.push(maxNum+temp);
			}
			else s.push(maxNum);
		}
		//printf("%d", s.top());
	}
	printf("%d\n", s.top());
	return 0;
}
