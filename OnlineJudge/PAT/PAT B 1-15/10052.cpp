#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],c[n];
    bool b[n];
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++) {cin>>a[i];b[i]=true;}
    for(int i=0;i<n;i++){
        if(b[i]==true){
            int k=a[i];
            while(k!=1){
                //bool fp=false;
                if(k%2==0) k/=2;
                else k=(k*3+1)/2;
                for(int j=0;j<n;j++){
                    if(i!=j && k==a[j]){
                        //if(j>i) fp=true;
                        b[j]=false;break;}
                }
                //if(fp==true) break;
            }
        }
    }
    int d=0;
    for(int i=0;i<n;i++){
        if(b[i]==true) c[d++]=a[i];
    }
    sort(c,c+d,greater<int>());
    int t=0;
    for(int i=0;i<d;i++){
        if(t>=1) cout<<" ";
        cout<<c[i];t++;
    }
    cout<<endl;
    return 0;
}