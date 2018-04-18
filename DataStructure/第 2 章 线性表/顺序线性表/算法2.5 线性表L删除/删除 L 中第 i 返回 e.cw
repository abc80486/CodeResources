//在线性表中L中删除第i个元素，并用e返回其值；
Status ListDelete_Sq(Sqlist &L,int i,ElemType &e){
    if((i<1)||(i>L.length))
        return ERROR;
    P=&(L.elem[i-1]);
    e=*p;
    q=L.elem+L.length-1;
    for(++p;p<=q;++p)
        *(p-1)=*p;
    --L.length;
    return OK;
}//ListDelete_Sq