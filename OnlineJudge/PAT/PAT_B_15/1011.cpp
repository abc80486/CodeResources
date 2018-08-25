#include<iostream>
using namespace std;
int main(){
    long long a,b,c;
    int n;
    cin>>n;
    //cout<<n<<endl;return 0;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        cout<<"Case #"<<i<<": ";
        if(a+b>c) cout<<"true";
        else cout<<"false";
        cout<<endl;
    }
    return 0;
