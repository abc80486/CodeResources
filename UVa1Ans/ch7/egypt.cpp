// 埃及分数问题
// Rujia Liu
//9/12目前还不能读懂加深迭代搜索，继续往下，不能耗费过多时间；
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

int a, b, maxd;//全局变量；

typedef long long LL;//类型定义；

LL gcd(LL a, LL b) {//求最大公约数；
  return b == 0 ? a : gcd(b, a%b);
}

// 返回满足1/c <= a/b的最小c
inline int get_first(LL a, LL b) {
  return b/a+1;
}

const int maxn = 100 + 5;

LL v[maxn], ans[maxn];
template<class T>
void print(T a,T b,T c,T d,T e,T f){
  cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
  return;
}
// 如果当前解v比目前最优解ans更优，更新ans
bool better(int d) {//判断两个数组；
  for(int i = d; i >= 0; i--) if(v[i] != ans[i]) {//在某范围内判断两个数组不相等；
    return ans[i] == -1 || v[i] < ans[i];//如果 ans数组等于-1或者ans数组比v数组大，返回真；
  }
  return false;
}

// 当前深度为d，分母不能小于from，分数之和恰好为aa/bb
bool dfs(int d, int from, LL aa, LL bb) {//深度优先遍历；四个参数的作用；
  if(d == maxd) {//如果d等于maxd；
    if(bb % aa) return false; // aa/bb必须是埃及分数
    v[d] = bb/aa;//数组v取值；
    if(better(d)) memcpy(ans, v, sizeof(LL) * (d+1));//在范围d+1比较数组ans和v;
    //cout<<v[d]<<endl;
    return true;//ans比v大；返回；
  }
  bool ok = false;
  from = max(from, get_first(aa, bb)); // 枚举的起点
  for(int i = from; ; i++) {//该循环实现数组v的写入；
    // 剪枝：如果剩下的maxd+1-d个分数全部都是1/i，加起来仍然不超过aa/bb，则无解
    if(bb * (maxd+1-d) <= i * aa) break;//判断四个数的关系；
    v[d] = i;//给数组取值；
    // 计算aa/bb - 1/i，设结果为a2/b2
    LL b2 = bb*i;//获取新的迭代数据；
    LL a2 = aa*i - bb;//新的数据；
    LL g = gcd(a2, b2); // 以便约分
    //cout<<d<<" "<<i<<" "<<aa<<" "<<bb<<" "<<a2<<" "<<b2<<" "<<g<<endl;
    //print(d,i,aa,bb,a2,b2);
    if(dfs(d+1, i+1, a2/g, b2/g)) ok = true;//如果能寻找一个最简分数的最大i/1形式的数；
  }//循环退出只要唯一一个一条件
  return ok;
}

int main() {
  //cout<<gcd(-7,90)<<endl;return 0;
  int kase = 0;
  while(cin >> a >> b) {
    int ok = 0;
    for(maxd = 1; maxd <= 100; maxd++) {
      memset(ans, -1, sizeof(ans));
      //cout<<maxd<<endl;
      if(dfs(0, get_first(a, b), a, b)) { ok = 1; break; }
    }
    return 0;
    cout << "Case " << ++kase << ": ";
    if(ok) {
      cout << a << "/" << b << "=";
      for(int i = 0; i < maxd; i++) cout << "1/" << ans[i] << "+";
      cout << "1/" << ans[maxd] << "\n";
    } else cout << "No solution.\n";
  }
  return 0;
}
