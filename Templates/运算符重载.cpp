bool operator < (const Node& rhs) const {//��С�������� 
		return r < rhs.r;
}
	
int cmp(int x, int v) const {
	if (x == v) return -1;
	return x < v ? 0 : 1;
}
