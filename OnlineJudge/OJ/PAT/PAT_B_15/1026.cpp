//计算一个数按照某种格式输出
#include<iostream>
using namespace std;
int main(){
    int tb,te,t;
    cin>>tb>>te;
    if((te-tb)%100>=50)
        {t=(te-tb)/100.0;t++;}
    else
        t=(te-tb)/100.0;
    printf("%02d:%02d:%02d\n",t/3600,t%3600/60,t%60);
    return 0;
}