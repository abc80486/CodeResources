//在带头结点的单链线性表L中第 i 个位置之前插入元素e；
Status ListInsert_L(LinkList &L,int i,ElemType e){
    p=L;
    j=0;
    while(p&&j<i-1){  //p指向第i-1个结点；p<(头结点，尾结点)；
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
        return ERROR;
    s=(LinkList)malloc(sizeof(LNode)); //s插入L中；
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}//ListInsert_L