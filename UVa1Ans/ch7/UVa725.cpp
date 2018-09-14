// UVa725 Division
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//
int main() {
  int n, kase = 0;
  char buf[99];
  while(scanf("%d", &n) == 1 && n) {//数据输入；
    int cnt = 0;//输出标志位
    if(kase++) printf("\n");
    for(int fghij = 1234; ; fghij++) {
      int abcde = fghij * n;
      sprintf(buf, "%05d%05d", abcde, fghij);//整型化为字符串；
      if(strlen(buf) > 10) break;//初始数据不存在解；
      sort(buf, buf+10);//排序；
      bool ok = true;//19-21字符串判断；
      for(int i = 0; i < 10; i++)
        if(buf[i] != '0' + i) ok = false;//不相等，数据不对；
      if(ok) {//数据满足条件；输出
        cnt++;
        printf("%05d / %05d = %d\n", abcde, fghij, n);
      }
    }//继续寻找下一个解；
    if(!cnt) printf("There are no solutions for %d.\n", n);
    //无解输出；
  }
  return 0;
}
