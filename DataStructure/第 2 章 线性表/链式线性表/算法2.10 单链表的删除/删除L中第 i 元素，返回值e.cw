//在带头结点的单链线性表L中，删除第 i 个元素，并由e返回其值；
Status ListDelete_L(LinkList &L,int i,ElemType &e){
    p=L;j=0;
    while(p->next && j<i-1){  //p指向i-1结点；p<(头结点，尾结点-1)；不能指向尾结点；
        p=p->next;++j;
    }
    if(!(p->next)||j>i-1) return ERROR;
    q=p->next;p->next=q->next;
    e=q->data;free(q);
    return OK;
}//ListDelete_L