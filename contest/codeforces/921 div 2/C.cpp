#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    string str;
    cin>>str;
    vector<vector<int> > index(26);

    for(int i = 0; i<str.size();i++){
        char ch = str[i];
        int ascc = int32_t(ch);
        index[ascc - 97].push_back(i);
    }

    for(int i = 0; i<k; i++){
        // if(index[i].size()==0){
        //     cout<<"NO"<<endl;
        //     cout<<char(i+97)<<endl;
        //     return;
        // }
        if(index[i].size() <=i){
            string ans = "";
            for(int l = 0 ; l<=i;l++){
                ans += char(i+97);
            }
            cout<<"NO"<<endl;
            cout<<ans<<endl;
            return;
        }
        int lastOcc = index[i][index[i].size() - 1];
        for(int j = 0; j<k; j++){
            if(j==i) continue;
            int number = 0;
            for(int x = 0; x<index[j].size();x++){
                if(index[j][x] > lastOcc)number++;   
                debug(number);             
            }
            if(number < k-1){
                debug(k-1);
                string ans = "";
                ans += char(i+97);
                
                for(int l = 0;l<(k-1); l++){
                    debug(l);
                    debug(k-1);
                    ans+= char(j+97);
                    
                }
                cout<<"NO"<<endl;
                cout<<ans<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}