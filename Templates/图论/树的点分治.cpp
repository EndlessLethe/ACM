//读取输入： 
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

//len为前向星的长度，初始化为0
//边的编号从1开始
void insert(int from, int to, int cost) {
	e[++len].next = head[from];
	head[from] = len;
	e[len].to = to;
	e[len].w = cost;
}

//开始时的调用
//f[0] = INF; root = 0; sum = n; getroot(1, 0); solve(root);
void getroot(int v, int fa) {
	size[v] = 1;
	f[v] = 0;
	for (int i = head[v]; i; i = e[i].next) {
		if (e[i].to == fa || vis[e[i].to]) continue;
		getroot(e[i].to, v);
		size[v] += size[e[i].to];
		f[v] = max(f[v], size[e[i].to]);
	}
	f[v] = max(f[v], sum - size[v]);
	if (f[x] < f[root]) root = x;
}

//对子树进行深度遍历dfs(v, 0)
//可以证明一共找重心不超过logN,故总的复杂度不超过NlogN
void dfs(int v, int fa) {
	deep[++deep[0]] = d[v];//deep用来记录子树各点的信息
	for (int i = head[v]; i; i = e[i].next) {
		if (e[i].to == fa || vis[e[i].to]) continue;
		d[e[i].to] = d[v] + e[i].w;
		dfs(e[i].to, v);
	}
}

//对于根的计算调用cal(v, 0);
int cal(int v, int w) {
	d[v] = w;
	deep[0] = 0;
	dfs(v, 0);
	//根据deep的信息计算相应结果
	//deep的存储从deep[1]开始, 到deep[deep[0]]结束(含deep[0]) 
	return 0;
}

void solve(int v) {
	ans += cal(v, 0);
	vis[v] = 1;
	for (int i = head[i]; i; i = e[i].next) {
		if (vis[e[i].to]) continue;
		ans -= cal(e[i].to, e[i].w);//在子树中去掉重复的部分
		sum = son(e[i].to);//开始给子树找重心
		root = 0;
		getroot(e[i].to, 0);
		solve(root);
	}
}
