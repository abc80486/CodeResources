//集体照
/*
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
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    string name;
    int height;
};
int cmp(struct node a,struct node b){
    return a.height!=b.height?a.height>b.height:a.name<b.name;
}
int main(){
    int n,k,m;
    cin>>n>>k;
    vector<node> stu(n);
    for(int i=0;i<n;i++){
        cin>>stu[i].name;
        cin>>stu[i].height;
    }
    sort(stu.begin(),stu.end(),cmp);
    int t=0,row=k;
    while(row){
        if(row==k) m=n-n/k*(k-1);
        else m=n/k;
        vector<string> stemp(m);
        stemp[m/2]=stu[t].name;
        int j=m/2-1;
        for(int i=t+1;i<t+m;i=i+2) stemp[j--]=stu[i].name;
        j=m/2+1;
        for(int i=t+2;i<t+m;i=i+2) stemp[j++]=stu[i].name;
        cout<<stemp[0];
        for(int i=1;i<m;i++) cout<<" "<<stemp[i];
        cout<<endl;
        t=t+m;
        row--;
    }
    return 0;
}
