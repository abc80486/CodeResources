//已知单链表La和Lb的元素按值非递减排列；
//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列；
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
    pa=La->next;
    pb=Lb->next;
    Lc=pc=La;
    while(pa&&pb){  
        if(pa->data<=pb->data){
            pc->next=pa;pc=pa;pa=pa->next; 
        }
        else{
            pc->next=pb;pc=pb;pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;   //插入剩余片段；
    free(Lb);
}//MergeList_L