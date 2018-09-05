#include<cmath>
#include<iostream>
#include<string>
using namespace std;
const int N=100000+10;
int main(){
    int m;
    cin>>m;
    bool prime[N+1];
    //memset(prime,true,sizeof(prime));
    for(int i=1;i<=N;i++){
        prime[i]=true;
        if(i%2==0||i%3==0||i%5==0||i%7==0) prime[i]=false;
        for(int j=10;j<=sqrt(i);j++){
            if(i%j==0) {prime[i]=false;break;}
        }
    }
    prime[1]=false;
    prime[2]=prime[3]=prime[5]=prime[7]=true;
    int k=0,a[2],t=0;
    for(int i=1;i<m;i++){
        if(prime[i]==true){
            a[k]=i;
            k=(k+1)%2;
            if(a[1]-a[0]==2) {t++;a[0]=a[1];k=1;}
            else{a[0]=a[1];k=1;}
            cout<<i<<endl;
        }
    }
    cout<<t<<endl;
    return 0;
}