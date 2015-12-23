int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        int a[100020] = {0},b[100200] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d",&b[i]);
        }
        sort(a, a+n);
        sort(b, b+m);
        int count1 = 0;
        int count2 = 0;
        int sum = 0;
        while (count1<n&&count2<m) {
            if (a[count1] <= b[count2]) {
                sum++;
                count1++;
                count2++;
            }else{
                count2++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
