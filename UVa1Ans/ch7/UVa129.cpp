// UVa129 Krypton Factor
// Rujia Liu
//判断是否存在相邻子串
#include<stdio.h>
int n, L, cnt;
int S[100];
//有一些常用算法真的需要背熟；例如判断字符串是否存在相邻相等子串等；
int dfs(int cur) { //深度优先搜索     // 返回0表示已经得到解，无须继续搜索
  if(cnt++ == n) {//判断cnt是否与n相等；
    for(int i = 0; i < cur; i++) {//输出；
      if(i % 64 == 0 && i > 0) printf("\n");
      else if(i % 4 == 0 && i > 0) printf(" ");
      printf("%c", 'A'+S[i]); // 输出方案
    }
    printf("\n%d\n", cur);
    return 0;
  }
  for(int i = 0; i < L; i++) {//3次循环；
    S[cur] = i;//数组取值；
    int ok = 1;//标志位；
    for(int j = 1; j*2 <= cur+1; j++) {              // 尝试长度为j*2的后缀
      //j的取值为【1，cur/2]；
      int equal = 1;//相等标志；
      for(int k = 0; k < j; k++) //  k的取值为【0，j）；    // 检查后一半是否等于前一半
        if(S[cur-k] != S[cur-k-j]) { equal = 0; break; }
        //20-28行为相邻相等子串判断的代码；
      if(equal) { ok = 0; break; }                       // 后一半等于前一半，方案不合法
    }
    //标志位ok为1代表无相邻重复子串；参数为字符串长度cur的字符串；
    if(ok) if(!dfs(cur+1)) return 0;                     // 递归搜索。如果已经找到解，则直接退出
    //无重复子串，继续增加字母；  
  }//存在重复子串，改变字母，继续判断；
  return 1;
}

int main() {
  while(scanf("%d%d", &n, &L) == 2 && n > 0) {
    cnt = 0;
    dfs(0);
  }
  return 0;
}
