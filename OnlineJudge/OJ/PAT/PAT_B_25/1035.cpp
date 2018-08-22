#include<iostream>
using namespace std;
template<class T>
void InsertionSort(T a[],int n){
    int i,j;
    T temp;
    for(i=1;i<n;i++){
        j=i;
        temp=a[i];
        while(j>0 && temp<a[j-1]){
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
        for(int k=0;k<n;k++) printf("%d ",a[k]);
        cout<<endl;
    }
}
template<class T>
void 
int main(){
    int n;
    int a[100000],b[100000];
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    InsertionSort(a,n);
    return 0;
}
