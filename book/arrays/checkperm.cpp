#include<bits/stdc++.h>
using namespace std;
bool sol1(string str1,string str2){
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    if(str1==str2){
        return true;
    }
    return false;

}
int main(){
    string str="dev";
    string str2="ved";
    bool val =sol1(str,str2);
    cout<<val<<endl;
}
