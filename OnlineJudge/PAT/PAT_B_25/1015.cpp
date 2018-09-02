#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct stu{
    int num;
    int df;
    int cf;
};
bool operator < (const stu &a,const stu &b) {
    if(a.df+a.cf!=b.df+b.cf){
        return a.df+a.cf>b.df+b.cf;
    }
    else if(a.df!=b.df) return a.df>b.df;
    else return a.num<b.num;
}
int main(){
    int n,l,h;cin>>n>>l>>h;
    int k=0;
    vector<struct stu> a[4];
    while(n--){
        stu ch;
        scanf("%d%d%d",&ch.num,&ch.df,&ch.cf);
        if(ch.df>=l&&ch.cf>=l){
            k++;
            if(ch.df>=h&&ch.cf>=h) {a[0].push_back(ch);}
            else if(ch.df>=h&&ch.cf<h) a[1].push_back(ch);
            else if(ch.df<h&&ch.cf<h&&ch.df>=ch.cf) a[2].push_back(ch);
            //else if(ch.df<h&&ch.cf<h) a[3].push_back(ch);
            else a[3].push_back(ch);
        }
    }
    cout<<k<<endl;
    for(int j=0;j<4;j++){
        sort(a[j].begin(),a[j].end());
        for(int i=0;i<a[j].size();i++){
            //a[j][i].stucout();
            printf("%d %d %d\n",a[j][i].num,a[j][i].df,a[j][i].cf);
           
        }
    }
    //cout<<a[0][0].num<<endl;

    return 0;
}