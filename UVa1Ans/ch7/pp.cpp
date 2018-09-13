// 求1~n的全排列. n<100
// Rujia Liu
#include<cstdio>
using namespace std;

int A[101];

// 输出1~n的全排列
void print_permutation(int n, int* A, int cur) {
  if(cur == n) { // 递归边界,填数满足要求
    for(int i = 0; i < n; i++) printf("%d ", A[i]);//输出；
    printf("\n");
  } else for(int i = 1; i <= n; i++) { // 尝试在A[cur]中填各种整数i
    int ok = 1;//填数成功标志；
    for(int j = 0; j < cur; j++)//填数
      if(A[j] == i) ok = 0; // 如果i已经在A[0]~A[cur-1]出现过，则不能再选
    if(ok) {//数据可填；
      A[cur] = i;//填数；
      print_permutation(n, A, cur+1); // 递归调用，填下一个数；
    }//数据填完，退出，下一组数据；
  }//递归退出；
}

int main() {
  int n;
  scanf("%d", &n);
  print_permutation(n, A, 0); 
  return 0;
}
