/*
    canSum(targetSum,[numbers])
    write a function canSum which will return bool values, 
    depending wether we can achieve the target sum from the array of numbers,
    given we can use the numbers in the array as many times as we want to.
    Assume the numbers in the array to be non-negative
    
*/
#include<bits/stdc++.h>
using namespace std;
class CanSum{
    public:
        
        int canSum(int targetSum, int numbers[],int size,map<int,int> &memo){
            if(memo.count(targetSum)){
                cout<<"using memo"<<endl;
                // cout<<targetSum<<"--->"<<memo[targetSum]<<" ";
                return memo[targetSum];
            }
            if(targetSum == 0){
                
                return 1;
            } 
            
            if(targetSum < 0){
                
                return 0;
            } 

            for(int i=0;i<size;i++){
                int remainder = targetSum - numbers[i];
                if(canSum(remainder,numbers,size,memo) == true){
                    memo[targetSum] = 1;
                    return 1;
                }
            }
            
            return 0;

            
        }
        void printMemo(map<int,int> &memo){
            map<int,int>::iterator itr;
            cout<<"Printing Memo"<<endl;
            for(itr = memo.begin();itr!=memo.end();++itr){
                cout<<"("<<itr->first<<","<<itr->second<<")"<<endl;
            }
        }
};

int main(){
    map<int,int> memo;
    CanSum c1,c2,c3,c4;
    int arr1[] = {5,3,4,7};
    int arr2[] = {2,4};
    int arr3[] = {2,3,5};
    int arr4[] = {7,14};
    cout<<c1.canSum(7,arr1,4,memo)<<endl;
    // c1.printMemo();
    cout<<c2.canSum(7,arr2,2,memo)<<endl;
    cout<<c3.canSum(8,arr3,3,memo)<<endl;
    // c3.printMemo(memo);
    cout<<c4.canSum(140,arr4,2,memo)<<endl;
    // c4.printMemo();

    return 0;
}