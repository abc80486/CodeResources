// UVa1343 The Rotation Game
// Rujia Liu
// This solutions uses IDA* instead of BFS described in the book, because it's shorter 8-)
// It's shorter because no need for lookup tables and "automatically" lexicographically smallest solution.
#include<cstdio>
#include<algorithm>
using namespace std;

/*
      00    01
      02    03
04 05 06 07 08 09 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/

// lines E~H are computed with the help of rev[]
int line[8][7]={//暂时不懂这组数据；如果真的在比赛，想到这种方法的都是了不起的；
  { 0, 2, 6,11,15,20,22}, // A
  { 1, 3, 8,12,17,21,23}, // B
  {10, 9, 8, 7, 6, 5, 4}, // C
  {19,18,17,16,15,14,13}, // D
};

const int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2}; // reverse lines of each line
//还有这一组，数据看起来没有显然的规律；
// center squares
const int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
//？？？
int a[24];
char ans[1000];

bool is_final() {//判断内环8个数是否相同；
  for(int i = 0; i < 8; i++)//8次循环；
    if (a[center[i]] != a[center[0]]) return false;//8个数相等；
  return true;//都相等返回真；
}

int diff(int target) {//
  int ans = 0;
  for(int i = 0; i < 8; i++)//8次循环；
    if(a[center[i]] != target) ans++;//计算内部与某数不相等的个数；
  return ans;
}//

inline int h() {//返回内环最多的数的个数与8的差
  return min(min(diff(1), diff(2)), diff(3));//寻找内环最多的数；
}

inline void move(int i) {//操作，数据移动；
  int tmp = a[line[i][0]];//保留头部；
  for(int j = 0; j < 6; j++) a[line[i][j]] = a[line[i][j+1]];
  //后面的数向前移动；
  a[line[i][6]] = tmp;//第一个数移到最后一个；
}

bool dfs(int d, int maxd) {//深度优先搜素
  if(is_final()) {//如果内部数字相等；
    ans[d] = '\0';
    printf("%s\n", ans);//输出字符串；该字符串为操作字符串；
    return true;//返回；
  }
  if(d + h() > maxd) return false;//
  for(int i = 0; i < 8; i++) {//8次循环；
    ans[d] = 'A' + i;//答案；
    move(i);//移动；
    if(dfs(d+1, maxd)) return true;//
    move(rev[i]);
  }
  return false;
}//搜素

int main() {//还是从主函数开始读起；
  for(int i = 4; i < 8; i++)
    for(int j = 0; j < 7; j++) line[i][j] = line[rev[i]][6-j];
  //该二重循环涉及两个数组
  while(scanf("%d", &a[0]) == 1 && a[0]) {//循环输入一个整数；
    for(int i = 1; i < 24; i++) scanf("%d", &a[i]);//输入23个数；
    for(int i = 0; i < 24; i++) if(!a[i]) return 0;//如果存在0，退出；
    if(is_final()) {//如果内部数字相等，输出；
      printf("No moves needed\n");
    } else {
      for(int maxd = 1; ; maxd++)//maxd的作用是？
        if(dfs(0, maxd)) break;//如果深度优先搜索返回真，退出；
    }
    printf("%d\n", a[6]);
  }
  return 0;
}
