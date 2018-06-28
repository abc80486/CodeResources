#include<cstdio>
#include<iostream>
#include<fstream>
#include<algorithm>
const int N=20;
//#define double long double
//#define lf 
//long double op[20][20];
using namespace std;
bool inversematrix(double (*s)[N],int n);
  void zeroline(int j,int i,int n,double(*a)[N]);
double determinant(int m,int n,double(*a)[N]);
  bool abjustzero(int set,int end,double(*a)[N]);
bool matrixch(int n,double(*a)[N]);
bool matrixnubmul(int n,double b,double(*a)[N]);
bool matrixmul(double (*p)[N],double (*y)[N],int a,int b,int c);
double pc(const int n,int h,int k,double(*a)[N]);
void ax(int n,double(*a)[N]);
bool output(int n,double(*a)[N],double *u,double *out);
double G[N][N]={0},B[N][N]={0},e[N],f[N],P[N],Q[N],u1=1.06,a[N],b[N];
double le[N],lf[N],lp[N],lq[N];
double h[N][N],n1[N][N],j1[N][N],l[N][N],pq[N];
//ofstream fout("out.txt");
double jj[N][N];
void show(int n,double(*p)[N]){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lf ",p[i][j]);
        }
        cout<<endl;
    }
 }
void zeroline(int j,int i,int n,double(*a)[N]){
   double k;
    k=-a[j][i]/a[i][i];
    for(int t=i;t<=n;t++){
        a[j][t]+=a[i][t]*k;
    }
}
double determinant(int m,int n,double(*a)[N]){

    double p=1.0;
    if(((n-m)==1)){
        p=a[m][m]*a[n][n]-a[m][n]*a[n][m];
    }
    else{
    for(int i=m;i<=n;i++){
        if(a[i][i]==0){
          if(abjustzero(i,n,a)==false){
            return 0;}
        }
        for(int j=i+1;j<=n;j++){
           if(a[j][i]!=0) {
               zeroline(j,i,n,a);
           }
        }
    }
    for(int i=1;i<=n;i++){
        p*=a[i][i];
    }}
    return p;
}

bool abjustzero(int set,int end,double(*a)[N]){
    int q=0;
    if(a[set][set]==0){
         for(int t=1;t<=end;t++){
                if(a[set][t]!=0){
                    int p;
                    q=1;
                    for(int u=1;u<=end;u++){
                        p=a[u][set];
                        a[u][set]=-a[u][t];
                        a[u][t]=p;
                    }
                    break;
                }
            }
            if(q==0) return false;
    }
    return true;
}
bool matrixch(int n,double(*a)[N]){
    //int a[n];
    double p;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            p=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=p;
        }
    }
    return true;
}
bool matrixnubmul(int n,double b,double(*a)[N]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]*=b;
        }
    }
    return true;
}
bool matrixmul(double (*p)[N],double *y,int a,int b,double *r){
    double s=0;
    for(int i=1;i<=a;i++){
            s=0.0;
            for(int j=1;j<=b;j++){
                s+=p[i][j]*y[j];
            }
            r[i]=s;
    }
    return true;
}
 bool inversematrix(double (*s)[N],int n){
     double p[N][N],k;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             p[i][j]=s[i][j];
         }
     }
     k=determinant(1,n,p);
     //show(n,p);
     //cout<<k<<endl;
     if(k!=0.0){
        ax(n,s);
         matrixnubmul(n,1.0/k,s);
         //show(n,s);
     }
     else {
         return false;
     }
     return true;
 }
bool output(int n,double(*a)[N],double *u,double *out){
    
    if(!inversematrix(a,n)) {
        //cout<<"error!";
        return false;
    }
    else {
        matrixmul(a,u,n,n,out);
    }
    return true;
}
double pc(const int n,int h,int k,double(*a)[N]){
    double s[N][N];
    int p=0,b=0;
    for(int i=1;i<=n;i++){
        if(i!=h){ 
            p++;
            b=0;
            for(int j=1;j<=n;j++){
                //b=1;
                if(j!=k){
                    b=b+1;
                    s[p][b]=a[i][j];
                   
                }
            }
           
        }
    }
    //show(n-1,s);
    if(((h+k)%2)==0){
        return determinant(1,n-1,s);
        
    }
    else{
        return -determinant(1,n-1,s);
    }
}
void ax(int n,double(*a)[N]){
    double t[N][N];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[j][i]=pc(n,i,j,a);
        }
    }
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             a[i][j]=t[i][j];
         }
     }
}
//double G[N][N]={0},B[N][N]={0},e[N],f[N],P[N],Q[N],u1=1.06,a[N],b[N];
void show2(int n,double (*a)[N]){
    ofstream fout("out.txt");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lf ",a[i][j]);
            fout<<a[i][j];
        }
        fout<<endl<<endl;
        cout<<endl<<endl;
    }
}
void show1(int n,double *a){
    ofstream fout("out.txt");
    for(int j=1;j<=n;j++){
            printf("%lf ",a[j]);
            fout<<a[j];
     }
    fout<<endl<<endl;
    cout<<endl<<endl;
}

void inputdata(int *n,int *m,double(*g)[N],double(*b)[N]){
    ifstream fin("gb.txt");
    int i,j;
    double y,u;
    //scanf("%d%d",n,m);
    fin>>*n>>*m;
    while(fin>>i>>j&& i!=0 && j!=0){
       // scanf("%lf%lf",&y,&u);
       fin>>y>>u;
        g[i][i]+=y/(y*y+u*u);
        g[j][j]+=y/(y*y+u*u);
        g[j][i]=g[i][j]=-y/(y*y+u*u);
       // cout<<g[i][j]<<endl;
        b[i][i]+=-u/(y*y+u*u);
        b[j][j]+=-u/(y*y+u*u);
        b[j][i]=b[i][j]=u/(y*y+u*u);
       // cout<<b[i][j]<<endl;
        
    }
}
void input( int n, int m,double *e,double *f,double *p0,double *q0){
    ifstream fin("efpq.txt");
    int k=m+n+1;
    for(int i=1;i<=n+m+1;i++){
        fin>>e[i]>>f[i];}
    for(int i=1;i<=n;i++){
        fin>>p0[i]>>q0[i];}
    
}
void acquirepqab(int n,int m){
    int k=1;
    for(int i;i<=n;i++){
        lp[i]=0.0;lq[i]=0.0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+m+1;j++){
     lp[i]+=e[i]*(G[i][j]*e[j]-B[i][j]*f[j])+f[i]*(G[i][j]*f[j]+B[i][j]*e[j]);
     lq[i]+=f[i]*(G[i][j]*e[j]-B[i][j]*f[j])-e[i]*(G[i][j]*f[j]+B[i][j]*e[j]);
        }
    }
    
    for(int i=1;i<=n;i++){
        a[i]=(lp[i]*e[i]+(-lq[i])*(-f[i]))/(e[i]*e[i]+f[i]*f[i]);
        b[i]=((-lq[i])*e[i]-lp[i]*(-f[i]))/(e[i]*e[i]+f[i]*f[i]);
       lp[i]=P[i]-lp[i];lq[i]=Q[i]-lq[i];
    }
    for(int i=1;i<=n;i++){
        pq[k++]=lp[i];
        pq[k++]=lq[i];}
}
void acquireJ(int n,double (*H)[N],double (*N1)[N],double (*J)[N],double (*L)[N]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                H[i][j]=(0.0-B[i][j])*e[i]+G[i][j]*f[i]+b[i];
                 N1[i][j]=G[i][j]*e[i]+B[i][i]*f[i]+a[i];
                 J[i][j]=(0.0-G[i][j])*e[i]+B[i][j]*f[i]+a[i];
                L[i][j]=(0.0-B[i][j])*e[i]+G[i][j]*f[i]-b[i];
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
void acquirejmat(int n,double (*jj)[N],double (*H)[N],double (*N1)[N],double (*J1)[N],double (*L)[N]){
    int k=1,p=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            jj[p][k++]=H[i][j];
            jj[p][k++]=N1[i][j];
        }
        k=1;p++;
        for(int j=1;j<=n;j++){
            jj[p][k++]=J1[i][j];
            jj[p][k++]=L[i][j];
        }
        k=1;p++;
    }


}
int main(){
    //double lp[N],lq[N];
   // double h[N][N],n1[N][N],j1[N][N],l[N][N];
    //ofstream fout("out.xt");
    //double jj[N][N];
    double out[N]={0.0};
    int n,m,s,k=0,c=1;;
   // double *er,*ew;
    inputdata(&n,&m,G,B);
    input(n,m,e,f,P,Q);
    s=n+m+1;
    do
    {
    printf("第 %d 次迭代\n",k);
    acquirepqab(n,m);
    acquireJ(n,h,n1,j1,l);
    acquirejmat(n,jj,h,n1,j1,l);
    //show2(2*n,jj);  
    show1(n,e);
    output(2*n,jj,pq,out);
    c=1;
    for(int i=1;i<=n;i++){
        lf[i]=out[c++];
        le[i]=out[c++];
     }
     //show1(n,)
    for(int i=1;i<=n;i++){
        e[i]+=le[i];
        f[i]+=lf[i];
    }
    k++;
      }
   while(k<=15);
       /*
        //cout<<"迭代过程中各节点的不平衡量："<<endl;
        for(int i=1;i<=n;i++){
            //cout<<lp[i]<<"+j"<<lq[i]<<"  ";
        }
        cout<<endl<<endl;
        
        //show2()
        
        //cout<<"迭代过程中各节点电压修正量："<<endl;
        for(int i=1;i<=n;i++){
           // cout<<le[i]<<"+j"<<lf[i]<<" ";
        }
       // cout<<endl<<endl<<"迭代过程中节点电压："<<endl;
        for(int i=1;i<=n;i++){
           // cout<<e[i]<<"+j"<<f[i]<<" "<<ends;
        }
       // cout<<endl<<endl<<"迭代过程中雅克比矩阵对角元："<<endl;
        for(int i=1;i<=n;i++){
            //cout<<h[i][i]<<"  "<<l[i][i]<<"  "<<ends;
        }
        cout<<endl<<endl;
        */
        
    //show1(n,e);
    //er=max_element(out+1,out+2*n);
    //ew=min_element(out+1,out+2*n);
    //k++;
    //cout<<*er;
   
    //show1(s,e);show1(s,f);show2(s,G);show2(s,B);
    //show1(n,P);show1(n,Q);show1(n,lp);show1(n,lq);
   // show1(n,a);show1(n,b);show2(n,h);
    /*
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
           printf("%lf ",jj[i][j]);
        }
        cout<<endl<<endl;
    }
    */
    //cout<<endl
    //show2(n,h);show2(n,n1);show2(n,j1);show2(n,l);
    //show1(2*n,pq);
    //show1(2*n,out);
    return 0;
}
