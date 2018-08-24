//在顺序线性表L中查找第1个值与e满足compare()的元素的位序；
int LocateElem_Sq(SqList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    i=1;
    p=L.elem;
    while(i<=L.length && !(*compare)(*p++,e)) //找到与e相等的i位序；
        ++i;
    if(i<=L.length)  //考虑表L为空的情况；
        return i;
    else 
        return 0;
}//LocateElem_Sq