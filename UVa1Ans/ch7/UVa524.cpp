// UVa524 Prime Ring Problem
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int is_prime(int x) {//判断素数；
  for(int i = 2; i*i <= x; i++)
    if(x % i == 0) return 0;
  return 1;
}
int n, A[50], isp[50], vis[50];
void dfs(int cur) {//深度搜索；
  if(cur == n && isp[A[0]+A[n-1]]) {//数据输入结束；
    for(int i = 0; i < n; i++) {//输出；
      if(i != 0) printf(" ");
      printf("%d", A[i]);
    }
    printf("\n");
  }
  else for(int i = 2; i <= n; i++)
    if(!vis[i] && isp[i+A[cur-1]]) {//填数；
      A[cur] = i;//取值；
      vis[i] = 1;//标志；
      dfs(cur+1);//填下一个数；
      vis[i] = 0;//返回这一步，说明第一次迭代已经输出，改变最后填进的数
      //继续下一次输出；
    }//改变数值；
}//深度优先搜索；

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1 && n > 0) {//输入
    if(kase > 0) printf("\n");//格式；
    printf("Case %d:\n", ++kase);//输出
    for(int i = 2; i <= n*2; i++) isp[i] = is_prime(i);//素数表；
    memset(vis, 0, sizeof(vis));//初始化；
    A[0] = 1;
    dfs(1);//搜索
  }
  return 0;
}
