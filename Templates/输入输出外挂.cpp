//∂¡»° ‰»Î£∫ 
//while (1) {
//	n = read(), k = read();
//	if (n == 0 && k == 0) break;
//} 
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

inline void out(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x >= 10) out(x / 10);
	putchar(x % 10 + '0');
}
