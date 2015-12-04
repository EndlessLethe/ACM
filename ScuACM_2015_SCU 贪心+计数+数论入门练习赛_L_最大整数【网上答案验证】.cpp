#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::sort;
using std::vector;
using std::string;
//ÅÅÐò¹æÔò
bool cmp(string str1 , string str2)
{
	string temp1 = str1+str2;
	string temp2 = str2+str1;
	return temp1>temp2;
}
int main()
{
	vector<string> vStr;
	string str;
	int L , N;
	cin >> L;
	while(L--)
	{
		vStr.clear();
		cin >> N;
		for(int i=0; i<N; ++i)
		{
			cin >> str;
			vStr.push_back(str);
		}
		sort(vStr.begin() , vStr.end() , cmp);
		//Êä³ö
		for(int i=0; i<N; ++i)
		{
			cout << vStr[i];
		}
		cout << endl;
	}
	return 0;
}
