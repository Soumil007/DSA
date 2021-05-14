//here we are using memoization to calculate the fibonacci of big numbers
#include<bits/stdc++.h>
using namespace std;
class dp_Fib{
    public:
        int memo[1000]={0};
        int fib(int n){
            if(n<=2){
                return 1;
            }else{
                if(memo[n]!=0){
                    cout<<memo[n]<<" ";
                    return memo[n];
                }else{
                    memo[n] = fib(n-1) + fib(n-2);
                    cout<<memo[n]<<" ";
                    return memo[n]; 
                }
            }
        }
};
int main(){
    dp_Fib f1,f2,f3;
    cout<<f1.fib(10)<<endl;
    cout<<f2.fib(20)<<endl;
    cout<<f3.fib(30)<<endl;
    cout<<f3.fib(40)<<endl;
    return 0;
}