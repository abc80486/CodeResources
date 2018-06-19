#include<cstdio>
#include<cstring>
#include<fstream>
#include<math.h>
#define N 100
#define M 100
using namespace std;
 double G[N][N],B[N][N],e[N],f[N],P[M],Q[M];
int note,pqnote;
void DataInput(){
    ifstream fin("indata.txt");
    fin>>note>>pqnote;
    for(int j=1;j<=note;j++)
        for(int i=1;i<=note;i++) fin>>G[j][i];
    for(int j=1;j<=note;j++)
        for(int i=1;i<=note;i++) fin>>B[j][i];
    for(int i=1;i<=note;i++) fin>>e[i];
        
    for(int i=1;i<=note;i++) fin>>f[i];

    for(int j=1;j<=pqnote;j++) fin>>P[j]>>Q[j];
 
}
int main(){
     double  P0[M]={0.0},Q0[M]={0.0},DP[M],DQ[M],aii[M],bii[M];
    DataInput();

    for(int i=2;i<=note;i++){
        for(int j=1;j<=note;j++)    {
            P0[i]+=e[i]*(G[i][j]*e[j]-B[i][j]*f[j])+f[i]*(G[i][j]*f[j]+B[i][j]*e[j]);
            Q0[i]+=f[i]*(G[i][j]*e[j]-B[i][j]*f[j])-e[i]*(G[i][j]*f[j]+B[i][j]*e[j]);
        }
    }
    for(int i=2;i<=note;i++){
        DP[i]=P[i]-P0[i];
        DQ[i]=Q[i]-Q0[i];
    }
    for(int i=2;i<=note;i++){
        aii[i]=(P0[i]*e[i]+(-Q0[i])*(-f[i]))/(e[i]*e[i]+f[i]*f[i]);
        bii[i]=((-Q0[i])*e[i]-P0[i]*(-f[i]))/(e[i]*e[i]+f[i]*f[i]);
    }
    for(int i=2;i<=note;i++) printf("%f ",P0[i]); 
    printf("\n"); 
    while(1);
    return 0;
   
}