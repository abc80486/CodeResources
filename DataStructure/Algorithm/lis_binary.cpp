#include<iostream>
#include<algorithm>
using namespace std;

int lis_binary(int arr[],int n){
    int ans[n],len=0;
    ans[0]=arr[0];
    for(int i=1;i<n;++i){
        if(arr[i]>ans[len]) ans[++len]=arr[i];
        else ans[*lower_bound(ans,ans+len+1,arr[i])]=arr[i];
    }
    return len+1;
}
int main(){
    int arr[]={2,1,5,3,6,4,8,9,7};
    cout<<lis_binary(arr,9)<<endl;
    return 0;
}