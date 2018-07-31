#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct ArcCell{
    VRTyp adj;
    InfoType *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
    GraphKind kind;
}MGraph;
Status CreateGraph(MGraph &G){
    scanf(&G.kind);
    switch(G.kind){
        case DG:return CreateDG(G);
        case DN:return CreateDN(G);
        case UDG:return CreateUDG(G);
        case UDN:return CreateUDN(G);
        default:return ERROR;
    }
}
Status CreateUDN(MGraph &G){
    scanf(&G.vexnum,&G.arcnum,&IncInfo);
    for(i=0;i<G.vexnum;i++) scanf(&G.vexs[i]);
    for(i=0;i<G.vexnum;++i)
        for(j=0;j<G.vexnum;++j) G.arcs[i][j]={INFINITY,NULL};
    for(k=0;k<G.arcnum;++k){
        scanf(&v1,&v2,&w);
        i=LocateVex(G,v1);j=LocateVex(G,v2);
        G.arcs[i][j].adj=w;
        if(IncInfo) Input(*G.arcs[i][j].info);
        G.arcs[j][i]=G.arcs[i][j];
    }
    return OK;
}