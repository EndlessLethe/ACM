#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include<iomanip>
using namespace std;

const int MAXN = 250000 + 50;
int input[MAXN];

void swap(int a[], int x, int y) {
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void quickSort(int a[], int l, int r) {
	if (l >= r) return;
	int st = l, end = r;
	
	//三哨兵
	int mid = l + ((r-l)>>1);
	if (a[mid] > a[r]) swap(a, mid, r);
    if (a[l] > a[r]) swap(a, l, r);
    if (a[mid] > a[l]) swap(a, mid, l); 
	
	while (st < end) {
		while (st < end && a[l] <= a[end]) end--;
		while (st < end && a[l] >= a[st]) st++;
		swap(a, end, st);
	}
	swap(a, st, l);
	
	//三路划分 
	for (int i = l; i < st; i++) {
		if (a[i] == a[st]) {
			a[i] = a[--st];
			a[st] = a[st+1];
		}
	}
	for (int i = r; i > end; i--) {
		if (a[i] == a[end]) {
			a[i] = a[++end];
			a[end] = a[end-1];
		}
	}

	quickSort(a, l, st-1);
	quickSort(a, end+1, r);
	return;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	quickSort(input, 0, N);
	double res = N%2?input[N/2+1]:((double)input[N/2]+input[N/2+1])/2;
	cout << setiosflags(ios::fixed) << setprecision(1) << res << endl;
	return 0;
}
