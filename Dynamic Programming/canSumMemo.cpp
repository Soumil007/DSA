/*
    canSum(targetSum,[numbers])
    write a function canSum which will return bool values, 
    depending wether we can achieve the target sum from the array of numbers,
    given we can use the numbers in the array as many times as we want to.
    Assume the numbers in the array to be non-negative
    
*/
#include<bits/stdc++.h>

using namespace std;

bool canSum(int targetSum, int num[], int size,unordered_map<int,bool> &memo){
    bool res;
    if(memo.count(targetSum)){
        return memo[targetSum];
    }
    if(targetSum==0){
        return true;
    }
    for(int i=0;i<size;i++){
        if(targetSum-num[i]>=0){
            res = canSum(targetSum-num[i],num,3,memo);
            memo[targetSum] = res;
            if(res){
                return true;
            }
        }
    }

    return false;

    
}


int main(){
    int arr1[] = {3,3};
    bool res;
    unordered_map<int,bool> memo;
    res = canSum(13,arr1,2,memo);
    if(res){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Not Possible"<<endl;
    }
    return 0;
}


