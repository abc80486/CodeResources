//在顺序线性表L中第i个位置之前插入新的元素e
Status ListInsert_Sq(SqList &L,int i,ElemType e){
    if(i<1||i>L.length+1) 
        return ERROR;
    if(L.length>=L.listsize){
        newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCEMENT)*sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCEMENT;
    }
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p)   //p指向q及之后的元素；
        *(p+1)=*p;        //p后移；
    *q=e;
    ++L.length;
    return OK;
}//ListInsert_Sq