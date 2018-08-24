#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int main(){
    int n;
    int fl[N+1]={0};
    bool out[N+1]={false};
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) 
        //cin>>a[i];
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int k=a[i];
        if(fl[k]==0){
             fl[k]=1;
        while(k!=1){
            if(k%2==0)  k/=2;
            else k=(3*k+1)/2;
            if(fl[k]!=0){
                out[a[i]]=true;
                if(out[k]==true) out[k]=false;
                break;
            }
            if(k<=100) fl[k]=1;
        }
        out[a[i]]=true;
        }
        else out[a[i]]=false;
    }
    int p=0;
    for(int i=100;i>=1;i--){
        if(out[i]==true) {
            p++;
            if(p!=1){cout<<" ";}
            cout<<i;
            }
    }
    cout<<endl;
    return 0;
}