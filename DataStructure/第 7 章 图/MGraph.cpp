#include<cstdio>
#include<cstring>
using namespace std;
#define MAXVERTEX 501
#define VEXLENG 20
//#define INFINITY INT_MAX;
typedef struct{
    char Vertex[MAXVERTEX][VEXLENG]={NULL};
    int arcs[MAXVERTEX][MAXVERTEX]={0};
    int vexnum=0,arcnum=0;
    int GraphKind=1;//1代表无向图，2无向网，3有向图，4有向网；
}MGraph;
bool CreatGraph(MGraph &G){
    int v1,v2,w;
    scanf("%d %d",&G.GraphKind,&G.vexnum);
    if(G.vexnum==0) return false;
    for(int i=1;i<=G.vexnum;i++) scanf("%s",G.Vertex[i]);
    for(int i=1;i<=G.vexnum*(G.vexnum-1)/2;i++){
        scanf("%d,%d,%d",&v1,&v2,&w);
        G.arcs[v1][v2]=w;
        if(G.GraphKind==1||G.GraphKind==2) G.arcs[v2][v1]=G.arcs[v1][v2];
        G.arcnum++;
    }
    return true;
}
int LocateVex(MGraph &G,char *u){
    int i,j;
    for( i=1;i<=G.vexnum;i++){
       for( j=0;u[j]!='\0';j++){
           if(u[j]!=G.Vertex[i][j]) break;
       }
       if(G.Vertex[i][j]==u[j]) return i;
    }
    return 0;
}
int main(){
    MGraph g1;
    char u[VEXLENG];
    if(CreatGraph(g1)){
         scanf("%s",u);
         printf("%d",LocateVex(g1,u));
     }
    return 0;
}


