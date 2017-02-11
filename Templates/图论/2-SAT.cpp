//具体的建图规则为：
//若 a and b ==1 , !a->a , !b -> b   
//	a and b ==0 , a->!b , b->!a
//    a or b ==1 , !a->b , !b->a
//    a or b ==0 , a->!a , b->!b
//    a xor b ==1 , a->!b,!b->a,!a->b,b->!a
//    a xor b ==0 , a->b,b->a,!a->!b,!b->!a

const int MAX = 1010;
vector <int> G[MAX], rG[MAX], vs;
bool used[MAX];
int cmp[MAX];
char cmd[5];
int V;


void add_edge(int from, int to) {
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		if (!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i< rG[v].size(); i++) {
		if (!used[rG[v][i]]) {
			rdfs(rG[v][i], k);
		}
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < V; v++) {
		if(!used[v]) dfs(v);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size()-1; i >= 0; i--) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

int main()
{
	int is_false, u, v, c, n, M;
    scanf("%d%d", &n, &M);
    	V = 2 * n;
    	for (int i = 0; i < V; i++) {
    		G[i].clear();
    		rG[i].clear();
		}
		is_false = 0;
		memset(cmp, 0, sizeof(cmp)); 
		
		for (int i = 0; i < M; i++) {
			memset(cmd, 0, sizeof(cmd));
			scanf("%d%d%d%s", &u, &v, &c, cmd);
			if ((cmd[0] == 'A') && (c == 1)) {
				add_edge(u+n, u);
				add_edge(v+n, v);
			}
			else if ((cmd[0] == 'A') && (c == 0)) {
				add_edge(u, v+n);
				add_edge(v, u+n);
			}
			else if ((cmd[0] == 'O') && (c == 1)) {
				add_edge(u+n, v);
				add_edge(v+n, u);
			}
			else if ((cmd[0] == 'O') && (c == 0)) {
				add_edge(u, u+n);
				add_edge(v, v+n);
			}
			else if ((cmd[0] == 'X') && (c == 0)) {
				add_edge(u, v);
				add_edge(v, u);
				add_edge(u+n, v+n);
				add_edge(v+n, u+n);
			}
			else if ((cmd[0] == 'X') && (c == 1)) {
				add_edge(u, v+n);
				add_edge(v, u+n);
				add_edge(v+n, u);
				add_edge(u+n, v);
			}
		}
		
		scc();
		
		for (int i = 0; i < n; i++) {
			if (cmp[i] == cmp[i+n]) {
				printf("NO\n");
				is_false = 1; 
				break;
			}
		}
		if (!is_false) printf("YES\n");
	
    return 0;
}
