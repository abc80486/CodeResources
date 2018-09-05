//开学寄语
#include<iostream>
using namespace std;
int  main(){
    int n,m;
    cin>>n>>m;
    string a[m];
    for(int i=0;i<m;i++) cin>>a[i];
    int k=0,p=0;
    while(n--){
        string name;
        int s;
        cin>>name>>s;
        int ui=0;
        while(s--){
            string ch;
            cin>>ch;
            for(int i=0;i<m;i++){
                if(ch==a[i]) {
                    p++;
                    if(ui==0) cout<<name<<":";
                    cout<<" "<<ch;
                    ui=1;
                    break;
                }
            }
        }
        if(ui==1) {k++;cout<<endl;}
    }
    cout<<k<<" "<<p<<endl;
    return 0;
}