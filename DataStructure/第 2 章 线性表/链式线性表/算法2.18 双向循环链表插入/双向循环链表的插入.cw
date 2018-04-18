typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;
//在带头结点的双链循环线性表L中第i个位置之前插入元素e
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
    if(!(p=GetElemP_Dul(L,i)))
        return ERROR;
    if(!(s=(DuLinkList)malloc(sizeof(DuLNode)))) return ERROE;
    s->data=e;
    s->prior=p->prior;
    s->next=p;
    return OK;
}//ListInsert_DuL
