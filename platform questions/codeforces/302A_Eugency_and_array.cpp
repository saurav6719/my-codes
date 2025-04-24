#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define ll long long int
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int pluscount = 0;
    int miniuscount = 0;
    for(int i = 0; i<n;i++){
        if(input[i] == 1) pluscount++;
        else miniuscount++;
    }
    
    while(m--){
        int l;
        int r;
        cin>>l;
        cin>>r;
        int range = r-l+1;
        if(range % 2 != 0) cout<<"0"<<endl;
        else{
            int require = range / 2;
            if(pluscount >= require and miniuscount>=require) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
}
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}