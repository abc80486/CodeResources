// 八数码，使用STL集合（最好写）
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

typedef int State[9];  //定义一维数组；
const int MAXSTATE = 1000000;//设置状态数的最大值；
State st[MAXSTATE], goal;//定义一个二维数组和一个一维数组；
int dist[MAXSTATE];//定义一个一维数组；

set<int> vis;//定义一个整型数列；
void init_lookup_table() { vis.clear(); } //初始化整形数列函数

int try_to_insert(int s) {//函数，将二维数组s行化成整数，插入空数列中
  int v = 0;//设置整型变量；
  for(int i = 0; i < 9; i++) v = v * 10 + st[s][i];//将二维数组st第s行的9个数转化为一个整数v；
  if(vis.count(v)) return 0;//如果数列vis中的存在数v，函数返回0；
  vis.insert(v);//如果数列不存在数v，将整数v插入数列vis；
  return 1;//并返回1；
}

const int dx[] = {-1, 1, 0, 0}; //定义4个数；
const int dy[] = {0, 0, -1, 1};//定义四个数；
int bfs() {//宽度优先搜索；
  init_lookup_table();//初始化整形数列vis
  int front = 1, rear = 2;//定义两个整数；
  while(front < rear) {//当一个整数小于另一个整数时循环；
    State& s = st[front];//定义一个指向一维数组的指针；该指针指向二维数组的front行；
    if(memcmp(goal, s, sizeof(s)) == 0) return front;//比较两个数组是否相等，相等则返回；
    int z;  
    for(z = 0; z < 9; z++) if(!s[z]) break;//寻找数组s中为零的那个数；
    int x = z/3, y = z%3;//将一维数组下标化为二维数组下标，行数列数为3；
    for(int d = 0; d < 4; d++) {//循环4次；
      int newx = x + dx[d];//d为0123对应于x坐标左移、右移及不变；
      int newy = y + dy[d];//y上下移动；
      int newz = newx * 3 + newy;//将二维数组坐标表示化为一维数组表示法；
      if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {//当二维数组坐标不越界时执行；
        State& t = st[rear];//定义指针t指向一维数组st[rear];
        memcpy(&t, &s, sizeof(s));//数组复制，将数组s复制到t；
        t[newz] = s[z];//1
        t[z] = s[newz];//2两行实现将数组为零的数与移动后的位置交换；
        dist[rear] = dist[front] + 1;//将前一个步骤的距离加一得到后一个步骤的步数；
        if(try_to_insert(rear)) rear++;//如果st[rear]不存在于数组vis，插入数据；
      }
    }//d继续累加，不断遍历坐标xy的上下左右4个方向，并把这四个方向的数据与原本数据交换，
    //得到的新数据放进队列，并把搜索深度在上一层的情况下加1；
    front++;  //将搜索下一层的数据，并重复过程，在下一层中寻找数据为0的数，遍历四个方向
    //获取四个数据，并将与不存在于队列的数插入队列，循环结束标识是当寻找到与目标数组一样的数组；
    //或者遍历完无法找到一样的数组；问题：八数码问题在合法输入下都能找到解吗？
  }
  return 0;
}//宽度优先搜索

int main() {
  for(int i = 0; i < 9; i++)
    scanf("%d", &st[1][i]);//输入原始数组；
  for(int i = 0; i < 9; i++)
    scanf("%d", &goal[i]);//输入目标数据；
  int ans = bfs();//宽度优先搜索，计算层数；
  if(ans > 0) printf("%d\n", dist[ans]);//如果步数大于0，输出步数；
  else printf("-1\n");//否则输出-1；
  return 0;
}
