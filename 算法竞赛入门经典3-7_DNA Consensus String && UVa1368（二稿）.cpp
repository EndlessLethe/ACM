#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

char input[50+5][1000+5];
char result[1000+5];
map<char, int> which_big;

//不知道为什么过不了QAQ 
//第二天发现result数组开小了QAQ 

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典3-7_DNA Consensus String && UVa1368.txt", "r", stdin);
	#endif
	
	int puzzle, m, n, i, j, k, maxnum;
	long long diff;
	
	scanf("%d", &puzzle);
	while (puzzle--) {
		memset(result, '\0', sizeof(result));
		scanf("%d%d", &m, &n);
		for (i = 0; i < m; i++) {
			scanf("%s", input[i]);
		}
		
		for (j = 0; j < n; j++) {
			for (i = 0; i < m; i++) {
				if (!which_big.count(input[i][j])) which_big[input[i][j]] = 0;
				which_big[input[i][j]]++;
			}
			maxnum = 0;
			if (maxnum < which_big['A']) maxnum = which_big['A'];
			if (maxnum < which_big['C']) maxnum = which_big['C'];
			if (maxnum < which_big['G']) maxnum = which_big['G'];
			if (maxnum < which_big['T']) maxnum = which_big['T'];
			if (maxnum == which_big['A']) result[j] = 'A';
			else if (maxnum == which_big['C']) result[j] = 'C';
			else if (maxnum == which_big['G']) result[j] = 'G';
			else if (maxnum == which_big['T']) result[j] = 'T';
			which_big['A'] = 0;
			which_big['C'] = 0;
			which_big['G'] = 0;
			which_big['T'] = 0;
		}
		
		
		diff = 0;
		for (k = 0; k < m; k++) {//比较 
			for (j = 0; j < n; j++) {
				if (result[j] != input[k][j]) diff++;
			}
		}
		diff;
		

		printf("%s\n", result);
		printf("%lld\n", diff);
		
	}
	return 0;
}
