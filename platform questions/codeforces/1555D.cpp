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
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;

    string s1 = "abc";
    string s2 = "acb";
    string s3 = "bac";
    string s4 = "bca";
    string s5 = "cab";
    string s6 = "cba";


    while(s1.size() < n){
        s1 += s1;
        s2 += s2;
        s3 += s3;
        s4 += s4;
        s5 += s5;
        s6 += s6;
    }

    vector<int> v1(n, 0);
    vector<int> v2(n, 0);
    vector<int> v3(n, 0);
    vector<int> v4(n, 0);
    vector<int> v5(n, 0);
    vector<int> v6(n, 0);

    v1[0]= (str[0] == s1[0] ? 0 : 1);
    for(int i = 1; i<n; i++){
        if(str[i] == s1[i]){
            v1[i] = v1[i-1];
        }
        else{
            v1[i] = 1+v1[i-1];
        }
    }

    v2[0]= (str[0] == s2[0] ? 0 : 1);
    for(int i = 1; i<n; i++){
        if(str[i] == s2[i]){
            v2[i] = v2[i-1];
        }
        else{
            v2[i] = 1+v2[i-1];
        }
    }

    v3[0]= (str[0] == s3[0] ? 0 : 1);
    for(int i = 1; i<n; i++){
        if(str[i] == s3[i]){
            v3[i] = v3[i-1];
        }
        else{
            v3[i] = 1+v3[i-1];
        }
    }

    v4[0]= (str[0] == s4[0] ? 0 : 1);
    for(int i = 1; i<n; i++){
        if(str[i] == s4[i]){
            v4[i] = v4[i-1];
        }
        else{
            v4[i] = 1+v4[i-1];
        }
    }

    v5[0]= (str[0] == s5[0] ? 0 : 1);
    for(int i = 1; i<n; i++){
        if(str[i] == s5[i]){
            v5[i] = v5[i-1];
        }
        else{
            v5[i] = 1+v5[i-1];
        }
    }

    v6[0]= (str[0] == s6[0] ? 0 : 1);
    for(int i = 1; i<n; i++){
        if(str[i] == s6[i]){
            v6[i] = v6[i-1];
        }
        else{
            v6[i] = 1+v6[i-1];
        }
    }


    while(m--){
        int l;
        int r;
        cin>>l>>r;
        l--;
        r--;
        int ans = INT_MAX;
        if(l == 0){
            ans = min(ans, v1[r]);
            ans = min(ans, v2[r]);
            ans = min(ans, v3[r]);
            ans = min(ans, v4[r]);
            ans = min(ans, v5[r]);
            ans = min(ans, v6[r]);

            cout<<ans<<endl;
            continue;
        }


            ans = min(ans, v1[r] - v1[l-1]);
            ans = min(ans, v2[r] - v2[l-1]);
            ans = min(ans, v3[r] - v3[l-1]);
            ans = min(ans, v4[r] - v4[l-1]);
            ans = min(ans, v5[r] - v5[l-1]);
            ans = min(ans, v6[r] - v6[l-1]);

            cout<<ans<<endl;
            continue;
        
    }



}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

