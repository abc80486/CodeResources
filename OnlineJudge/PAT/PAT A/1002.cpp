#include<iostream>
#include<map>
using namespace std;
map<int,float> ans;
int main(){
    void fcin(int k);
    int n,m;
    cin>>n;
    fcin(n);
    cin>>m;
    fcin(m);
    int t=ans.size();
    cout<<t;
    for(map<int,float>::reverse_iterator it=ans.rbegin();it!=ans.rend();it++){
        cout<<" "<<it->first<<" "<<it->second;
    }
    return 0;
}
void fcin(int k){
    while(k--){
        int p;float q;
        cin>>p>>q;
        ans[p]+=q;
    }
}