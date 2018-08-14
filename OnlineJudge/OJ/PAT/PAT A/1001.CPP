#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    void fun(int n);
    int a,b;
    while(scanf("%d%d",&a,&b)==2){
        
        fun(a+b);
        
        cout<<endl;
    }
    return 0;
}
void fun(int n){
    if(n<0){
        cout<<"-";
        n=-n;
    }

    if(n<1000){
        cout<<n;
        return;
    }
    else{
        fun(n/1000);
        cout<<",";
        if(n%1000<100) cout<<"0";
        if(n%1000<10) cout<<"0";
        cout<<n%1000;
    }
}