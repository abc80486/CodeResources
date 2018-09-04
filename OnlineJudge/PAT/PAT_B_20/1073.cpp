//多选题常见记分法
#include<iostream>
using namespace std;
struct title{
    int score;
    int ansselect;
    int ansnum;
    bool ans[5];
    int wrongnum[5]={0};

};
struct stutitle{
   int num;
   bool sans[5];  
};
int main(){
    int n,m;
    cin>>n>>m;
    title ti[m];
    double s[n];
    for(int i=0;i<m;i++){
        cin>>ti[i].score>>ti[i].ansselect>>ti[i].ansnum;
        for(int j=0;j<5;j++) ti[i].ans[j]=false;
        for(int j=0;j<ti[i].ansnum;j++){
            char ch;
            cin>>ch;
            ti[i].ans[ch-'a']=true;
        }
    }
    //for(int i=0;i<m;i++)
    //cout<<ti[i].score<<endl;return 0;
    stutitle a[m];
    for(int k=0;k<n;k++){
        s[k]=0.0;
        for(int i=0;i<m;i++){
            int p=0;
            while(getchar()!='(');
            cin>>a[i].num;
            for(int j=0;j<5;j++) a[i].sans[j]=false;
            for(int j=0;j<a[i].num;j++){
                char ch;
                cin>>ch;
                a[i].sans[ch-'a']=true;
            }
            for(int tt=0;tt<5;tt++){
                //cout<<a[i].sans[tt]<<endl;
                if(a[i].sans[tt]==true && ti[i].ans[tt]==true) p++;            
                if(ti[i].ans[tt]==false&&a[i].sans[tt]==true) 
                    ti[i].wrongnum[tt]++;
                if(ti[i].ans[tt]==true&&a[i].sans[tt]==false) 
                    ti[i].wrongnum[tt]++;
            }
            if(p==a[i].num) {
                if(p==ti[i].ansnum) s[k]+=ti[i].score;
                else s[k]+=(ti[i].score/2.0);
            }
            //cout<<p<<" "<<s[k]<<endl;
            
        }
        //return 0;
        //cout<<kk<<endl;
    }
    for(int i=0;i<n;i++) 
        //cout<<s[i]<<endl;
        printf("%.1lf\n",s[i]);
    int bb=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<5;j++)
        if(ti[i].wrongnum[j]>bb) bb=ti[i].wrongnum[j];
    }
    if(bb==0) {cout<<"Too simple"<<endl;return 0;}
    for(int i=0;i<m;i++){
        for(int j=0;j<5;j++){
            if(ti[i].wrongnum[j]==bb) cout<<bb<<" "<<i+1<<"-"<<char(j+'a')<<endl;
        }
    }
    return 0;
}
/*
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
*/