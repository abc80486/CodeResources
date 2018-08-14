//包括冒泡排序，希尔排序，快速排序，归并排序；

#include<iostream>
using namespace std;
//冒泡排序时间复杂度O（n*n);
template<class T>
void BubbSort(T *r,int length){
    int n=length;bool change=true;
    for(int i=1;i<=n-1 && change;++i){
        change=false;
        for(int j=0;j<n-1;++j)
            if(r[j]>r[j+1]){
                T x=r[j];r[j]=r[j+1];r[j+1]=x;
                change=true;
            }
    }
}
//快速排序，对冒泡排序的改进；类似二分法；


template<class T>
int QSort(T *r,int left,int right){
    T x=r[left];
    int low=left,high=right;
    while(low<high){
        while(low<high && r[high]>=x) high--;
        if(low<high){r[low]=r[high];low++;}
        while(low<high && r[low]<x) low++;
        if(low<high) {r[high]=r[low];high--;}
    }
    r[low]=x;return low;

}
template<class T>
void QKsort(T *r,int low,int high){
    if(low<high){
        int pos=QSort(r,low,high);
        QKsort(r,low,pos-1);
        QKsort(r,pos+1,high);
    }
}
template<class T>
void QuickSort(T *r,int endaddr){
    QKsort(r,0,endaddr-1);
}
int main(){
    int n=5;
    int a[n]={6,9,1,2,7};
    //BubbSort(a,n);
    QuickSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<endl;
    return 0;
}