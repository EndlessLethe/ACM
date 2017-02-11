/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/6/10 23:10:44
File Name     :HDU 1257.cpp
Description   :LIS or Ì°ÐÄ
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAX = 100010;
int input[MAX], dp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int N, Max;
	while (cin >> N) {
	    for (int i = 0; i < N; i++) {
			cin >> input[i];
		}
		for (int i = 0; i < N; i++) {
			dp[i] = 1;
		}
		for (int i = 1; i < N; i++) {
			Max = -1;
			for (int j = 0; j < i; j++) {
				if (input[j] < input[i] && Max < dp[j]) Max = dp[j];
			}
			if (Max == -1) dp[i] = 1;
			else dp[i] = Max + 1;
		}
		Max = -1;
		for (int i = 0; i < N; i++) {
			Max = max(Max, dp[i]);
		}
		cout << Max << endl;
	}
    return 0;
}
