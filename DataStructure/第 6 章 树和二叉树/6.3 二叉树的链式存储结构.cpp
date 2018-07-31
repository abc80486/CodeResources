typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T);
Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemType e));
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e));
Status PostOrderTraserse(BiTree T,Status(*Visit)(TElemType e));
Status LevelOrderTravverse(BiTree T,Status(*Visit)(TElemType e));
