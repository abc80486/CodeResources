
/*
#include<iostream>
using namespace std;
struct stu{
    int value,next;
};
int main(){
    stu list[100005];
    int firstadd,n,l;
    scanf("%d%d%d",&firstadd,&n,&l);
    int first[n][2], end[n][2];
    while(n--){
        int ch;
        scanf("%d",&ch);
        scanf("%d%d",&list[ch].value,&list[ch].next);
    }
    int k=0;
    while(firstadd!=-1){
        first[k][1]=firstadd;
        first[k++][0]=list[firstadd].value;
        firstadd=list[firstadd].next;
    }
    n=k;
    int t;
    for(int i=0;i<n;i++) {
        if(i>=(n-n%l)) {
            end[i][0]=first[i][0];
             end[i][1]=first[i][1];
            }
        else{
            if(i%l==0){
            for(int j=i;j<i+l;j++){
                end[i+i+l-1-j][0]=first[j][0];
                end[i+i+l-1-j][1]=first[j][1];
            }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i==0){
            printf("%05d %d",end[i][1],end[i][0]);
        }
        else{
         printf(" %05d\n%05d %d",end[i][1],end[i][1],end[i][0]);
           
        }
    }
    cout<<" -1"<<endl;
    return 0;
}
*/
//看完别人的代码后，感觉自己写的就是一坨屎；
//深度背熟reverse函数的使用；
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int first, k, n, temp;
    cin >> first >> n >> k;
    int data[100005], next[100005], list[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int sum = 0;//不一定所有的输入的结点都是有用的，加个计数器
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < (sum - sum % k); i += k)
        reverse(begin(list) + i, begin(list) + i + k);
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    printf("%05d %d -1", list[sum - 1], data[list[sum - 1]]);
    return 0;
}