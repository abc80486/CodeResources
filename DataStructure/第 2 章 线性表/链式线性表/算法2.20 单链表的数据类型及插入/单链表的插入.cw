typedef struct LNode{
    ElemType data;
    struct LNode *next;
}*Link,*Position;

typedef struct{
    Link head,tail;
    int len;
}LinkList;
Status MakeNode(Link &p,ElemType e);
void FreeNode(Link &p);
Status InitList(LinkList &L);
Status DestroyList(LinkList &L);
Status ClearList(LinkList &L);
Status InsFirst(Link h,Link s);
Status DelFirst(Link h,Link &q);
Status Append(LinkList &L,List s);
Status Remove(LinkList &L,Link &q);
Status InsBefore(LinkList &L,Link &q,Link s);
Status InsAfter(LinkList &L,Link &q,Link s);
Status SetCurElem(Link &p,ElemType e);
ElemType GetCurElem(Link p);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L,Link p);
Position NextPos(LinkList L,Link p);
Status LocatePos(LinkList L,int i,Link &p);
Position LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));
Status ListTraverse(LinkList L,Status(*visit)());









