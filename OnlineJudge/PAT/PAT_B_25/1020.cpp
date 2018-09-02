#include<iostream>
#include<algorithm>
using namespace std;
struct moon{
    double quantity;
    double sumprice;
};
bool operator < (const moon& a,const moon& b){
    return double(a.sumprice)/a.quantity > double(b.sumprice)/b.quantity;
}
int main(){
    int n,sum;
    cin>>n>>sum;
    moon a[n];
    for(int i=0;i<n;i++) cin>>a[i].quantity;
    for(int i=0;i<n;i++) cin>>a[i].sumprice;
    sort(a,a+n);
    double t=0.0;
    //cout<<a[0].sumprice<<endl;
    for(int i=0;i<n;i++){
        if(sum>=a[i].quantity){
            t+=double(a[i].sumprice);sum-=a[i].quantity;
        }
        else{
            t+=double(sum)/a[i].quantity*a[i].sumprice;
            break;
        }
    }
    printf("%.2lf\n",t);
    return 0;
}

