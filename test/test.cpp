#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int n;
bool read_list(int *a){
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n=0;
    int x;
    while(ss>>x) a[n++]=x;
    return n>0;
}
int main(){
    int a[100]={0};
    read_list(a);
    for(int i=0;i<10;i++) cout<<a[i]<<ends;
    return 0;
}