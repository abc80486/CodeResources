#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode *left,*right;
        TreeNode(){}
        TreeNode(const int& item,TreeNode *lptr=NULL,TreeNode *rptr=NULL){
            val=item;
            left=lptr;
            right=rptr;
        }
};
void invertBinaryTree1(TreeNode *root){//递归形式；
    if(root!=NULL){
        TreeNode* tmp=new TreeNode();
        tem->left=root->left;
        root->left=root->right; 
        root->right=tem->left;

        invertBinaryTree1(root->left);
        invertBinaryTree1(root->right);
    }
}
void invertBinaryTree(TreeNode *root){//非递归翻转二叉树；
    TreeNode *p=root;
    stack<TreeNode*> mstack;

    while(p!=NULL || !mstack.empty()){
        while(p!=NULL){
            mstack.push(p);
            TreeNode *tmp = new TreeNode();
            tmp->left=p->left;
            p->left=p->right;
            p->right=tmp->left;

            p=p->left;
        }
        if(!mstack.empty()){
            p=mstack.top();
            mstack.pop();

            p=p->right;
        }
    }

}
