#include<iostream>
#include<algorithm>
using namespace std;
int cutrod(int prices[], int n){
    if(n==0){
        return 0;
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=max(res,prices[i]+cutrod(prices,n-i-1));
    }
    return res;
    
}
int main(){
    int prices[10]={1,2,3,4,5,6,7,8,9};
    int n=10;
    int result=cutrod(prices,n);
    cout<<result<<endl;
    return 0;
}