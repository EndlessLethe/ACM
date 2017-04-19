int V;
vector<int> G[MAX_V];//图的邻接表表示 
vector<int> rG[MAX_V];//把边反向后的图 
vector<int> vs;//后序遍历的顶点序列 
bool used[MAX_V];//访问标记 
int cmp[MAX_V];//所属强连通分量的拓扑序 

void add_edge(int from, int to) {//add_edge(a-1, b-1)
	G[from].push_back(to);
	G[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++) {
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}

//输入：v为搜索的节点编号， k为所属的强连通分量编号
//输出：标记节点v的used和强连通分量编号 
void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for(int i = 0; i < rG[v].size(); i++) {
        if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

//输出：图中的强连通分量数目 
int scc() {
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < V; v++) {
		if (!used[v]) dfs(v);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

//rG中存放缩点后的新图，顶点编号从0到k-1
//且0 - k-1正是缩完点后的拓扑序 
int newG() {
	for(int i = 1; i <= V; i++) while (!rG[i].empty()) rG[i].pop_back();
    for(int v = 1; v <= V; v++){
        for(int i = 0; i < G[v].size(); i++){
            int to = G[v][i];
            if(cmp[v] != cmp[to]){
                rG[cmp[v]].push_back(cmp[to]);
            }
        }
    }
}
