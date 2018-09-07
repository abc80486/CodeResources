#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
     getchar();
    while(n--){
        int ap=0,pat=0,ta=0,k=0;
        char ch;

        bool fp=false,ft=false;
        bool pn=false,tn=false;
        while((ch=getchar())!='\n'){
            //cout<<ch<<" ";
            
            if(k==0){
            if(ch=='A') {
                if(fp==false){
                ap++;}
                else{
                    if(ft==false){
                        pat++;
                    }
                    else ta++;
                }
            }
            else if(ch=='P' && pn==false) {
                fp=true;pn=true;}
            else if(ch=='T' && tn==false && fp==true){
                ft=true;tn=true;}
            else {k=1;}
            }
        }
        if(k==1 || fp==false || ft==false) {cout<<"NO"<<endl;}
        else if(ap==0 && ta==0 && pat!=0) {
            cout<<"YES"<<endl;                                     
        }
        else if(ap!=0 && ta!=0 && ta/ap==pat) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        
    }
    return 0;
}
/*
while(n--){
    int p=0,t=0,a=0,b=0,c=0;
    string ch;
    cin>>ch;
    for(int i=0;i<ch.length();i++){
        if(ch[i]=='P'){
            p++;
        }else if(ch[i]=='A'){
            if(p==0&&t==0) a++;
            else if(p==1&&t==0) b++;
            else if(p==1&&t==1) c++;
            else {cout<<"NO"<<endl;break;}
        }else if(ch[i]=='T'){
            t++;
        }else{
            cout<<"NO"<<endl;break;}
    }
    if(p==1&&t==1){
        if(a==0&&c==0&&b>0) {cout<<"YES"<<endl;break;}
        else if(b==0) {cout<<"NO"<<endl;break;}
        else if(c/a==b) {cout<<"YES"<<endl;} 
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;

}
*/