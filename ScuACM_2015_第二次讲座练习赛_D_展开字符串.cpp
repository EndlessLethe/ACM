#include <bits/stdc++.h>

#define MAX 250000

void f(int i, int* res);
int number(int a);

int main()
{
	int n = 0, i = 0;
	scanf("%d", &n); 
	int res[n][MAX] = {0};
	
	for (i = 0; i < n; i++){
		f(i, res[i]);
	}
	
	for (i = 0; i < n; i++){	
		printf("%s\n", res[i]);	
	}
}

void f(int i, int* res){
	int a = 0;
	while ((a = getchar()) != )
	if (number(a))
}

int number(int a){
	if (a >= 48 && a <= 57){
		return 0;
	}
	else {
		
	}
}
