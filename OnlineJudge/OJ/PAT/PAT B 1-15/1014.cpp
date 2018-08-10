#include<iostream>
#include<string>
using namespace std;
int main(){
    char a[4][65];
    for(int i=0;i<4;i++){
        scanf("%s",a[i]);
        //printf("%c\n",a[i][0]);
    }
    //cout<<a[2][1]<<endl;
    int day,hh;
    int k=1;
    for(int i=0;a[0][i]!='\0';i++){
        if(k==2){
            if(a[0][i]==a[1][i]){ 
                if(a[0][i]>='0'&&a[0][i]<='9') {
                    hh=int(a[0][i]-'0');break;}
                if(a[0][i]>='A'&&a[0][i]<='N') {
                    hh=int(a[0][i]-'A')+10;//cout<<a[0][i]<<endl;
                    break;}
               
            }
        } 
        if(k==1){
            if(a[0][i]==a[1][i]&&a[0][i]>='A'&&a[0][i]<='G') {
                k=2;
                day=int(a[0][i]-'A');
            }
        }
        
    }
    int mm=0;
    for(int i=0;a[2][i]!='\0';i++){
        if(a[2][i]==a[3][i]) {
            //mm=i;break;
            if(a[2][i]>='a'&&a[2][i]<='z'){
            mm=i;break;}
            if(a[2][i]>='A'&&a[2][i]<='Z'){
            mm=i;break;}
        }
    }
    const string da[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cout<<da[day]<<" ";
    if(hh<10) cout<<"0";
    cout<<hh<<":";
    if(mm<10) cout<<"0";
     cout<<mm;
    return 0;
}
