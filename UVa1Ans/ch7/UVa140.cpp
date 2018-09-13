// UVa140 Bandwidth
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
//
const int maxn = 10;
int id[256], letter[maxn];//定义两个数组；用于实现字符输入，应该可以使用其他办法；

int main() {
  char input[1000];//字符数组；
  while(scanf("%s", input) == 1 && input[0] != '#') {
    // 计算结点个数并给字母编号
    int n = 0;
    for(char ch = 'A'; ch <= 'Z'; ch++)
      if(strchr(input, ch) != NULL) {//strchr字符查找；
        id[ch] = n++;//标志查找的字符；
        //letter[id[ch]] = ch;//标志字符；
      }

    // 处理输入
    int len = strlen(input), p = 0, q = 0;
    vector<int> u, v;//两个整型队列；
    for(;;) {//为两个列表取值；
      while(p < len && input[p] != ':') p++;//寻找某标志；
      if(p == len) break;//到达字符尾部结束；
      while(q < len && input[q] != ';') q++;//寻找标志；
      for(int i = p+1; i < q; i++) {//满足条件字符插入；
        u.push_back(id[input[p-1]]);//插入主字符位置；
        v.push_back(id[input[i]]);//插入关联字符位置；
      }
      p++; q++;//继续寻找下一组数据；
    }

    // 枚举全排列
    int P[maxn], bestP[maxn], pos[maxn], ans = n;//三个数组；
    for(int i = 0; i < n; i++) P[i] = i;//初始化；
    do {
      for(int i = 0; i < n; i++) pos[P[i]] = i; // 每个字母的位置
      int bandwidth = 0;//标志位；
      for(int i = 0; i < u.size(); i++)//计算带宽，最大值
        bandwidth = max(bandwidth, abs(pos[u[i]] - pos[v[i]])); // 计算带宽
      if(bandwidth < ans) {//保留最大值；
        ans = bandwidth;
        memcpy(bestP, P, sizeof(P));//保存最大值时的排列；
      }
    } while(next_permutation(P, P+n));//下一个排列，并重复计算最大带宽，保存
    //最大带宽和排列；

    // 输出
    for(int i = 0; i < n; i++) printf("%c ", char(bestP[i]+'A'));
    //原来letter用于输出，其实可以直接输出；
    printf("-> %d\n", ans);
  }
  return 0;
}
