#include<iostream>
using namespace std;
template<class T>
void InsertionSort(T A[],int n,T B[]){
    int i,j;
    T temp;
     int p=0;
    for(i=1;i<n;i++){
        j=i;
        temp=A[i];
        while(j>0 && temp<A[j-1]){
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
        if(p==1){
           printf("Insertion Sort\n");
           for(int k=0;k<n;k++){
               printf("%d ",A[k]);
           }
           printf("\n");
           break;
       }
        for(int k=0;k<n;k++){
            if(A[k]!=B[k]){
                break;
            }
            if(k==n-1) p=1;
        }
        
    }
}
/*
template<class T>
void Merge(T *SR,T *TR,int i,int m,int n){
    int j,k;
    for( j=m+1,k=i;i<=m && j<=n;++k){
        if(SR[i]<SR[j]) TR[k]=SR[i++];
        else TR[k]=SR[j++];
    }
    if(i<=m){
        //int q=k;
        for(int p=i;p<=m;p++){
            TR[k++]=SR[p];
        }
    }
    if(j<=n){
        for(int p=j;p<=n;p++){
            TR[k++]=SR[p];
        }
    }
}
template<class T>
void MSort(T *SR,T *TR1,int s,int t,T TR2[]){
    int m;
    if(s==t) TR1[s]=SR[s];
    else{
        m=(s+t)/2;
        MSort(SR,TR2,s,m,TR2);
        MSort(SR,TR2,m+1,t,TR2);
        Merge(TR2,TR1,s,m,t);
    }
}
template<class T>
void MergeSort(T A[],int n){
    T B[n];
    MSort(A,A,0,n-1,B);
}
*/
void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex){
            int i=startIndex,j=midIndex+1,k=startIndex;
            while(i!=midIndex+1 && j!=endIndex+1){
                if(sourceArr[i]<sourceArr[j]){
                    tempArr[k++]=sourceArr[i++];
                }
                else tempArr[k++]=sourceArr[j++];
            }
            while(i!=midIndex+1){
                tempArr[k++]=sourceArr[i++];
            }
            while(j!=endIndex+1){
                tempArr[k++]=sourceArr[j++];
            }
            for(i=startIndex;i<=endIndex;i++){
                sourceArr[i]=tempArr[i];
            }
        }
void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex){
        int midIndex;
        if(startIndex < endIndex){
            midIndex=startIndex+(endIndex-startIndex)/2;
            MergeSort(sourceArr,tempArr,midIndex,endIndex);
            MergeSort(sourceArr,tempArr,midIndex+1,endIndex);
            Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
        }
    }
void test(){
    int a[4]={5,2,6,9};
    int i,b[4];
    MergeSort(a,b,0,3);
    for(i=0;i<4;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int n;
    cin>>n;
    int first[1000],second[1000],c[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&first[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&second[i]);
    }
     //InsertionSort(first,n,second);
   //MergeSort(first,c,0,9);
   test();
   for(int k=0;k<n;k++){
       //cout<<first[k]<<" ";
       //printf("%d ",first[k]);
   }
  printf("\n");
    return 0;
}
