#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ans;
        if(n==m)  ans = n;
        else {
            int mn = min(n,m);
            int mx = max(n,m);
            ans = mn;
            ans+= mx - mn;
        }

        cout<<ans<<endl;
    
    }
    
    return 0;
}