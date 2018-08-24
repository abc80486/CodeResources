#include<iostream>
using namespace std;
int main(){
    char ch;
    int a[10]={0};
    while((ch=getchar())!=10){
        a[ch-'0']++;
    }
    for(int i=0;i<10;i++){
        if(a[i]!=0) cout<<i<<":"<<a[i]<<endl;
    }
    return 0;
}
