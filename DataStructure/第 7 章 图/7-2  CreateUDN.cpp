Status CreateUDN(MGraph &G){
    scanf(&G.vexnum,&G.arcnum,&InxInfo);
    for(int i=0;i<G.vexnum;++i) scanf(&G.vexs[i]);
    for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.vexnum;++j) G.arc[i][j]={INFINITY,NULL};
    for(int k=0;k<G.arcnum;k++){
        scanf(&v1,&v2,&w);
        i=LocateVex(G,v1);j=LocateVex(G,v2);
        G.arcs[i][j].adj=w;
        if(IncInfo) Input(*G.arcs[i][j].info);
        G.arcs[j][i]=G.arcs[i][j];
    }
    return OK;
}//CreatUDN