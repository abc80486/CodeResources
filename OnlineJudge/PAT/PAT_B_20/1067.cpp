#include<iostream>
using namespace std;
int main(){
    string a;
    int n,k=0;
    cin>>a>>n;
    getchar();
    while(1){
        string ch;
        getline(cin,ch);
        if(ch=="#") break;
        if(ch==a) {cout<<"Welcome in";break;}
        else{
            k++;
            cout<<"Wrong password: "<<ch<<endl;
            if(k==n) {cout<<"Account locked";break;}
        }
    }
    return 0;
}