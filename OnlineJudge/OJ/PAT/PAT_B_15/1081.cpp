#include<iostream>
int main(){
    int n;
    scanf("%d ",&n);
    while(n--){
        char ch;
        int k=0;
        bool illchar=false,num=false,abc=false;
        while((ch=getchar())!=10){
            k++;
            if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')) abc=true;
            else if(ch>='0'&&ch<='9') num=true;
            else if(ch=='.') ;
            else illchar=true;
            //if(k>=6 && illchar==true) break;
        }
        if(k<6){
            printf("Your password is tai duan le.\n");
        }
        else{
            if(illchar==true) printf("Your password is tai luan le.\n");
            else if(abc==true&&num==false) printf("Your password needs shu zi.\n");
            else if(abc==false && num==true) printf("Your password needs zi mu.\n");
            else if(abc==true && num ==true)printf("Your password is wan mei.\n");
            else ;
        }
    }
    return 0;
}