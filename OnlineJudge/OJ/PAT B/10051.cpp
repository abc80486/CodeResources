#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
 
bool compare(int i, int j){
	return j<i;
}
int main() {
	int n(0); //待验证整数个数
	cin >> n;
	vector<int> a(100);   //记录（3n+1)过程中出现每个数的次数 
	vector<int> b(n);   //保存每个待验证整数
	vector<int>::iterator it;
	for(it=b.begin();it!=b.end();it++){
		int temp;
		cin >> *it;
		temp = *it;
		a[temp]++;
		if(temp==1){
			a[temp]++;
		}else{
			while(temp!=1){
				if(temp%2==0){
					temp/=2;
					if(temp<=100)    //超过100无意义，不需记录 
					a[temp]++;
				}else{
					temp=(3*temp+1)/2;
					if(temp<=100)
					a[temp]++;
				}
			}
		}
	}
	
	sort(b.begin(),b.end(),compare);  //按降序排序
	int count(0);  //记录关键数个数 
	vector<int> key(1);  // 保存关键数 
	for(it=b.begin();it!=b.end();it++){
		if(a[*it]==1){
			key[count++]=*it;
			key.resize(count+1);
		} 
	} 
	
	//按要求输出结果 
	for(it=key.begin();it!=key.end()-1;it++){
		
		if(it!=key.end()-2){
			cout << *it << " ";
		}
		else{
			cout << *it;
		}
	}
	return 0;
}