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

void dfs(int subset) {
  if(vis[subset]) return;
  vis[subset] = true;

  bool have_children = false;
  for(int left = (subset-1)&subset; left; left = (left-1)&subset) {
    have_children = true;

    int right = subset^left;
    double d1 = sum[right] / sum[subset];
    double d2 = sum[left] / sum[subset];

    dfs(left); dfs(right);

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

    int root = (1<<n)-1;
    memset(vis, 0, sizeof(vis));
    dfs(root);

    double ans = -1;
    for(int i = 0; i < tree[root].size(); i++)
      ans = max(ans, tree[root][i].L + tree[root][i].R);
    printf("%.10lf\n", ans);
  }
  return 0;
}
