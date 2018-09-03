#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[10000]={0};
    for(int i=1;i<=n;i++){
        int ch;
        cin>>ch;
        ch=abs(ch-i);
        a[ch]++;
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]>=2) cout<<i<<" "<<a[i]<<endl;
    }
    return 0;
}