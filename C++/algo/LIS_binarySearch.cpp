#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
int LIS_binarySearch(T arr[],int n){//最长增长子序列，nlogn，二分查找
    T ans[n],a[n][n];
    int len=0,p=0;
    ans[0]=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>ans[len]) 
        {   
            ans[++len]=arr[i];
            p=0;
            for(int k=0;k<=len;k++){
                a[p][k]=ans[k];
            }
        }
        else 
        {
            ans[*lower_bound(ans,ans+len+1,arr[i])]=arr[i];
            p++;
            for(int k=0;k<=len;k++){
                a[p][k]=ans[k];
            }
        }
    }
    return len+1;
}