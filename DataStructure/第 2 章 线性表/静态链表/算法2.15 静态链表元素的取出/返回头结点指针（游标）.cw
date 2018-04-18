int Malloc_SL(SLinkList &space){
    i=space[0].cur;
    if(space[0]){
        space[0].cur=space[1].cur;
    }
    return i;
}//Malloc_SL

