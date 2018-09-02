#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    //cin<<n;
    scanf("%d",&n);
    long long a[n],b[n],c[n];
    for(int i=0;i<n;i++) {
        scanf("%ld",&a[i]);
        b[i]=a[i];
    }
    sort(a,a+n);
    int k=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(b[i]>max) max=b[i];
        if(a[i]==b[i] && a[i]>=max) c[k++]=a[i];
    }
    printf("%d\n",k);
    for(int i=0;i<k;i++){
        if(i!=0) printf(" ");
        printf("%d",c[i]);
    }
    return 0;
}