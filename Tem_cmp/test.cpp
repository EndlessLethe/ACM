/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/4/28 9:19:47
File Name     :scu1039.cpp
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

struct people {
	string n;
	int give, get;
} p[10+2];
map<string, int> name;

int main()
{
//    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("a.txt","w",stdout);
//    #endif
    ios_base::sync_with_stdio(0);cin.tie(0);
	int cases, giveout, how_many;
	string temp;
    while (cin >> cases) {
		for (int i = 0; i < cases; i++) {
//			for (int j = 0; j < 12; j++) {
//				cout << j << ":" <<p[j].n << endl;
//			}
			cin >> p[i].n;
//			cout << p[i].n << endl;
			name.insert(map<string, int>::value_type(p[i].n, i));
//			name[p[i].n] = i;
			p[i].give = 0;
			p[i].get = 0;
		}
		for (int i = 0; i < cases; i++) {
			cin >> temp >> giveout >> how_many;
//			cout << "temp:" << temp << "\n";
//			cout << "giveout:" << giveout << "\n";
//			cout << "how_many:" << how_many << "\n";
			if (giveout == 0 || how_many == 0) ; 
			else {
				p[name.find(temp)->second].give += giveout;
				p[name.find(temp)->second].get += giveout - (giveout/how_many) * how_many;
			}
			
//			cout << "give:" <<p[i].give << "\n";
			
//			cout << "get:" <<p[i].get << "\n";
			for (int j = 0; j < how_many; j++) {
				cin >> temp;
				if (giveout == 0 || how_many == 0) ; 
				else {
					p[name.find(temp)->second].get += giveout / how_many;
				}
//				cout << "get:" << p[name.find(temp)->second].get << "\n";
			}
		}
		for (int i = 0; i < cases; i++) {
			cout << p[i].n << " " << p[i].get - p[i]. give << "\n";
		}
		cout << endl;
		name.clear();
	}
    return 0;
}
