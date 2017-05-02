int index, cntcc;//时间戳 强连通分量计数 
bool instack[MAX_V];//是否在栈中 
int dfn[MAX_V];//编号从1开始 
int scn[MAX_V];
struct edge{
	int from, to;
} V[MAX_V];

//输入：节点v 
//输出：v所属联通块中 所有的节点都获得一个强连通分量编号 
void tarjan(int i) {
    int j;
    dfn[i] = low[i] = ++index;
    instack[i] = true;
    st[++stp] = i;
    for (edge *e = V[i]; e; e = e->next) {
        j = e->to;
        if (!dfn[j]) {
            tarjan(j);
            if (low[j] < low[i])
                low[i] = low[j];
        }
        else if (instack[j] && dfn[j] < low[i])
            low[i] = dfn[j];
    }
    if (dfn[i] == low[i]) {
        cntsc++;
        do {
            j = st[stp--];
            instack[j] = false;
            scn[j] = cntsc;
        }
        while (j != i);
    }
}

//输出：对图的每一个联通块都进行一次tarjan，使每个节点获得编号 
void scc() {
    int i;
    stp = cntsc = index = 0;
    memset(dfn, 0, sizeof(dfn));
    for (i = 1; i <= N; i++)
        if (!dfn[i])
            tarjan(i);
}

//rG中存放缩点后的新图，顶点编号从0到cntsc-1
//新图保证是无环的，包括自环，所以DFS时不需要!used条件 
void newG() {
    for (int v = 0; v < V; v++){
        if ()
    }
}
