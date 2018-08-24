//爱丁堡数
#include<iostream>
using namespace std;
const int N=100000+5;
int main(){
    int n,a[N]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp!=0 && temp<=100000) a[temp]++;
        if(temp>100000) a[0]++;
    }
    int p=a[100000],q;
    a[100000]=a[0];
    for(int i=99999;i>0;i--){
        q=a[i];
        a[i]=a[i+1]+p;
        p=q;
        if(a[i]==i) printf("%d\n",i);
    }
    return 0;
}