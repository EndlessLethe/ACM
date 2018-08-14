#pragma comment(linker, "/STACK:102400000,102400000")

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

const int LEN = 100000000;
const int RANGE = 0x7fffffff;
//const int RANGE = LEN / 10;
//const int RANGE = 1000;
int input[LEN];
int RANDOM;

void swap(int a[], int x, int y) {
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void insertSort(int a[], int l, int r) {
	if (l >= r) return;
	for (int i = l+1; i <= r; i++) {
		for (int j = i-l; j >= 1; j--) {
			if (a[j] >= a[j-1]) break;
			swap(a, l+j, l+j-1);
		}
	}
}

void quickSort(int a[], int l, int r) {
	if (l >= r) return;
	int st = l, end = r;
	
	//三哨兵
	int mid = l + ((r-l)>>1);
	if (a[mid] > a[r]) swap(a, mid, r);
    if (a[l] > a[r]) swap(a, l, r);
    if (a[mid] > a[l]) swap(a, mid, l); 
	
	//随机选取哨兵 使用不同随机数 
//	int randn = rand() % (r-l) + l;
//	swap(a, l, randn);

	//随机选取哨兵  只用同一个随机数
//	int tmp = RANDOM % (r-l) + l;
//	swap(a, l, tmp);
	
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
	
	//插入排序优化 
//	if (st-1 - l > 10) quickSort(a, l, st-1);
//	else insertSort(a, l, st-1);
//	if (r - end-1 > 10) quickSort(a, end+1, r);
//	else insertSort(a, end+1, r);
	
	quickSort(a, l, st-1);
	quickSort(a, end+1, r);
	return;
}

int main() {
	srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
	RANDOM = rand();
	for (int i = 0; i < LEN; i++) {
		input[i] = rand() % RANGE;
//		input[i] = LEN - i;
	}
	
    double start, stop, durationTime;
    
    start = clock();
    quickSort(input, 0, LEN);
    stop = clock();

    durationTime = ((double)(stop-start))/CLK_TCK;
    cout << "程序耗时：" << durationTime << " s" << endl;

	
	for (int i = 0; i < 100; i++) printf("%d ", input[i]);
	return 0;
}


// 1e7 random 3.751s
// 1e7 repeat 79.822s
// 1e7 reverse INF

//随机选取 只用同一个随机数 
// 1e7 random 3.845s
// 1e7 repeat 79.762s
// 1e7 reverse 2.512s

// 随机选取 使用多个随机数
// 1e7 random 3.985s
// 1e7 repeat 81.489s
// 1e7 reverse 10.472s

// 三哨兵
// 1e7 random 3.69s
// 1e7 repeat 81.216s
// 1e7 reverse 0.936s

// 三路划分 
// 1e7 random 1.53s
// 1e7 repeat 1.066s
// 1e7 reverse INF

// 三哨兵+三路划分 
// 1e7 random 1.67s
// 1e8 random 16.598s

// 三哨兵+三路划分+插入排序 
// 1e7 random 1.599s
// 1e8 random 16.868s
