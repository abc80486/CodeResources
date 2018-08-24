//逆位序输入n个元素的值，建立带表头结点的单链线性表L；
void CreateList_L(LinkList &L,int n){
    L=(LinkList) malloc (sizeof(LNode));
    L->next=NULL;
    for(i=n;i>0;--i){
        p=(LinkList)malloc(sizeof (LNode));
        scanf(&p->data);
        p->next=L->next;
        L->next=p;
    }
}//CreateList_L