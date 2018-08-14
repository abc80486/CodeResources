#include<iostream>
int main(){
    int T,K;
    scanf("%d %d",&T,&K);
    while(K--){
        int n1,b,t,n2;
        scanf("%d %d %d %d",&n1,&b,&t,&n2);
        if(t>T) {printf("Not enough tokens.  Total = %d.\n",T);continue;}
        if((n2<n1&&b==0)||(n2>n1&&b==1)){
            T+=t;
            printf("Win %d!  Total = %d.\n",t,T);
        }
        else{
            T-=t;
            printf("Lose %d.  Total = %d.\n",t,T);
        }
        if(T==0) {printf("Game Over.\n");break;}
    }
    return 0;
}
