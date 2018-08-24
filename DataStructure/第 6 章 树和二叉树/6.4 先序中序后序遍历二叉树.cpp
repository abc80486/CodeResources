Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemTypee)){
    Status PrintElement(TElemType e){
        print(e);
        return OK;
    }
if(T){
    if(Visit(T->data))
        if(PreOrderTraverse(T->lchile,Visit))
            if(PreOrderTraverse(T->rchild,Visit))
                return OK;
    return OK;
}else return OK;
}
Status InOrderTravverse(BiTree T,Status(*Visit)(TElemType e)){
    InitStack(S);
    Push(S,T);
    while(!StackEmpty(S)){
        while(GetTop(S,p)&&p) Push(S,p->lchild);
        Pop(S,p);
        if(!StackEmpty(S)){
            Pop(S,p);
            if(!Visit(p->data)) return ERROR;
            Push(S,p->rchild);
        }
    }
    return OK;
}