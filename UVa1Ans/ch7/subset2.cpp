// {0~n-1}的所有子集：位向量法
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int* B, int cur) {
  if(cur == n) {//满足条件
    for(int i = 0; i < cur; i++)
      if(B[i]) printf("%d ", i); // 打印当前集合
    printf("\n");
    return;//打印后退出；
  }
  B[cur] = 1; // 选第cur个元素
  print_subset(n, B, cur+1);//短短几行，却难以理解，难以捉摸，递归里
  //应该存在还没掌握的数学知识；
  B[cur] = 0; // 不选第cur个元素
  print_subset(n, B, cur+1);
}

int B[10];
int main() {
  int n;
  scanf("%d", &n);
  print_subset(n, B, 0);
  return 0;
}
