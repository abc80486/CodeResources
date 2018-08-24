//将所有在线性表Lb中的数据元素插入到La中；
void union(List &La,List Lb){
    La.len=Listlength(La);
    Lb.len=ListLength(Lb);
    for(i=1;i<=Lb_len;i++){
        GetElem(Lb,i,e);
        if(!LocateElem(La,e,equal)) 
            ListInsert(La,++La_len,e);
    }
}//union