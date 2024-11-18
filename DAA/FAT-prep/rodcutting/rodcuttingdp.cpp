#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cutroddp(vector<int>&price){
    int n=price.size();
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=0;j<i;j++){
            res=max(res,price[j]+dp[i-j-1]);
        }
        dp[i]=res;
    }
    return dp[n];
}
int main(){
    vector<int>prices={1,2,3,4,5,6,7,8,9};
    int result=cutroddp(prices);
    cout<<result<<endl;
    return 0;
}