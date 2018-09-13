// n皇后问题：生成-测试法
// Rujia Liu
//该方法的运行效率很差，当n大于9是几乎不能出结果；
#include<cstdio>
#include<iostream>
using namespace std;

int C[50], tot = 0, n = 8, nc = 0;//四个变量，其中一个数组；

void search(int cur) {//搜索算法；
  int i, j;
  nc++;//搜素的次数；
  if(cur == n) {//
    for(i = 0; i < n; i++)//二重循环
      for(j = i+1; j < n; j++)//
        if(C[i] == C[j] || i-C[i] == j-C[j] || i+C[i] == j+C[j]) return;
        //当i,j不在同一对角线以及，后一个数不与前一个相等；
    tot++;//经过两次循环都没有退出，表明数组符合条件；次数累加；也可以输出；
  } else for(i = 0; i < n; i++) {//类似于8层循环，函数退出的条件是cui==8
  //所以首次进入会形成8套循环，之后是循环退出；
    C[cur] = i;
    search(cur+1);//下一个取值；
  }
}

int main() {
  scanf("%d", &n);
  search(0);
  printf("%d\n", tot);
  printf("%d\n", nc);
  return 0;
}
