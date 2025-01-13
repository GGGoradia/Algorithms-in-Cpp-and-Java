#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
bool isunique(string str){
    if(str.length()>128){
        return false;
    }
    vector<bool> arr(128,false);
    for(int i=0;i<str.length();i++){
        int val=str[i];
        if(arr[val]){
            return false;
        }
    }
    cout<<"true"<<endl;
    return true;
}
int main(){
    string str="dev";
    cout<<isunique(str)<<endl;
    return 0;
}