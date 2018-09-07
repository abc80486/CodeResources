
/*
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int main(){
    int n;
    int fl[N+1]={0};
    bool out[N+1]={false};
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) 
        //cin>>a[i];
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int k=a[i];
        if(fl[k]==0){
             fl[k]=1;
        while(k!=1){
            if(k%2==0)  k/=2;
            else k=(3*k+1)/2;
            if(fl[k]!=0){
                out[a[i]]=true;
                if(out[k]==true) out[k]=false;
                break;
            }
            if(k<=100) fl[k]=1;
        }
        out[a[i]]=true;
        }
        else out[a[i]]=false;
    }
    int p=0;
    for(int i=100;i>=1;i--){
        if(out[i]==true) {
            p++;
            if(p!=1){cout<<" ";}
            cout<<i;
            }
    }
    cout<<endl;
    return 0;
}
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    bool arr[10000]={false};
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[i]=temp;
        while(temp!=1){
            if(temp%2!=0) temp=temp*3+1;
            temp/=2;
            if(arr[temp]==true) break;
            arr[temp]=true;
        }
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[a[i]]==false){
            if(flag==1) cout<<" ";
            cout<<a[i];
            flag=1;
        }
    }
    return 0;
}
