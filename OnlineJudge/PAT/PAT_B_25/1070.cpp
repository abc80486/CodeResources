//结绳
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    double a[n];
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    sort(a,a+n);
    int sum=0;
    for(int i=1;i<n;i++){
        a[i]=a[i-1]/2+a[i]/2;
    }
    if(int(a[n-1])>a[n-1]) printf("%d\n",int(a[n-1])-1);
    else printf("%d\n",int(a[n-1]));
    //cout<<a[n-1]<<endl;
    return 0;
}