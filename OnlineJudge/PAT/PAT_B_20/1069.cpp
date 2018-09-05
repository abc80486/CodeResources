//微博转发抽奖
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<string> list;
    int p=0;
    for(int i=1;i<=n;i++){
        string ch;
        cin>>ch;
        if(i==m){
            int te=1;
            //if(find(list.begin(),list.end(),ch)==list.end()){
            for(int j=0;j<list.size();j++){
                if(ch==list[j]){te=0;break;}
            }
            if(te==1){
                cout<<ch<<endl;;
                p=1;
                list.push_back(ch);
                m+=k;
            }
            else m++;
        }
        
    }
    if(p==0) cout<<"Keep going..."<<endl;
    return 0;
}
/*
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
*/