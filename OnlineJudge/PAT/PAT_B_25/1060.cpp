//爱丁堡数
/*
#include<iostream>
using namespace std;
const int N=100000+5;
int main(){
    int n,a[N]={0},b[N]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp!=0 && temp<=100000) a[temp]++;
        if(temp>100000) a[0]++;
    }
    int ta=0;
    for(int i=99999;i>0;i--){
        b[100000]=a[0];
        if(n==100000&&n<=a[0]) cout<<n<<endl;
        b[i]=b[i+1]+a[i+1];
        if(b[i]>=i) {
            cout<<i;ta=1;
            break;
        }
    }
    if(ta==0) cout<<"0"<<endl;
    return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
bool cmp1(int a, int b) {
    return a > b;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1, cmp1);
    int ans = 0, p = 1;
    while(ans <= n && a[p] > p) {
        ans++;
        p++;
    }
    printf("%d", ans);
    return 0;
}