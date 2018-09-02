#include<iostream>
#include<cstdlib>
#include<string>
using  namespace std;

int strnum(const string &a,const string &da){
    int pa=0;
    int hx=0,k=0;
    while(hx<a.size()){
        if((hx=a.find_first_of(da,hx))>=0){
            k++;hx++;
        }
    }
    const int dai=stoi(da);
    for(int i=1;i<=k;i++){
        pa=pa*10+dai;
    }
    return pa;
}
int main(){
    int pa=0,pb=0;
    string a,da,b,db;
    cin>>a>>da>>b>>db;
    pa=strnum(a,da);
    pb=strnum(b,db);
   cout<<pa+pb<<endl;
    return 0;
}