//#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int m,t=0,a=2,b=3;
    cin>>m;
    for(int i=4;i<=m;i++){
        if(i==5||i==7||(i%2!=0&&i%3!=0&&i%5!=0&&i%7!=0)){
            int k=1;
            for(int j=10;j<=sqrt(i);j++){
                if(i%j==0) {k=0;break;}
            }
            if(k==1){
            a=b;b=i;
            if(b-a==2) t++;
            }
        }
    }
    cout<<t<<endl;
    return 0;
}