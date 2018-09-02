//深入理解插入与归并排序
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
bool equal(int a[],int b[],int n){
    for(int k=0;k<n;k++){
        if(a[k]!=b[k]) return false;
    }
    return true;
}
void merger(int a[],int b[],int n){
    int edge=1;
    for(;;edge*=2){
        bool istrue=true;
        istrue=equal(a,b,n);
        for(int j=0;j<n;j+=edge){
            int temp=edge+j;
            if(temp>n){
                temp=n;
            }
            sort(a+j,a+temp);
        }
        if(istrue){
            cout<<"Merge Sort"<<endl;
            break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a1[n+5],a2[n+5];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    for(int i=0;i<n;i++){
        cin>>a2[i];
    }
    int i,j;
    for(i=0;a2[i]<=a2[i+1]&&i<n-1;i++);
     for(j=++i;a1[j]==a2[j]&&j<n;j++);
    if(j==n){
        cout<<"Insertion Sort"<<endl;
        sort(a1,a1+i+1);
    }
    else merger(a1,a2,n);
    for(int k=0;k<n;k++){
        if(k!=0) cout<<" ";
        cout<<a1[k];
    }
    return 0;
}
