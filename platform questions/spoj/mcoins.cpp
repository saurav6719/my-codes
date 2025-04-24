#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int k,l,m; //  m = number of games
    cin>>k>>l>>m;
     
    vector<bool> dp(10000005, 0); // phle se maan ke chal rhe saare lossong state ho winning v maan skte hai 
    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;
    for(int i = 2 ; i<= 1000000 ; i++){
        if(i == k or i == l ) continue;
        dp[i] = !(dp[i-1] and (i-k > 0 ? dp[i-k] : 1)and (i-l > 0 ? dp[i-l] : 1)); //else 1 isliye le rhe qki and me
                                                                                        // 1 se fark nhi pdega
    }
    for(int i = 0; i< m ; i++){
        int n;
        cin>>n;
        if(dp[n] == 0) {// n is  a lossing state
            cout<<"B";
        }
        else{
            cout<<"A";
        }
    }
}