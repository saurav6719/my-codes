#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> ans(n+1);
    if(n % 2 != 0) cout<<"-1";
    else{
        for(int i = 1; i<n+1 ;i++){
            if(i % 2 == 0){
                ans[i] = i-1;
            }
            else ans[i] = i+1;
        }
        for(int i = 1; i<n+1;i++){
        cout<<ans[i]<<" ";
        }
    }
    
    return 0;
}