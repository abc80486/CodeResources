#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int> &numbers,int target){
        vector<int> ret;
        if(numbers.size()<=1) return ret;
        unordered_map<int,int> myMap;
        for(int i=0;i<numbers.size();++i)
            myMap[numbers[i]]=i;
        for(int i=0;i<numbers.size();++i){
            int rest_val=target-numbers[i];
            if(myMap.find(rest_val)!=myMap.end()){
                int index = myMap[rest_val];
                if(index == i) continue;
                if(index<i){
                    ret.push_back(index+1);
                    ret.push_back(i+1);
                    return ret;
                }
                else{
                    ret.push_back(i+1);
                    ret.push_back(index+1);
                    return ret;
                }
            }
        }
    }
};