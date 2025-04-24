/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string str;
    cin>>str;
    vector<string> v(n/k);

    for(int i = 0; i<n; i++){
        int curr = i/k;
        v[curr].push_back(str[i]);
    }

    print(v[0]);
    print(v[1]);
    //print(v[2]);
    //print(v[3]);

    string ans = "";

    vector<string> xx(k/2 + k%2);
    
    for(int i = 0; i<k/2; i++){
        for(int j = 0; j<n/k; j++){
            xx[i].push_back(v[j][i]);
            xx[i].push_back(v[j][k-1-i]);
        }
    }

    print(xx[0]);

    if(k&1){
        for(int j = 0; j<n/k; j++){
            xx[k/2+k%2-1].push_back(v[j][k/2+k%2-1]);
        }
    }

    print(xx[1]);

    

    int cnt =0;

    for(int i = 0; i<(k/2+k%2); i++){
        map<char,int> mp;

        for(auto ele : xx[i]){
            mp[ele]++;
        }

        int mxi = INT_MIN;
        char mxii;

        for(auto ele : mp){
            if(ele.second > mxi){
                mxi = ele.second;
                mxii = ele.first;
            }
        }

        cnt += xx[i].size() - mxi;
    }

    cout<<cnt<<endl;



}
/* logic ends */

signed main(){
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

