#define MAXSIZE 1000
Typedef struct{
    ElemType data;
    int cur;
}component,SLinkList[MAXSIZE];
//若静态链表L中查找第一个值为e的元素；
//若找到，则返回它在L中的位序，否则返回0；
int LocateElem_SL(SLinkList S,ElemType e){
    i=S[0].cur;
    while(i&&S[i].data !=e){
        i=S[i].cur;
    }
    return i;
}//LocateElem_SL