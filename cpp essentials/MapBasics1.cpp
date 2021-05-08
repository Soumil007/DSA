// #include<iostream>
// #include<unordered_map>
// #include<string>
// #include<sstream>
#include <bits/stdc++.h>
using namespace std;
void findFrequencies(string line){
    unordered_map<string,int> freq;
    stringstream s(line); //sstream header file
    string word;
    while(s >> word){
        // // cout<<word<<endl;
        // if(freq.find(word) == freq.end()){
        //     freq.insert(make_pair(word,1));
        // }else{

        // }
        freq[word]++;
    }
    unordered_map<string,int>::iterator itr;
    for(itr = freq.begin();itr!=freq.end();++itr){
        cout<<"("<<itr->first<<","<<itr->second<<")"<<endl;
    }

}
int main(){
    
    string line = "geeks for geeks geeks quiz "
                 "practice qa for";
    findFrequencies(line);
    return 0;
}