// 八数码，使用哈希表（竞赛中最常用）
// Rujia Liu

#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

typedef int State[9];//定义一维数组样式；
const int MAXSTATE = 1000000;//设置最大遍历数；
State st[MAXSTATE], goal;//设置一个二维数组、一维数组；
int dist[MAXSTATE];//在每一种遍历中记录深度；

const int MAXHASHSIZE = 1000003;
int head[MAXHASHSIZE], next[MAXSTATE];//两个数组；
void init_lookup_table() { memset(head, 0, sizeof(head)); }//初始化数组；
int hash(State& s) {//哈希函数；返回一个整数的模；
  int v = 0;
  for(int i = 0; i < 9; i++) v = v * 10 + s[i];
  return v % MAXHASHSIZE;
}//哈希函数
int try_to_insert(int s) {//插入函数；
  int h = hash(st[s]);//将二维数组某行化为整数，形成哈希数；
  int u = head[h];//该哈希数在头数组的映射值；
  while(u) {//映射值不为0；
    if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;//判断两个数组是否相等；相等返回；
    u = next[u];//不等，更新u值；
  }
  next[s] = head[h];//记录与每一个哈希值相等的数前一个数下标；
  head[h] = s;//将s行插入头数组；记录哈希值最新的查找数；
  return 1;
}

const int dx[] = {-1, 1, 0, 0};//左右移动；
const int dy[] = {0, 0, -1, 1};//上下移动；
int bfs() {//宽度优先搜索；
  init_lookup_table();//初始化头数组；
  int front = 1, rear = 2;//初始化
  while(front < rear) {//满足条件，循环；
    State& s = st[front];//s指向二维数组某行；
    if(memcmp(goal, s, sizeof(s)) == 0) return front;//该行与目标数组相等，结束循环；
    int z;
    for(z = 0; z < 9; z++) if(!s[z]) break;//寻找改行为0下标；
    int x = z/3, y = z%3;//化为二维数组形式下标；
    for(int d = 0; d < 4; d++) {//下标上下左右移动
      int newx = x + dx[d];
      int newy = y + dy[d];
      int newz = newx * 3 + newy;//化为一维数组下标；
      if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {//二维数组下标不出界；
        State& t = st[rear];//t指向下一个一维数组；
        memcpy(&t, &s, sizeof(s));//将下一个一维数组于前一个相等；
        t[newz] = s[z];//1
        t[z] = s[newz];//改变下一个数组的值；
        dist[rear] = dist[front] + 1;//深度加1；
        if(try_to_insert(rear)) rear++;//如果这个数组还不存在，插入；继续插入下一个数组；
      }
    }
    front++;//搜索层数加1；
  }
  return 0;
}

int main() {
  for(int i = 0; i < 9; i++)
    scanf("%d", &st[1][i]);//输入初始数组；
  for(int i = 0; i < 9; i++)
    scanf("%d", &goal[i]);//输入目标数组；
  int ans = bfs();//节点的下标；
  if(ans > 0) printf("%d\n", dist[ans]);//获取树的深度；
  else printf("-1\n");
  return 0;
}
