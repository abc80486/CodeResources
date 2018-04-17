//归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列；
void MergeList_Sq(Sqlist La,Sqlist Lb,Sqlist &Lc){
    pa=La.elem;
    pb=Lb.elem;
    Lc.listsize=Lc.length=La.length+Lb.length;
    pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));
    if(!Lc.elem) 
        exit(OVERFLOW);  //存储分配失败；
    pa_last=La.elem+La.length-1;
    pb_last=Lb.elem+Lb.length-1;
    while(pa<=pa_last && pb<=pb_past){ //比较，插入；
        if(*pa<=*pb)
            *pc++=*pa++;
        else
            *pc++=*pb++;
    }
    while(pa<=pa_last)
        *pc++=*pa++;
    while(pb<=pb_last)
        *pc++=*pb++;
}//MergeList_Sq