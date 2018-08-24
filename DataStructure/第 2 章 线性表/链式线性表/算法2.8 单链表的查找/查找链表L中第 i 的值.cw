//L为带头结点的单链表的头指针；
//当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR;
Status GetElem_L(LinkList L,int i,ElemType &e){
    p=L->next;
    j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    e=p->data;
    return OK;
}//GetElem_L

//线性表的单链表存储结构；
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;