#include<iostream>
using namespace std;
const int MAXHASHSIZE = 1000003;
int head[MAXHASHSIZE], next1[1000000];//两个数组；
void init_lookup_table() { memset(head, 0, sizeof(head)); }//初始化数组；
int hash1(int v) {//哈希函数；返回一个整数的模；
  //int v = 0;
  //for(int i = 0; i < 9; i++) v = v * 10 + s[i];
  return v % 40;
}//哈希函数
int try_to_insert(int s) {//插入函数；
  int h = hash1(s);//将二维数组某行化为整数，形成哈希数；
  int u = head[h];//该哈希数在头数组的映射值；
  while(u) {//映射值不为0；
    //if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;//判断两个数组是否相等；相等返回；
    u = next1[u];//不等，更新u值；
  }
  next1[s] = head[h];//将头数组某值赋给下一数组；
  //cout<<s<<" "<<next1[s]<<endl;
  head[h] = s;//将s行插入头数组；
  //cout<<s<<" "<<h<<endl;
  return 1;
}
int main(){
    init_lookup_table();
    for(int i=1;i<100;i++){
        try_to_insert(i);
    }
    return 0;
}