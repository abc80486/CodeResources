typedef struct{
    char *ch;
    int length;
}HString;
Status StrInsert(HSring &S,int pos,HString T){
    //在串S的某个位置之前插入某个串；注意位置的边界；
    if(pos<1 || pos>S.length+1) return ERROR;
    //检验插入位置的正确性；插入位置必须在主串的第一到最后一个加一之间；
    if(T.length){  //检验插入串的正确性；
        if(!(S.ch=(char *)realloc(S.ch,(S.length+T.length)*sizeof(char))))
            exit(OVERFLOW);
            //在主串基础上增加插入串大小的存储空间，新存储空间基址刷新；
        for(i=S.length-1;i>=pos-1;--i)
            S.ch[i+T.length]=S.ch[i];
            //将主串插入位置到串尾往后移动插入串大小的空间；
        S.ch[pos-1..pos+T.length-2]=T.ch[0..T.length-1];
        //将插入串插入主串；
        S.length+=T.length;
    }
    return OK;
}