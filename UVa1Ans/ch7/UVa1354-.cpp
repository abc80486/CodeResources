#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
double val[10],l[105],r[105],w[10],ans,room;
int n,t[105],visit[105];
int judge(int x){
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(val,0,sizeof(val));
    for(int i=x;i;i--){
        if(t[i]==-1){
            int x=i*2,y=i*2+1;
            val[i]=val[y]+val[x];
            double L=val[y]/val[i];
            double R=val[x]/val[i];
            l[i]=min(-L+l[x],R+l[y]);
            r[i]=max(-L+r[x],R+r[y]);
        }
        else if(t[i]){
            val[i]=w[t[i]];
        }
    }
    double a=r[1]-l[1];
    if (a-room<0.00005) ans=max(ans,a);
}
int dfs(int num,int sit,int use){
    if(use==0){
        judge(num-1);
        return 0;
    }
    if(t[num/2]!=-1){
        dfs(num+1,sit,use);
    }
    else{
        if(use>sit){
            t[num]=-1;
            dfs(num+1,sit+1,use);
            t[num]=0;
        }
        if(sit==1&&use>1) return 0;
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                visit[i]=1;
                t[num]=i;
                dfs(num+1,sit-1,use-1);
                visit[i]=0;
                t[num]=0;
            }
        }
    }
}
int main(){
    int tot;
    scanf("%d",&tot);
    while(tot--){
        scanf("%lf%d",&room,&n);
        memset(w,0,sizeof(w));
        memset(t,0,sizeof(t));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
            scanf("%lf",&w[i]);
        ans=-1;
        t[1]=-1;
        if(n==1){
            printf("%.10lf\n",0.0);
        }
        else{
            dfs(2,2,n);
            if(ans==-1) printf("-1\n");
            else printf("%.10lf\n",ans);
        }
    }
    return 0;
}