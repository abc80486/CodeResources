void Free_SL(SLinkList &space,int k){
    space[k].cur=space[0].cur;
    space[0].cur=k;
}//Free_SL