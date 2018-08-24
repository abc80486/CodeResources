Status CreateGraph(MGraph &G){
    scanf(&G.kind);
    switch(G.kind){
        case DG:return CreateDG(G);
        case DN:return CreateDN(G);
        case UDN:return CreateUDN(G);
        case UDG:return CreateUDG(G);
        default:return ERROR;
    }//switch
}//CreateGraph