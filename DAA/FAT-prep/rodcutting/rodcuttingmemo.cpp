#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cutrodmemo(int prices[],int n,vector<int> memo){
    if(n==0){
        return 0;
    }
    if(memo[n]!=-1){
        return memo[n];
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=max(res,prices[i]+cutrodmemo(prices,n-i-1,memo));
    }
    return memo[n]=res;
}
int main(){
   
    int prices[10]={1,2,3,4,5,6,7,8,9};
    int n=10;
    vector<int> memo(n+1,-1);
    int result=cutrodmemo(prices,n,memo);
    cout<<result<<endl;
    return 0;
}