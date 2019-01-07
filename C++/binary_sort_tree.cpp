#include<iostream>
using namespace std;
typedef struct _BitNode
{
    int bf;//平衡因子
    int data;
    struct _BitNode *lchild,*rchild;
}BitNode,*BiTree;
bool SearchBST(BiTree T,int key,BiTree pre,BiTree&n)
 {
     if(!T)
     {
         n=pre;       //如果此数为空树，那我们就把前一个元素指针pre（此时为NULL）复制给n，注意树为空时，n才为NULL。
         return false;   //返回假没有找到
     }
     else if(key==T->data)
     {
         n=T;        //找到了就把目标元素指针给n
         return true;
     }
     if(key<T->data)
         SearchBST(T->lchild,key,T,n) ;//去找他的左子树根比
     else
     {
         SearchBST(T->rchild,key,T,n);//去找他的右子树根比。
     }
 }
 bool InsetBST(BiTree &T,int k)
 {
     BitNode* p;
     if(!SearchBST(T,k,NULL,p))
     {   BitNode * temp=new BitNode;
         temp->data=k;
         temp->lchild=temp->rchild=NULL;
         if(!p)  //只有树为空时，此时的p才为NULL。看到这里应该明白SearchBST(T,k,pre,p)这些参数的意义了吧
         {
           T=temp; 
         }
         else
         {
             if(k<p->data)  //如果不为空树，加入的key值就和p相比较，小于就是他的左孩子，否子为右孩子
                 p->lchild=temp;
             else
             {
                 p->rchild=temp;
             }
         }
         return 0;
     }
     else 
     {
         return false;
     }
 }
 bool DeleElement(BiTree&T,int key)
 {
    
         if(!T)
          {
              return 0;   //树是空树的话就返回假
          }
         if(T->data==key)
         {
            BitNode*s,*p;
            if(T->rchild==NULL)   //只有右子树，情况2
            {   
                 s=T;
                 T=T->lchild;
                 free(s);
            }
            else if(T->lchild==NULL)
            {
                s=T;               //只有左子树，情况1
                T=T->rchild;
                free(s);
            }
            else
            {                      //情况3，左右子树都有
                p=T;
                s=T->rchild;
                while (s->lchild)
                {
                    p=s;           //找到所要删除节点的后继，那就是他的右孩子的
                    s=s->lchild;
                }
                T->data=s->data;    //用删除节点的后继替换所删除的节点
                if(p!=T)           
                {
                    p->lchild=NULL;   //所删除的节点的右孩子不是叶结点
                }
                else 
                    p->rchild=NULL;   //所删除的节点的右孩子是叶节点
                free(s);
            }
             return 1;
         }
         else if(key<T->data)
            DeleElement(T->lchild,key);    //去和他的左子树根去比较
         else 
            DeleElement(T->rchild,key);   //去和他的右子树根去比较

 }
 void R_Rotate(BiTree&T)
{
    BiTree p;             //
    p=T->lchild;    //假如此时T指向4，则p指向3；
    T->lchild=p->rchild; //把3的右子树挂接到4的左子树上（此例子3右子树为空）
    p->rchild=T;       //让3的右孩子指向4.
    T=p;        //根指向节点3
}
void L_Rotate(BiTree&T)
{
    BiTree p;
    p=T->rchild;     //假如此时T指向4，则p指向7.
    T->rchild=p->lchild;  //让7的左子树挂接到4的右子树上
    p->lchild=T;    //让7的左孩子指向4
    T=p;   //树根指向7
}
void RightBalance(BiTree&T)
{
    BiTree R,rl;    //调用此函数时，以T为根的树，右边高于左边，则T->bf=RH。
    R=T->rchild;     //R是T的右孩子
    switch (R->bf)
    {
    case RH:            //如果 T的右孩子和T他们的平衡因子符号相同时，则直接左旋，这是总结中的第2项
        T->bf=R->bf=EH;  
        L_Rotate(T);
        break;
    case EH:
        T->bf=RH;
        R->bf=LH;
        L_Rotate(T);
        break;
    case LH:         //如果T的右孩子和T他们的平衡因子符合不同时，需要先以T的右孩子为根进行右旋，再以T为根左旋。
                          //rl为T的右孩子的左孩子
        rl=R->lchild;    //2次旋转后，T的右孩子的左孩子为新的根 。注意：rl的右子树挂接到R的左子树上，rl的左子树挂接到T的右子树上
        switch (rl->bf)   //这个switch 是操作T和T的右孩子进行旋转后的平衡因子。
        {
        case EH:
            T->bf=R->bf=EH;    //这些平衡因子操作，大家可以自己画图操作理解 下面的注解
            break;
                           ////2次旋转后，T的右孩子的左孩子为新的根 。
                          //并且rl的右子树挂接到R的左子树上，rl的左子树挂接到T的右子树上，rl为新根
        case RH:
             R->bf=EH;
             T->bf=LH;
            break;

        case LH:
             R->bf=RH;
             T->bf=EH;
            break;
        default:
            break;
        }
        rl->bf=EH;    
        R_Rotate(T->rchild);    //先左旋，以T->rchild为根左旋。
        L_Rotate(T);  //右旋，以T为根, 左旋后 T是和rl想等，rl是新根
        break;
    }
}
void LeftBalance(BiTree&T)
{
    BiTree L,lr;
    L=T->lchild;
    switch (L->bf)
    {
    case EH:
        L->bf=RH;
        T->bf=LH;
        R_Rotate(T);
        break;
    case LH:
        L->bf=T->bf=EH;
        R_Rotate(T);
        break;
    case RH:
        lr=L->rchild;
        switch (lr->bf)
        {
        case EH:
            L->bf=L->bf=EH;
        case RH:
            T->bf=EH;
            L->bf=LH;
            break;
        case LH:
            L->bf=EH;
            T->bf=RH;
            break;
        default:
            break;
        }
        lr->bf=EH;
        L_Rotate(T->lchild);
        R_Rotate(T);
        break;
    default:
        break;
    }
}
bool InsertAVLtree(BiTree&T,int key,bool &taller)
{
    if(!T)       //此树为空
    {
        T=new BitNode;   //直接作为整棵树的根。
        T->bf=EH;
        T->lchild=T->rchild=NULL;
        T->data=key;
        taller=true;
        return true;
    }
    else
    {   if(key==T->data)      //已有元素，不用插入了，返回false；
          {
              taller=false;
              return false;
           }
        if(key<T->data)      //所插元素小于此根的值，就找他的左孩子去比
        {
            if(!InsertAVLtree(T->lchild,key,taller))   //所插元素小于此根的值，就找他的左孩子去比 
                return false;
            if(taller)    //taller为根，则树长高了，并且插入到了此根的左子树上。
            {
            switch (T->bf)       //此根的平衡因子
            {
            case EH:             //原先是左右平衡，等高
                T->bf=LH;          //由于插入到左子树上，导致左高=》》LH
                taller=true;      //继续往上递归
                break;
            case LH:
                LeftBalance(T); //原先LH，由于插入到了左边，这T这个树，不平衡需要左平衡
                taller=false;  //以平衡，设taller为false，往上递归就不用进入此语句了，
                break;
            case RH:
                T->bf=EH;     //原先RH，由于插入到左边，导致此T平衡
                taller=false;
                break;
            default:
                break;
            }
            }
        }
        else 
        {
                if(!InsertAVLtree(T->rchild,key,taller))
                    return false;
                if(taller)
                {
                switch (T->bf)
                {
                case EH:
                    T->bf=RH;
                    taller=true;
                    break;
                case LH:
                    T->bf=EH;
                    taller=false;
                    break;
                case RH:
                    RightBalance(T);
                    taller=false;
                    break;
                default:
                    break;
                }
                }
        }
       
         
    }
}
//中序遍历输出
void InOrderReverse(BiTree &T)
{
    if(T)
    {

        InOrderReverse(T->lchild);
        cout<<T->data<<endl;
        InOrderReverse(T->rchild);
    }
}
bool DeletElement(BiTree&T,int key,bool&lower)//参数（0）树根，（1）删除的元素，（3）此树是否降低标志位
{
    bool L,R;//删除的是左子树还是右子树，作为标志。
    L=R=false;
       if(T==NULL)        // 判断树根是否为空                      
        return false;
    if(key==T->data)//找到了所要删除的节点
    {
        BitNode* p,*s;
        p=T->rchild;
        s=p;
        lower=true;    //找到了必定删除，lower为真
        if(T->rchild==NULL)  // 如果所要删除的节点的右孩子为空
        {   

            p=T;
            T=T->lchild;         //直接删除比如删除上图的 4,9,10，
            free(p);

             lower=true;

            return true;
        }
        else
        {
            while (s)//如果所要删除的T节点右子树不为空，就找T的后继，也就是T的右孩子左子树的最左叶节点
            {
                p=s;
                s=s->lchild;
            }
            T->data=p->data;//替换T
            DeletElement(T->rchild,p->data,lower);//删除掉T的后继
            R=true;
        }
    }
    else if(key<T->data)
    {
        DeletElement(T->lchild,key,lower);
        L=true;
    }
    else 
    {
        DeletElement(T->rchild,key,lower);
        R=true;
    }
    if(lower)//如果有节点删除
    {
        if(L)//删除的是左节点
        {
            switch (T->bf)
            {
            case LH://没删之前LH，删后T->bf=EH;
                T->bf=EH;
                lower=true;
                break;
            case RH://没删之前RH，删后导致右不平衡，
                RightBalance(T);
                lower=false;
                break;
            case EH://没删之前EH，删后RH；
                T->bf=RH;
                lower=false;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (T->bf)
            {
            case EH:
                T->bf=LH;
                lower=false;
                break;
            case RH:
                T->bf=EH;
                lower=true;
                break;
            case LH:
                LeftBalance(T);
                lower=false;
                break;
            default:
                break;
            }
        }
    }
} 