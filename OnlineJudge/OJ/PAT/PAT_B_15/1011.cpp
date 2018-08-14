<<<<<<< HEAD:OnlineJudge/OJ/PAT/PAT B 1-15/1011.cpp
#include<iostream>
using namespace std;
int main(){
    long long a,b,c;
    int n;
    cin>>n;
    cout<<n<<endl;return 0;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        cout<<"Case #"<<i<<": ";
        if(a+b>c) cout<<"true";
        else cout<<"false";
        cout<<endl;
    }
    return 0;
=======
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
>>>>>>> 6556a053fc79f890eb9c729c3449bec9cdabcbdf:OnlineJudge/OJ/PAT/PAT_B_15/1011.cpp
}