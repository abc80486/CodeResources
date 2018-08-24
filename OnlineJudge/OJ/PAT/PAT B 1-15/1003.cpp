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
        cout<<ap<<pat<<ta;
        if(k==1 || fp==false || ft==false) {cout<<"NO"<<endl;}
        else if(ap==0 && ta==0 && pat!=0) {
            cout<<"YES"<<endl;                                     
            //continue;
        }
        else if(ap!=0 && ta!=0 && ta/ap==pat) {
            cout<<"YES"<<endl;
            //continue;
        }
        else cout<<"NO"<<endl;
        
    }
    return 0;
}