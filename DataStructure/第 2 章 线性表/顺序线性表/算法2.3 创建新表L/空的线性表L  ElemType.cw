//构建一个空的线性表L；
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
Status InitList_sq(Sqlist &L){
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}//InitList_Sq