//��ȡ���룺 
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

//lenΪǰ���ǵĳ��ȣ���ʼ��Ϊ0
//�ߵı�Ŵ�1��ʼ
void insert(int from, int to, int cost) {
	e[++len].next = head[from];
	head[from] = len;
	e[len].to = to;
	e[len].w = cost;
}

//��ʼʱ�ĵ���
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

//������������ȱ���dfs(v, 0)
//����֤��һ�������Ĳ�����logN,���ܵĸ��ӶȲ�����NlogN
void dfs(int v, int fa) {
	deep[++deep[0]] = d[v];//deep������¼�����������Ϣ
	for (int i = head[v]; i; i = e[i].next) {
		if (e[i].to == fa || vis[e[i].to]) continue;
		d[e[i].to] = d[v] + e[i].w;
		dfs(e[i].to, v);
	}
}

//���ڸ��ļ������cal(v, 0);
int cal(int v, int w) {
	d[v] = w;
	deep[0] = 0;
	dfs(v, 0);
	//����deep����Ϣ������Ӧ���
	//deep�Ĵ洢��deep[1]��ʼ, ��deep[deep[0]]����(��deep[0]) 
	return 0;
}

void solve(int v) {
	ans += cal(v, 0);
	vis[v] = 1;
	for (int i = head[i]; i; i = e[i].next) {
		if (vis[e[i].to]) continue;
		ans -= cal(e[i].to, e[i].w);//��������ȥ���ظ��Ĳ���
		sum = son(e[i].to);//��ʼ������������
		root = 0;
		getroot(e[i].to, 0);
		solve(root);
	}
}
