/**
 * @Author: EndlessLethe
 * @Date:   01-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: 后缀数组 LCP.cpp
 * @Last modified by: EndlessLethe
 * @Last modified time: 01-Apr-2017
 * @Copyright: ©2017 EndlessLethe. All rights reserved.
 * @Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stack>

char s[MAXN];
int sa[MAXN], t[MAXN], t2[MAXN], c[MAXN], n;
//数组s存放文本字符串s
//参数n代表字符串中字符的个数，这里的n里面是包括人为在字符串末尾添加的那个0的
//参数t代表字符串中字符的取值范围，是基数排序的一个参数，如果原序列都是字母可以直接取128
//如果原序列本身都是整数的话，则t可以取比最大的整数大1的值

void buildSa(int t) {
	int i, *x = t, *y = t2;
	//基数排序
	for (int i = 0; i < t; i++) c[i] = 0;
	for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
	for (int i = 1; i < t; i++) c[i] += c[i-1];
	for (int i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int k = 1; k <= n; k <<= 1) {
		int p = 0;
		for (int i = n-k; i < n; i++) y[p++] = i;
		for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i]-k;
		for (int i = 0; i < t; i++) c[i] = 0;
		for (int i = 0; i < n; i++) c[x[y[i]]]++;
		for (int i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1;
		x[sa[0]] = 0;
		for (int i = 1; i < n; i++) {
			x[sa[i]] = y[sa[i-1] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1 : p++;
		}
		if (p >= n) break;
		t = p;
	}
}

int rank[MAXN], height[MAXN];
void getHeight() {
	int i, j, k = 0;
	for (int i = 0; i < n; i++) rank[sa[i]] = i;
	for (int i = 0; i < n; i++) {
		if (k) k--;
		int j = sa[rank[i]-1];
		while (s[i+k] == s[j+k]) k++;
		height[rank[i]] = k;
	}
}

int main() {

	return 0;
}
