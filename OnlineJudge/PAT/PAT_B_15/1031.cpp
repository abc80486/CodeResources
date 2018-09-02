//简单字符操作
#include<cstdio>
using namespace std;
int main(){
    int n,p=1;
    char m[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    int qz[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    scanf("%d",&n);
    while(n--){
        char str1[19],mm;
        int sum=0,k=1;
        scanf("%s",str1);
        for(int i=0;i<17;i++){
            if(str1[i]>='0'&&str1[i]<='9') 
                sum+=(str1[i]-'0')*qz[i];
            else{printf("%s\n",str1);k=0;break;p=0;}
        }
        if(k==1) {
            mm=m[sum%11];
            if(mm!=str1[17]) {printf("%s\n",str1);p=0;}
        }
    }
    if(p==1) printf("All passed\n");
    return 0;
}