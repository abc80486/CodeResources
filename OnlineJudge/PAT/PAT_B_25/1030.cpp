//完美数列
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    double a[100005],p;
    scanf("%d%lf",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    sort(a,a+n);
    int t=0;
    //double k;
    for(int j=0;j<n;j++){
        for(int i=j+t;i<n;i++){
            if(a[i]>a[j]*p) break;
            if(i-j+1>=t) t=i-j+1;  
            }
    }
    cout<<t<<endl;
    return 0;
}