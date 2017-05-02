#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define MAX_V 30010

int V;
vector<int> G[MAX_V];//ͼ���ڽӱ��ʾ 
vector<int> rG[MAX_V];//�ѱ߷�����ͼ 
vector<int> vs;//��������Ķ������� 
bool used[MAX_V];//���ʱ�� 
int scn[MAX_V];//����ǿ��ͨ������������ 

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

//���룺vΪ�����Ľڵ��ţ� kΪ������ǿ��ͨ�������
//�������ǽڵ�v��used��ǿ��ͨ������� 
void rdfs(int v, int k) {
    used[v] = true;
    scn[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
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
//��ͼ��֤���޻��ģ������Ի�������DFSʱ����Ҫ!used���� 
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

//����Ϊsccģ�� 
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
	//freopen("input_UESTC 1431 ����ͼ��.txt", "r", stdin);
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
			valsc[scn[i]] += val[i];//Ϊ��ͼ�ĵ㸳ֵ 
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
