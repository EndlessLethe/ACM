#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
	int N, K,a , b, maxLen = 0, total = 0;
	cin >> N >> K;
	for (int i = 0; i< N; i++) {
		cin >> a >> b;
		total += a * b;
		a = min(a, b);
		maxLen = max(maxLen, a);
	}
	for (int i = maxLen; i > 0; i--) {
		if (total - maxLen*maxLen >=K) break;
	}
	cout << maxLen << endl;
	return 0;
}
