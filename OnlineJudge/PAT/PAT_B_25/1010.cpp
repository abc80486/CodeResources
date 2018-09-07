#include<cstdio>
int main(){
    int m,n,t=0;
    while(scanf("%d %d",&m,&n)!=EOF){
        if(n!=0){
            if(t!=0) printf(" ");
            printf("%d %d",m*n,n-1);
            t=1;
        }
        
    }
    if(t==0) printf("0 0");
    return 0;
}