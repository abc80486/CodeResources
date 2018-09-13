// {0~n-1}的所有子集：增量构造法
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int* A, int cur) {//刚刚是全排列，现在是子集；
  for(int i = 0; i < cur; i++) printf("%d ", A[i]); // 打印当前集合    
  printf("\n");
  int s = cur ? A[cur-1]+1 : 0; // 确定当前元素的最小可能值
  //如果不是第一个元素，所填的元素为上一个元素+1；
  for(int i = s; i < n; i++) {//填数；
    A[cur] = i;//取值；
    print_subset(n, A, cur+1); // 递归构造子集，填入下一个数；
  }//完成一个全排列，改变值，形成下一个子集；
}

int A[10];
int main() {
  int n;
  scanf("%d", &n);
  print_subset(n, A, 0);
  return 0;
}
