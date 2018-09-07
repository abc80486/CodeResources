#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int m;
    cin>>m;
    int a=2,b=3,t=0;
    for(int i=4;i<=m;i++){
        int ta=1;
        double k=sqrt(i);
        for(int j=2;j<=k;j++){
            if(i%j==0){ta=0;break;}
        }
        if(ta==1){
            a=b;b=i;
            if(b-a==2) t++;
        }
    }
    cout<<t<<endl;
    return 0;
}