#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,t;
    cin>>n;
    int k=0;t=n;
    while(t>0){ t=t/10;k++;}
    while(k--){
        int a;
        a=n/pow(10,k);
        n%=int(pow(10,k));
        if(k==2){
            for(int i=1;i<=a;i++) cout<<"B";continue;
        }
        if(k==1){
            for(int i=1;i<=a;i++) cout<<"S";continue;
        }
        if(k==0){
            for(int i=1;i<=a;i++) cout<<i;
        }
    }
    cout<<endl;
    return 0;
}