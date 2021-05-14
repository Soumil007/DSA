#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> memo;
    memo.insert(pair<string,int>("one",1));
    memo.insert(pair<string,int>("two",2));

    cout<<memo["two"]<<endl;

    int a = 2,b = 3;
    string exmp = to_string(a) + "," + to_string(b);
    cout<<exmp<<endl;
    // memo[exmp] = 23;
    cout<<memo[exmp]<<endl;

    map<string,int> :: iterator itr;
    for(itr = memo.begin();itr!=memo.end();itr++){
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }
    if(memo[exmp]){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;

}