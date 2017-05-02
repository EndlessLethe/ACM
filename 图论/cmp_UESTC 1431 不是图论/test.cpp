#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define MAX_V 30010

int V;
vector<int> G[MAX_V];//图的邻接表表示 
vector<int> rG[MAX_V];//把边反向后的图 
vector<int> vs;//后序遍历的顶点序列 
bool used[MAX_V];//访问标记 
int scn[MAX_V];//所属强连通分量的拓扑序 

void add_edge(int from, int to) {//add_edge(a-1, b-1)
	G[from].push_back(to);
	rG[to].push_back(from);
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
    scn[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
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
//新图保证是无环的，包括自环，所以DFS时不需要!used条件 
void newG() {
	for (int i = 0; i < V; i++) if (!rG[i].empty()) rG[i].clear();
    for (int v = 0; v < V; v++){
        for (int i = 0; i < G[v].size(); i++) {
            int to = G[v][i];
            if (scn[v] != scn[to]) {
                rG[scn[v]].push_back(scn[to]);
            }
        }
    }
}

//以上为scc模板 
int val[MAX_V];
int valsc[MAX_V];
int ans[MAX_V];

void DFS(int v, int sum) {
	ans[v] = max(ans[v], sum + valsc[v]);
    for (int i = 0; i < rG[v].size(); i++) {
        DFS(rG[v][i], ans[v]);
    }
}

int main() {
	//freopen("input_UESTC 1431 不是图论.txt", "r", stdin);
//	freopen("in.txt", "r", stdin);
//	freopen("test.out", "w", stdout);
	int N, M, a, b, maxNum;
	while (scanf("%d%d", &N, &M) == 2) {
		maxNum = 0;
		memset(val, 0, sizeof(val));
		memset(valsc, 0, sizeof(valsc));
		memset(ans, 0, sizeof(ans));
		V = N;
		for (int i = 0; i < N; i++) {
			scanf("%d", &val[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d%d", &a, &b);
			add_edge(a-1, b-1);
		}
		int k = scc();
//		printf("k: %d\n", k);
		newG();
		for (int i = 0; i < N; i++) {
			valsc[scn[i]] += val[i];//为新图的点赋值 
		}
//		for (int i = 0; i < k; i++) printf("%d: %d\n", i, valsc[i]);
		for (int i = 0; i < k; i++) {
			DFS(i, 0);
		}
		for (int i = 0; i < k; i++) {
			//printf("ans %d: %d\n", i, ans[i]);
			maxNum = max(maxNum, ans[i]);
		}
		printf("%d\n", maxNum);
		for (int i = 0; i < N; i++) if (!G[i].empty()) G[i].clear();
		for (int i = 0; i < k; i++) if (!rG[i].empty()) rG[i].clear(); 
	}
}
