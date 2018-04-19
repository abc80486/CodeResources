typedef struct{
    char *ch;
    int length;
}HString;
Status StrAssign(HString &T,char *chars);
int StrLength(HString S);
int StrCompare(HString S,HString T);
Status ClearString(HString &S);
Status Concat(HString &T,HString S1,HString S2);
HString SubString(HString S,int pos,int len);

Status StrAssign(HString &T,char *chars){
    if(T.ch) free(T.ch);
    for(i=0,c=chars;*c;++i,++c);
    if(!i){T.ch=NULL;  T.length=0}
    else{
        if(!(T.ch=(char *)malloc(i*sizeof(char))))
            exit(OVERFLOW);
        T.ch[0..i-1]=chars[0..i-1];
        T.length=i;
    }
    return OK;
}

int StrLength(HString S){
    return S.length;
}

int StrCompare(HString S,HString T){
    for(i=0;i<S.length && i<T.length;++i)
        if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
    return S.length-T.length;
}

Status ClearString(HString &S){
    if(S.ch) {free(S.ch);S.ch=NULL;}
    S.length=0;
    return OK;
}

Status Concat(HString &T,HString S1,HString S2){
    if(T.ch) free(T.ch);
    if(!)
}