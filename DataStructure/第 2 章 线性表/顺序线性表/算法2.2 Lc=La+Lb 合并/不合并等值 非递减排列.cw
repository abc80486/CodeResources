//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
void MergeList(List La,List Lb,List &Lc){
    InitList(Lc);
    i=j=1;k=0;
    La_len=ListLength(La);
    Lb_len=ListLength(Lb);
    while((i<=La_len)&&(j<=Lb_len)){//没检索到表A或表B的尽头；
        GetElem(La,i,ai); //用ai返回La中第i个元素的值；
        GetElem(Lb,j,bj);
        if(ai<=bj){
            ListInsert(Lc,++k,ai); //在Lc中第k+1个元素之前插入新的数据元素ai，Lc的长度加1；
            ++i;
        }
        else{
            ListInsert(Lc,++k,bj);//在Lc中第k+1个元素之前插入新的数据元素bj,Lc的长度加1；
            ++j;
        }
    }
    while(i<=La_len){
        GetElem(La,i++,ai);
        ListInsert(Lc,++k,ai);
    }
    while(j<=Lb_len){
         GetElem(Lb,j++,bj);
         ListInsert(Lc,++k,bj);
    }
    
}