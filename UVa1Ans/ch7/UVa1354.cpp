// UVa1354 Mobile Computing
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
//全局变量：Tree maxn n,vis[],dfs(),r,w[],sum[],tree[]
struct Tree {
  double L, R; // distance from the root to the leftmost/rightmost point
  Tree():L(0),R(0) {}//结构体构造函数
};

const int maxn = 6;

int n, vis[1<<maxn];//vis的大小为128
double r, w[maxn], sum[1<<maxn];//w[6],sum[128]
vector<Tree> tree[1<<maxn];//tree[128]容器；

void dfs(int subset) {//深度优先搜索
  if(vis[subset]) return;//如果该值为1，返回；
  vis[subset] = true;//设该值为1；

  bool have_children = false;//局部变量
  for(int left = (subset-1)&subset; left; left = (left-1)&subset) {
    //subset-1后与本身逻辑与，left为0循环结束；left的下一个值为left-1与subset逻辑与；
    have_children = true;//设置have_children为真；

    int right = subset^left;//局部变量为subset异或
    double d1 = sum[right] / sum[subset];//d1为
    double d2 = sum[left] / sum[subset]; 9

    dfs(left); 
    dfs(right);
    
    for(int i = 0; i < tree[left].size(); i++)
      for(int j = 0; j < tree[right].size(); j++) {
        Tree t;
        t.L = max(tree[left][i].L + d1, tree[right][j].L - d2);
        t.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
        if(t.L + t.R < r) tree[subset].push_back(t);
      }
  }

  if(!have_children) tree[subset].push_back(Tree());
}
 
int main() {//程序入口
  int T;
  scanf("%d", &T);//输入变量
  while(T--) {//循环
    scanf("%lf%d", &r, &n);//输入r,n；
    for(int i = 0; i < n; i++) scanf("%lf", &w[i]);//输入n个数，存在w[i]中；
    for(int i = 0; i < (1<<n); i++) {//循环2^n次方
      sum[i] = 0;//sum[i]初始化；
      tree[i].clear();//tree[i]初始化；
      for(int j = 0; j < n; j++)//循环n次
        if(i & (1<<j)) sum[i] += w[j];//如果i与2^j次方按位与不为0，将w[j]累加到sum[i]；
    }

    int root = (1<<n)-1;//root=2^n-1;
    memset(vis, 0, sizeof(vis));//初始化vis
    dfs(root);//深度优先搜索；

    double ans = -1;//结果
    for(int i = 0; i < tree[root].size(); i++)
      ans = max(ans, tree[root][i].L + tree[root][i].R);//取最大值
    printf("%.10lf\n", ans);//输出；
  }
  return 0;
}
