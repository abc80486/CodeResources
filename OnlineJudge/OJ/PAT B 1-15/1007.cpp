#include<iostream>
#include<string>
using namespace std;
const int N=100000;
int main(){
    bool prime[N+1];
    memset(prime,true,sizeof(prime));
    for(int i=1;i<=N;i++){
        if(i%2==0||i%3==0||i%5==0||i%7==0) prime[i]=false; 
    }
    prime[1]=false;
    prime[2]=prime[3]=prime[5]=prime[7]=true;
    int k=0,a[2],t=0;
    for(int i=1;i<=N;i++){
        if(prime[i]==true){
            a[k]=i;
            k=(k+1)%2;
            if(abs(a[1]-a[0])==2) t++;
            else{a[0]=a[1];k=1;}
            //cout<<i<<endl;
        }
    }
    cout<<t<<endl;
    return 0;
}