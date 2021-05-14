/*
Say that you are a traveller on a 2d-grid. 
You beigin in the top-left corner and your goal is to reach bottom-right corner.
You may only move down or right 

In how many ways can you travel to the goal on a grid with dimension m*n?

*/


//This is coded using memoization


#include<bits/stdc++.h>
using namespace std;
// int gridTraveller(int m,int n){
//     if(m==1 && n==1) return 1;
//     if(m==0 || n==0) return 0;
//     return gridTraveller(m-1,n) + gridTraveller(m,n-1);
// }

class GridTraveller {
    public:
        map<string,int> memo;
        int gridTraveller(int m,int n){
            string key = to_string(m)+","+to_string(n);
            string keyrev = to_string(n)+","+to_string(m);
            
            //since gridtraveller(m,n) == gridtraveller(n,m)
            if(memo[key] || memo[keyrev]){
                cout<<key<<"-->"<<memo[key]<<" ";
                return memo[key];
            }else{
                if(m==1 && n==1) return 1;
                if(m==0 || n==0) return 0;

                memo[keyrev] = memo[key] = gridTraveller(m-1,n)+gridTraveller(m,n-1);
                return memo[key];
            }
        }
};

int main(){
    // cout<<gridTraveller(1,1)<<endl;
    // cout<<gridTraveller(3,3)<<endl;
    GridTraveller g1,g2,g3,g4;
    cout<<g1.gridTraveller(1,1)<<endl;
    cout<<g2.gridTraveller(3,3)<<endl;
    cout<<g3.gridTraveller(2,3)<<endl;
    cout<<g4.gridTraveller(15,15)<<endl;
    return 0;
}