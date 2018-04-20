#define MaxBookNum 1000
#define MaxKeyNum 2500
#define MaxLineLen 500
#define MaxWordNum 10
typedef struct{
    char *item[];
    int last;
}WordListType;
typedef int ElemType;
typedef struct{
    HString key;
    LinkList bnolist;
}IdxTermType;
typedef struct{
    IdxTermType item[MaxKeyNum+1];
    int last;
}IdxListType;
char *buf;
WordListType wdlist;
void InitIdxList(IdxListType &idxlist);
void GetLine(FILE f);
void ExtracKeyWord(ElemType &bno);
Status InsIdxList(IdxListType &idxlist,ElemType bno);
void PutText(FILE g,IdxListType idxlist);
void main(){
    if(f=openf("BookInfo.txt"."r"))
        if(g=openf("BookIdx.txt","w"))
            InitIdxList(idxlist);
            while(!foef(f)){
                GetLine(f);
                ExtractKeyWord(BookNo);
                InsIdxList(idxlist,BookNo);
            }
            PutText(g,idxlist);
}
void GetWord(int i,HString &wd);
int Locate(IdxListType idxlist,HString wd,Boolean &b);
void InsertNewKey(IdxListType &idxlist,int i,HString wd);
Status InsertBook(IdxListType &idxlist,int i,int bno);
Status InsIdxList(IdxListType &idxlist,int bno){
    for(i=0;i<wdlist.last;++i){
        GetWord(i.wd); j=Locate(idxlist,wd,b);
        if(!b) InsertNewKey(idxlist,j,wd);
        if(!InsertBook(idxlist,j,bno)) return OVERFLOW;
    }
    return OK; 
}
void GetWord(int i,HString &wd){
    p=*(wdlist.item + i);
    StrAssign(wd,p);
}
int Locate(IdxListType &idxlist,HString wd,Boolean &b){
    for(i=idxlist.last-1;(m=StrCompare(idxlist.item[i].key))>0;i++);
    if(m==0){b=TRUE;return i;}
    else{b=False;return i+1;}
}
void InsertNewKey(int i,StrType wd){
    for(j=idxlist.last-1;j>=i;--j)
        idxlist.item[j+1]=idxlist.item[j];
    StrCopy(idxlist.item[i].key,wd);
    InitList(idxlist.item[i].bnolist);
    ++idxlist.last;
}
Status InsertBook(IdxListType &idxlist,int i,int bno){
    if(!MakeNode(p,bno)) return ERROR;
    Appand(idxlist.item[i].bnolist,p);
    return OK;
}