// n皇后问题：优化的回溯法
// Rujia Liu

#include<cstdio>
#include<cstring>
using namespace std;

int C[50], vis[3][50], tot = 0, n = 8, nc = 0;
//使用标志数组；
void search(int cur) {
  int i, j;
  nc++;
  if(cur == n) {//填数完成
    tot++;//计数；
  } else for(i = 0; i < n; i++) {//填数
    if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {
      C[cur] = i;//判断数据是否满足条件；
      vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;//已经填数，标志3处；
      search(cur+1);//填下一个；
      vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;//填数失败，修改标志；
    }//条件不满足，换数；
  }//数据使用完，退出；
}
int main() {
  scanf("%d", &n);
  memset(vis, 0, sizeof(vis));
  search(0);
  printf("%d\n", tot);
  printf("%d\n", nc);
  return 0;
}
