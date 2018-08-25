#include<iostream>
#include<algorithm>
#include<string.h>
#include<deque>
using namespace std;
struct student{
    char name[20];
    int tall;
};
bool operator < (const student &a,const student &b){
    if(a.tall!=b.tall) return a.tall>b.tall;
    else return strcmp(a.name,b.name);
}
template<class T>
void nk(T *a,int low,int top){
    deque<T> b;
    b.push_back(a[low]);
    for(int i=low+1;i<=top;){
        b.push_front(a[i++]);
        if(i>top) break;
        b.push_back(a[i++]);
    }
    for(int i=0;i<=top-low;i++){
        a[low+i]=b[i];
        //cout<<b[i].tall<<" ";
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    student a[n];
    for(int i=0;i<n;i++){
        scanf("%s%d",a[i].name,&a[i].tall);
    }
    sort(a,a+n);
    int low=0;
    int p=n%k+k;
    for(int i=0;i<n/k;i++){
        nk(a,low,p-1);
        for(int t=low;t<p;t++){
            if(t!=low) printf(" ");
            printf("%s",a[t].name);
        }
        printf("\n");
        low=p;
        p=p+k;
    }
    return 0;
}