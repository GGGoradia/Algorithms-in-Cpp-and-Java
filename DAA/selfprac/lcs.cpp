#include<vector>
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs(int i,int j,string &s1,string &s2){
    if(i<0||j<0){
        return 0;
    }
    if(s1[i]==s2[j]){
        return 1+lcs(i-1,j-1,s1,s2);
    }
    return max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2));
}
int main(){
    string s1="adb";
    string s2="deb";
    int n=s1.size();
    int m=s2.size();
    cout<<lcs(n-1,m-1,s1,s2)<<endl;
}