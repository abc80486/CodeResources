//1058选择题
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n,m,temp,k;
    scanf("%d%d",&n,&m);
    vector<set<char> > right(m);
    vector<int> total(m),wrong(m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&total[i],&temp,&k);
        for(int j=0;j<k;j++){
            char c;
            scanf(" %c",&c);
            right[i].insert(c);
        }
    }
    for(int i=0;i<n;i++){
        int score=0;
        scanf("\n");
        for(int j=0;j<m;j++){
            if(j!=0) scanf(" ");
            scanf("(%d",&k);
            set<char> st;
            char c;
            for(int l=0;l<k;l++){
                scanf(" %c",&c);
                st.insert(c);
            }
            scanf(")");
            if(st==right[j]){
                score+=total[j];
            }else{
                wrong[j]++;
            }
        }
        printf("%d\n",score);
    }
    int maxwrong=0;
    for(int i=0;i<m;i++){
        if(wrong[i]>maxwrong) maxwrong=wrong[i];
    }
    if(maxwrong==0) printf("Too simple");
    else{
        printf("%d",maxwrong);
        for(int i=0;i<m;i++){
            if(wrong[i]==maxwrong) printf(" %d",i+1);
        }
    }
    return 0;
}