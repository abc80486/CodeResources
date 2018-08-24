typedef struct{
    char *ch;
    int length;
}HString;
Status StrAssign(HString &T,char *chars);
 //生成一个其值等于某一字符串的串；
int StrLength(HString S);
//返回串的长度；
int StrCompare(HString S,HString T);
//比较两个串的大小；通过返回值反映结果；
Status ClearString(HString &S);
//清空某串，释放空间；
Status Concat(HString &T,HString S1,HString S2);
//联接两个串为一个新串，需要考虑新串的空间大小；
HString SubString(HString S,int pos,int len);
//求某串的子串；
Status StrAssign(HString &T,char *chars){
    //生成一个与串常量等值的新串；
    if(T.ch) free(T.ch);
    //对新串基址归零；
    for(i=0,c=chars;*c;++i,++c);
    //计算常量串的长度；
    if(!i){T.ch=NULL;  T.length=0}
    //如果常量串长度为零，直接构建新串；否则创建新空间；
    else{
        if(!(T.ch=(char *)malloc(i*sizeof(char))))
            exit(OVERFLOW);
            //分配常量串大小的空间；
        T.ch[0..i-1]=chars[0..i-1];
        //将常量串复制到新串；
        T.length=i;
        //设置新串长度；
    }
    return OK;
}

int StrLength(HString S){
    return S.length;
}

int StrCompare(HString S,HString T){
    for(i=0;i<S.length && i<T.length;++i)
    //两串对应比较；
        if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
        //若两串不等，返回不等时的字符差值；
    return S.length-T.length;
    //若某一串是另一串的子串关系，则返回串长的差；
}

Status ClearString(HString &S){
    if(S.ch) {free(S.ch);S.ch=NULL;}
    //如果某串不是空串，则释放串的基址；
    S.length=0;
    //设置串长；
    return OK;
}

Status Concat(HString &T,HString S1,HString S2){
    if(T.ch) free(T.ch);
    //初始化新串基址；
    if(!(T.ch=(char *)malloc((S1.length+S2.length)*sizeof(char))))
        exit(OVERFLOW);
        //为新串开辟存储空间；
    T.ch[0..S1.length-1]=S1.ch[0..S2.length-1];
    //为新串赋值；
    T.length=S1.length+S2.length;
    //设置新串长度；
    T.ch[S1.length..T.length-1] = S2.ch[0..S2.length-1];
    //新串赋值；
    return OK;
}

Status SubString(HString &Sub,HString S,int pos,int len){
    if(pos<1 || pos>S.length || len<0 || len>S.length-pos+1)
        return ERROR;
        //判断边界条件；
    if(Sub.ch) free(Sub.ch);
    //初始化子串；
    if(!len) {Sub.ch=NULL;Sub.length=0;}
    //若取空子串，则直接返回；
    else{
        Sub.ch=(char *)malloc(len*sizeof(char));
        //为子串分配存储空间；
        Sub.ch[0..len--1] = S.ch[pos-1..pos+len-2];
        //为子串赋值；
        Sub.length = len;
        //设置子串长度；
    }
    return OK;
}
