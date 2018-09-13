// 八数码，使用全排列的编码/解码（最高效）
// Rujia Liu

#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

typedef int State[9];//一维数组；
const int MAXSTATE = 1000000;
State st[MAXSTATE], goal;
int dist[MAXSTATE];

int vis[362880], fact[9];//两个一维数组；
void init_lookup_table() {//初始化数组；
  fact[0] = 1;
  for(int i = 1; i < 9; i++) fact[i] = fact[i-1] * i;//后一个数为前一个数的k陪，k为这个数的下标；
}
int try_to_insert(int s) {//插入函数，查找函数；
  int code = 0;
  for(int i = 0; i < 9; i++) {//对数组每一个数操作；
    int cnt = 0;
    for(int j = i+1; j < 9; j++) if(st[s][j] < st[s][i]) cnt++;
    //计算这个数后面比它小的数的个数；
    code += fact[8-i] * cnt;//用这个数与参数数组对应相乘；
  }
  if(vis[code]) return 0;//判断编码是否存在；
  return vis[code] = 1;//不存在，返回1；
}
//上述的三个查找方法各存在优点，同时存在不足；
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int bfs() {
  init_lookup_table();
  int front = 1, rear = 2;
  while(front < rear) {
    State& s = st[front];
    if(memcmp(goal, s, sizeof(s)) == 0) return front;
    int z;
    for(z = 0; z < 9; z++) if(!s[z]) break;
    int x = z/3, y = z%3;
    for(int d = 0; d < 4; d++) {
      int newx = x + dx[d];
      int newy = y + dy[d];
      int newz = newx * 3 + newy;
      if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
        State& t = st[rear];
        memcpy(&t, &s, sizeof(s));
        t[newz] = s[z];
        t[z] = s[newz];
        dist[rear] = dist[front] + 1;
        if(try_to_insert(rear)) rear++;
      }
    }
    front++;
  }
  return 0;
}

int main() {
  for(int i = 0; i < 9; i++)
    scanf("%d", &st[1][i]);
  for(int i = 0; i < 9; i++)
    scanf("%d", &goal[i]);
  int ans = bfs();
  if(ans > 0) printf("%d\n", dist[ans]);
  else printf("-1\n");
  return 0;
}
