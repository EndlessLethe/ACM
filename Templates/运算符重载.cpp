bool operator < (const Node& rhs) const {//从小到大排序 
		return r < rhs.r;
}
	
int cmp(int x, int v) const {
	if (x == v) return -1;
	return x < v ? 0 : 1;
}
