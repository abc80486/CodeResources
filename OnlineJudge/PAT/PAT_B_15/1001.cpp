#include<cstdio>
using namespace std;
int main(){
    int n,k=0;
    while(scanf("%d",&n)==1 ){
        while(n!=1){
        if(n%2==0) {
            n=n/2;k++;
            }
        else{
            n=3*n+1;
            n/=2;k++;
        }
        } 
        printf("%d\n",k);
    }
   
    return 0;
}