#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int N=1000+5;

void fillflame(int *b,int n,int r,int l,int (*a)[N],int p){
    int i=0,j=p;
    //if(n==0) break;
    for(;j<l+p;j++) a[i][j]=b[n--];
    j--;i++;
    for(;i<r;i++) a[i][j]=b[n--];
    j--;i--;
    if(i==0||j<p) return;
    for(;j>=p;j--) a[i][j]=b[n--];
    j++;i--;
    for(;i>=1;i--) a[i][j]=b[n--];
}
int main(){
    int n;
    
    cin>>n;
    int dcin[n],a[n][N]={0};
    for(int i=0;i<n;i++) cin>>dcin[i];
    sort(dcin,dcin+n);
    int low,rol;
    for(int j=sqrt(n);j>=1;j--){
        if(n%j==0){
            int i=n/j;
            low=i,rol=j;
            int p=0,k=n,q=n;
            
            while(q>0){
                if(j<=1) k=i;
                else if(i<=1) k=j;
                else k=2*j+(i-2)*2;
                fillflame(dcin,q-1,i,j,a+p,p);
                p++;
                i=i-2;j=j-2;
                if(i<=0||j<=0) break;
                q=n-k;
            }
            break;

        }
    }
    for(int i=0;i<low;i++){
        for(int j=0;j<rol;j++){
            if(j!=0) cout<<" ";
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}

// 13
// 37 76 20 98 76 42 53 95 60 81 58 93 56

