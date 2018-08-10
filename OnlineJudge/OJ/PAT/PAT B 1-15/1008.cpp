#include<iostream>
using namespace std;
const int N=101;
int main(){
    int a[N];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&a[(i+m)%n]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    cout<<endl;
    return 0;
}