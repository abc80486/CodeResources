//单身狗
#include<iostream>

#include<set>
#include<algorithm>
using namespace std;
const int N=100000+5;
int main(){
    int n,a[N]={0},m;
    bool b[N]={false};
   // ostream_iterator<int> output(cout," ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int boy,girl;
        scanf("%d%d",&boy,&girl);
        a[boy]=girl;a[girl]=boy;
    }
    scanf("%d",&m);
    set<int> t;
    for(int i=0;i<m;i++){
        int temp;
        scanf("%d",&temp);
        b[temp]=true;
    }
    for(int i=N-1;i>=1;i--){
        if(b[i]==true){
            if(a[i]==0) t.insert(i);
            else{
                if(b[a[i]]==false) t.insert(i);
            }
        }
    }
    cout<<t.size()<<endl;
    for(set<int>::iterator it=t.begin();it!=t.end();it++){
        if(it!=t.begin()) printf(" ");
        printf("%d",*it);
    }
    printf("\n");
    //copy(t.begin(),t.end(),output);
    return 0;
}
/*
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
*/