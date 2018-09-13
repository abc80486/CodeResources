// n皇后问题：普通回溯法
// Rujia Liu

#include<cstdio>
using namespace std;

int C[50], tot = 0, n = 8, nc = 0;

void search(int cur) {//搜索算法这次进行了优化；
  int i, j;
  nc++;
  if(cur == n) {//填满则计数；
    tot++;//计数
  } else for(i = 0; i < n; i++) {//填数；
    int ok = 1;//是否填数成功；
    C[cur] = i;//取值；
    for(j = 0; j < cur; j++)//判断能否填数
      if(C[cur] == C[j] || cur-C[cur] == j-C[j] || cur+C[cur] == j+C[j]) {
        ok = 0;//如果存在相等或者在两条对角线上；填数失败，退出循环；
        break;
      }
    if(ok) search(cur+1);//能填数，继续填下一个。
  }//填数失败，改变当前值；
}

int main() {
  scanf("%d", &n);
  search(0);
  printf("%d\n", tot);
  printf("%d\n", nc);
  return 0;
}
