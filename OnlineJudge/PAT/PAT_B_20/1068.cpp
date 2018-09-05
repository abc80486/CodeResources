//万绿丛中一点红
#include<iostream>
#include<map>
using namespace std;
int m,n,kk;
int a[1000][1000];
bool istrue(const int i,const int j){
    int dir[8][2]={
        {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}
    };
    for(int k=0;k<8;k++){
        int tx=i+dir[k][0];
        int ty=j+dir[k][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&a[i][j]-a[tx][ty]>=0-kk&&a[i][j]-a[tx][ty]<=kk)
        return false;
    }
    return true;
}
int main(){
    cin>>m>>n>>kk;
    map<int,int> ma;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            ma[a[i][j]]++;
        }
    }
    int x,y,p=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ma[a[i][j]]==1&&istrue(i,j)==true){
                p++;
                x=i+1;
                y=j+1;
            }
            if(p>1) {cout<<"Not Unique"<<endl;break;}
        }
        if(p>1) break;
    }
    if(p==0) cout<<"Not Exist"<<endl;
    if(p==1) printf("(%d, %d): %d\n",y,x,a[x-1][y-1]);
    //else cout<<"Not Unique"<<endl;
    return 0;
}
/*
8 6 200
0        0        0        0        0        0        0        0
65280    65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280    65280    65280    65280    65280    65280    165280   165280
65280    65280    16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
*/