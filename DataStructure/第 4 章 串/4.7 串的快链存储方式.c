//串的块链存储方式其实就是链表的特例，链表的节点只能是字符，
//一个结点既可以包含一个字符也可以包含多个字符；
#typedef CHUNKSIZE 80
typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;
//结点类型；
typedef struct{
    Chunk *head,*tail;
    int curlen;
}LString;
//链表类型；