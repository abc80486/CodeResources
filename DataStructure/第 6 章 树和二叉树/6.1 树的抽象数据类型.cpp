ADT Tree{
    InitTree(&T);
    DestroyTree(&T);
    CreatTree(&T,definition);
    ClearTree(&T);
    TreeEmpty(T);
    TreeDepth(T);
    Root(T);
    Value(T,cur_e);
    Assign(T,cur_e,value);
    Parent(T,cur_e);
    LeftChild(T,cur_e);
    RightSibling(T,cur_e);
    InsertChild(&T,&p,i,c);
    DeleteChild(&T,&p,i);
    TraverseTree(T,visit());
}