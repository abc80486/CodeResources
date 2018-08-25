#include<iostream>
using namespace std;

void print_permutation(int n,int *a,int cur){
    if(cur==n){
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    else{
        for(int i=1;i<=n;i++){
            int ok=1;
            for(int j=0;j<cur;j++)
                if(a[j]==i) ok=0;
            if(ok){
                a[cur]=i;
                print_permutation(n,a,cur+1);
            }
        }
    }
}
int main(){
    
    int n;
    cin>>n;
    int a[n];
    print_permutation(n,a,0);
    return 0;

}