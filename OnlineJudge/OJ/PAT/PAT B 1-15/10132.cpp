#include<iostream>
#include<cmath>
using namespace std;
//const int N=100000;
int main(){
    int k=0,m,n,p=0;
    cin>>m>>n;
    for(int i=2;i<=n*15;i++){
        int t=1;
        for(int j=2;j<=sqrt(i);j++)
            if(i%j==0){t=0;break;}
        if(t==1){
             k++;
            if(k>=m&&k<=n) {
                p++;
                if(p!=1) cout<<" ";
                cout<<i;
                if(p==10) {cout<<endl;p=0;}
            }
        }
    }
    
    return 0;
}