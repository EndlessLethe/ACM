int index, cntcc;//ʱ��� ǿ��ͨ�������� 
bool instack[MAX_V];//�Ƿ���ջ�� 
int dfn[MAX_V];//��Ŵ�1��ʼ 
int scn[MAX_V];
struct edge{
	int from, to;
} V[MAX_V];

//���룺�ڵ�v 
//�����v������ͨ���� ���еĽڵ㶼���һ��ǿ��ͨ������� 
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

//�������ͼ��ÿһ����ͨ�鶼����һ��tarjan��ʹÿ���ڵ��ñ�� 
void scc() {
    int i;
    stp = cntsc = index = 0;
    memset(dfn, 0, sizeof(dfn));
    for (i = 1; i <= N; i++)
        if (!dfn[i])
            tarjan(i);
}

//rG�д����������ͼ�������Ŵ�0��cntsc-1
//��ͼ��֤���޻��ģ������Ի�������DFSʱ����Ҫ!used���� 
void newG() {
    for (int v = 0; v < V; v++){
        if ()
    }
}
