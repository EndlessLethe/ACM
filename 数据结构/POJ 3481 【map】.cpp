/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/7/19 9:00:17
File Name     :POJ 3481 ¡¾map¡¿.cpp
Description   :
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


map <int, int> m;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int N, a, b;
	while (cin >> N) {
		if (N == 0) return 0;
		else if (N == 1) {
			cin >> a >> b;
			m[b] = a;
		}
		else if (N == 3) {
			map<int,int>::const_iterator it = m.begin();
			cout << it->second << endl;
			m.erase(it->first);
		}
		else if (N == 2) {
			if (m.size() == 0) {
				cout <<  "0" << endl;
				continue;
			}
			map<int,int>::const_iterator it = m.end();
			cout << (--it)->second << endl;
			m.erase(it->first);
		}
	}
    return 0;
}
