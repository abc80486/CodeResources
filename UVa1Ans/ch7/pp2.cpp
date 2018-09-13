// 可重集的全排列
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

int P[100], A[100];

// 输出数组P中元素的全排列。数组P中可能有重复元素
void print_permutation(int n, int* P, int* A, int cur) {
  if(cur == n) {//数填满；
    for(int i = 0; i < n; i++) printf("%d ", A[i]);//输出；
    printf("\n");
  } else for(int i = 0; i < n; i++) if(!i || P[i] != P[i-1]) {//填数；
    int c1 = 0, c2 = 0;//标志位；
    for(int j = 0; j < cur; j++) if(A[j] == P[i]) c1++;
    //计算当前要填的数与先前填的数相等的数的个数；
    for(int j = 0; j < n; j++) if(P[i] == P[j]) c2++;//判断要填的这个数在列表
    //与多少个数相同；
    if(c1 < c2) {//9/12 没法看懂这标志位的设置，或者通过什么依据得出这设置
    //先留着，因为时间不多；
      A[cur] = P[i];//填数；
      print_permutation(n, P, A, cur+1);//填下一个数；
    }//已经生成一个全排列；
  }//改变之前填的数值，继续生成全排列；
}

int main() {
  int i, n;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &P[i]);
  sort(P, P+n);//排序；
  print_permutation(n, P, A, 0);
  return 0;
}
