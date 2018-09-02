#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
struct student{
    string name;
    int score;
};
struct sch{
    double sum=0.0;
    int stunum=0;
};
struct sout{
    sch base;
    string school;
    bool operator<(const sout &t)const{
        if(int(this->base.sum)!=int(t.base.sum)) return int(this->base.sum)>int(t.base.sum);
        else if(this->base.stunum!=t.base.stunum){
            return this->base.stunum<t.base.stunum;
        }
        else return this->school<t.school;
    }
};
int main(){
    int n;
    map<string,struct sch> schstu; 
    map<string,struct sch>::iterator it;
    scanf("%d",&n);
    while(n--){
        student temp;string ch;
        cin>>temp.name>>temp.score>>ch;
        for(int i=0;ch[i]!='\0';i++){
            if(ch[i]>='A'&&ch[i]<='Z') ch[i]+=32;
        }
        if(temp.name[0]=='A') schstu[ch].sum+=temp.score;
        else if(temp.name[0]=='T') schstu[ch].sum+=temp.score*1.5;
        else schstu[ch].sum+=temp.score/1.5;
        schstu[ch].stunum++;
    }
    set<struct sout> endout;
    for(it=schstu.begin();it!=schstu.end();it++){
        sout temp;
        temp.school=it->first;
        temp.base=it->second;
        endout.insert(temp);
    }
    cout<<endout.size()<<endl;
    set<struct sout>::iterator ita=endout.begin();
    int sum=0,pm=1,k=0,tu;
    for(;ita!=endout.end();ita++){
        k++;
        int tenp=ita->base.sum;
        if(sum!=tenp)
            {cout<<k<<" ";tu=k;}
        else{
            cout<<pm<<" ";tu=pm;}
         cout<<ita->school<<" "<<tenp<<" " 
            <<ita->base.stunum<<endl;
        sum=tenp;pm=tu;

    }
    return 0;
}
/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

*/