#include<bits/stdc++.h>
#define null vector<int> {-1}
using namespace std;
vector<int> howSum(int targetSum,vector<int> &numbers,unordered_map<int,vector<int>> &memo){
    if(memo.count(targetSum)){
        return memo[targetSum];
    }
    if(targetSum==0)
         return {};
    if(targetSum < 0)
        return null;
    for(auto num = numbers.begin();num!=numbers.end();num++){
        int remainder = targetSum - *num;
        vector<int> remainderResult = howSum(remainder,numbers,memo);
        if(remainderResult!=null){
            remainderResult.push_back(*num);
            memo[targetSum] = remainderResult;
            return remainderResult;
        }   
    }
    memo[targetSum] = null;
    return null;
}
int main(){
    vector<int> numbers,resultArr;
    unordered_map<int,vector<int>> memo;
    // numbers.push_back(5);
    // numbers.push_back(3);
    // numbers.push_back(4);
    numbers.push_back(7);
    numbers.push_back(14);

    //checking vector
    // for(auto i = numbers.begin();i!=numbers.end();i++){
    //     cout<<*i<<" ";
    // }

    resultArr = howSum(300,numbers,memo);
    
    if(resultArr!=null){
        for(int res:resultArr){
            cout<<res<<" ";
        }
    }else{
        cout<<"Not possible"<<endl;
    }
    return 0;

}