#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
    int sum=0;
    char ch;
    while((ch=getchar())!='\n'){
        sum+=int(ch-'0');
    }
    int numbit=1,t=sum;
    while(t>0){
        t/=10;
        if(t!=0) numbit++;
    }
    //cout<<numbit<<endl;
    while(numbit--){
        int s=0;
        s=sum/pow(10,numbit);
        sum%=int(pow(10,numbit));
        //printf("%s ",num[s]);
        cout<<num[s];
        if(numbit!=0) cout<<" ";
    }
    cout<<endl;
    return 0;
}