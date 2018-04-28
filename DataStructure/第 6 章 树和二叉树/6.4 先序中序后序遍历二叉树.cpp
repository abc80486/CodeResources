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