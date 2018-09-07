#include<iostream>
using namespace std;
struct student{
    string name, num;int score;
    void operator=(student &ch){
        name=ch.name;num=ch.num;score=ch.score;
    }
};
int main(){
    int n;
    student maxs,mins;
    maxs.score=0;mins.score=100;
    cin>>n;
    while(n--){
        student ch;
        cin>>ch.name>>ch.num>>ch.score;
        if(ch.score>maxs.score) maxs=ch;
        if(ch.score<mins.score) mins=ch;
    }
    cout<<maxs.name<<" "<<maxs.num<<endl;
    cout<<mins.name<<" "<<mins.num<<endl;
    return 0;
}