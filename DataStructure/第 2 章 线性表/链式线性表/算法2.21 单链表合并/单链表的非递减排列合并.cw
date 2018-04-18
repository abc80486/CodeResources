Status MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc,int(*compare)(ElemType,ElemType){
    if(!InitList(Lc)) return ERROR;
    ha=GetHead(La);hb=GetHead(Lb);
    pa=NextPos(La,ha);pb=NextPos(Lb,hb);
    while(pa&&pb){
        a=GetCurElem(pa);b=GetCurElem(pb);
        if((*compare)(a,b)<=0){
            DelFirst(ha,q);Append(Lc.q);pa=NextPos(La,ha);
        }
        else{
            DelFirst(hb,q);Append(Lc,q);pb=NextPos(Lb,hb);
        }
    }
    if(pa) Append(Lc,pa);
    else Append(Lc,pb);
    FreeNode(ha);
    FreeNode(hb);
    return OK;
}