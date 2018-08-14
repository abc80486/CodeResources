#include<iostream>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int score[m],ans[m];
    for(int i=0;i<m;i++) scanf("%d",&score[i]);
    for(int i=0;i<m;i++) scanf("%d",&ans[i]);
    while(n--){
        int sum=0,a;
        for(int i=0;i<m;i++){
            scanf("%d",&a);
            if(a==ans[i]) sum+=score[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}