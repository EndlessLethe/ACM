int V;
vector<int> G[MAX_V];//ͼ���ڽӱ��ʾ 
vector<int> rG[MAX_V];//�ѱ߷�����ͼ 
vector<int> vs;//��������Ķ������� 
bool used[MAX_V];//���ʱ�� 
int cmp[MAX_V];//����ǿ��ͨ������������ 

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

//���룺vΪ�����Ľڵ��ţ� kΪ������ǿ��ͨ�������
//�������ǽڵ�v��used��ǿ��ͨ������� 
void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for(int i = 0; i < rG[v].size(); i++) {
        if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

//�����ͼ�е�ǿ��ͨ������Ŀ 
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

//rG�д����������ͼ�������Ŵ�0��k-1
//��0 - k-1����������������� 
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
