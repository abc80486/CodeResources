#include<iostream>
#include<cstdio>
using namespace std;
const int N=20;
double a[N][N]={0};
/*
void zero(int n,int m){
    double k;
    for(int i=m+1;i<=n;i++){
        if(a[m][m]!=0){
        k=-a[i][m]/a[m][m];
        for(int j=m;j<=n;j++){
            a[i][j]+=a[m][m]*k;
        }
        }
    }

}
*/
int main(){
    double fun(int n);
    //int n,k=1;
    //double s=1.0;
    int n;
    double s,sum=0.0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    if(n==2){
        sum=a[1][1]*a[2][2]-a[1][2]*a[2][1];
    }
    else{
    for(int i=1;i<=n;i++){
        int k;
        k=i;
        s=1.0;
        for(int j=1;j<=n;j++){
            s=s*a[j][k];
            k=k+1;
           if(k>n) k=1;
           // k=(k++)%n;
        }
        //cout<<s<<endl;
        sum=sum+s;
    }
    for(int i=n;i>=1;i--){
        s=1.0;
        int k=i;
        for(int j=1;j<=n;j++){
            //int k=i;
            s=s*a[j][k];
            k--;
            if(k==0) k=n;
            //k=(k++)%n;
        }
        //cout<<s<<endl;
        sum=sum-s;
    }
    }
    cout<<sum<<endl;

    /*
    for(int i=1;i<=n-2;i++){
        if(a[i][i]==0){
            int p=0;
            for(int j=i;i<=n;i++){
                if(a[i][j]!=0){
                    for(int t=i;t<=n;t++){
                        k=-k;p=1;
                        int e;
                        e=a[t][i];
                        a[t][i]=a[t][j];
                        a[t][j]=e;
                    }
                    break;
                }
            }
            if(p==0) {cout<<"0"<<endl;return 0;}
        }
        zero(n,i);
    }
    */
  // cout<<fun(n)<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lf  ",a[i][j]);
        }
        cout<<endl;
    }
    /*
    for(int i=1;i<=n-2;i++){
        s*=a[i][i];
    }
    s*=a[n-1][n-1]*a[n][n]-a[n-1][n]*a[n][n-1];
    //cout<<s<<endl;
    */
    return 0;
}
double fun(int n){
    double s,sum=0.0;
    for(int i=1;i<=n;i++){
        int k=i;
        s=1.0;
        for(int j=1;j<=n;j++){
            //int k=i;
            s=s*a[k++%n][j];
           // k=(k++)%n;
        }
        sum+=s;
    }
    for(int i=n;i>=1;i--){
        s=1.0;
        int k=i;
        for(int j=1;j<=n;j++){
            //int k=i;
            s=s*a[k++%n][j];
            //k=(k++)%n;
        }
        sum-=s;
    }
    return sum;
}