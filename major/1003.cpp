#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<math.h>

const int N=10;
//#define M 100
using namespace std;
 double G[N][N]={0},B[N][N]={0},e[N],f[N],P[N],Q[N],u1=1.06,a[N],b[N];
void show2(int n,double (*a)[N]){
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            printf("%lf ",a[i][j]);
        }
        cout<<endl;
    }
}
void show1(int n,double *a){
    for(int j=1;j<n;j++){
            printf("%lf ",a[j]);
     }
    cout<<endl;
}

void inputdata(int *n,int *m,double(*g)[N],double(*b)[N]){
    int i,j;
    double y,u;
    scanf("%d%d",n,m);
    while(scanf("%d,%d",&i,&j)==2 && i!=0 && j!=0){
        scanf("%lf%lf",&y,&u);
        g[i][i]+=y/(y*y+u*u);
        g[j][j]+=y/(y*y+u*u);
        g[j][i]=g[i][j]=-y/(y*y+u*u);
       // cout<<g[i][j]<<endl;
        b[i][i]+=-u/(y*y+u*u);
        b[j][j]+=-u/(y*y+u*u);
        b[j][i]=b[i][j]=u/(y*y+u*u);
       // cout<<b[i][j]<<endl;
        if(i>j) *n=i;
        else *n=j;
    }
}
void input( int n, int m,double *e,double *f,double *p0,double *q0){
    int k=m+n+1;
    while(k--){
        scanf("%lf%lf",&e[k+1],&f[k+1]);}
    while(n--){
        scanf("%lf%lf",&p0[n+1],&q0[n+1]);}
    
}
void acquirepq(int n,int m,double *lp,double *lq){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+m+1;j++){
     lp[i]+=e[i]*(G[i][j]*e[j]-B[i][j]*f[j])+f[i]*(G[i][j]*f[j]+B[i][j]*e[j]);
     lq[i]+=f[i]*(G[i][j]*e[j]-B[i][j]*f[j])-e[i]*(G[i][j]*f[j]+B[i][j]*e[j]);
        }
    }
    for(int i=1;i<=n;i++){
       lp[i]=P[i]-lp[i];lq[i]=Q[i]-lq[i];
    }
}
void acquireab(int n,double *a,double *b){
    for(int i=1;i<=n;i++){
        a[i]=(P[i]*e[i]+(-Q[i])*(-f[i]))/(e[i]*e[i]+f[i]*f[i]);
        b[i]=((-Q[i])*e[i]-P[i]*(-f[i]))/(e[i]*e[i]+f[i]*f[i]);
    }

}
void acquireJ(int n,double (*H)[N],double (*N1)[N],double (*J)[N],double (*L)[N]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                H[i][j]=-B[i][j]*e[i]+G[i][j]*f[i]+b[i];
                 N1[i][j]=G[i][j]*e[i]+B[i][i]*f[i]+a[i];
                 J[i][j]=-G[i][j]*e[i]+B[i][j]*f[i]+a[i];
                L[i][j]=-B[i][j]*e[i]+G[i][j]*f[i]-b[i];
            }
            else{
                H[i][j]=-B[i][j]*e[i]+G[i][j]*f[i];
                 N1[i][j]=G[i][j]*e[i]+B[i][i]*f[i];
                 J[i][j]=-G[i][j]*e[i]+B[i][j]*f[i];
                L[i][j]=-B[i][j]*e[i]+G[i][j]*f[i];
            }
     }
    }
}
void acquirejmat(int n,double (*jj)[2*N],double (*H)[N],double (*N1)[N],double (*J)[N],double (*L)[N]){
    int k=1,p=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            jj[p][k++]=H[i][j];
            jj[p][k++]=N1[i][j];
        }
        k=1;p++;
        for(int j=1;j<=n;j++){
            jj[p][k++]=J[i][j];
            jj[p][k++]=L[i][j];
        }
        k=1;p++;
    }


}
int main(){
    double lp[N],lq[N],a[N],b[N];
    int n,m,s;
    //inputdata(&n,&m,G,B);
    input(n,m,e,f,P,Q);
    s=n+m+1;
    show1(s,e);
    cout<<endl;
    show1(s,f);
    return 0;
}

