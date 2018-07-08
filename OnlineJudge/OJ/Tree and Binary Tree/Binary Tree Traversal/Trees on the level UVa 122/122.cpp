#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 256+10;
//结点定义；
struct Node{
    bool have_value;
    int v;
    Node *left,*right;
    Node():have_value(false),left(NULL),right(NULL){}
};
Node *root;//根节点；
Node *newnode(){return new Node();}//开辟存储空间；
bool failed;//差错全局变量；
//新建结点；
void addnode(int v,char *s){
    int n=strlen(s);
    Node *u=root;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            if(u->left==NULL) u->left=newnode();
            u=u->left;
        }else if(s[i]=='R'){
            if(u->right==NULL) u->right=newnode();
            u=u->right;
        }
    }
    if(u->have_value) failed=true;
    u->v=v;
    u->have_value=true;
}
//释放一棵树的存储空间；
void remove_tree(Node *u){
    if(u==NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}
char s[maxn];//存储输入的字符串；
//二叉树的建立；
bool read_input(){
    failed=false;
    remove_tree(root);
    root=newnode();
    for(;;){
        if(scanf("%s",s)!=1) return false;
        if(!strcmp(s,"()")) break;
        int v;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;
}
//二叉树的遍历；
bool bfs(vector<int>& ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node *u=q.front();q.pop();
        if(!u->have_value) return false;
        ans.push_back(u->v);
        if(u->left!=NULL) q.push(u->left);
        if(u->right!=NULL) q.push(u->right);
    }
    return true;
}
int main(){
    vector<int> ans;//输出序列；
    while(read_input()){//输入未结束；
        if(!bfs(ans)) failed=1;//输入数据有误；
        if(failed) printf("-1\n");
        else{//输出；
            for(int i=0;i<ans.size();i++){
                if(i!=0) printf(" ");
                printf("%d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
