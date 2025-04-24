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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string str;
    cin>>str;
    string str1= "";
    string str2 ="";
    string str3 = "";


    string ss1 = "RGB";
    string ss2 = "GBR";
    string ss3 = "BRG";

    while(str1.size() < k){
        str1 += ss1;
    }

    while(str1.size() > k){
        str1.pop_back();
    }


    while(str2.size() < k){
        str2 += ss2;
    }

    while(str2.size() > k){
        str2.pop_back();
    }


    while(str3.size() < k){
        str3 += ss3;
    }

    while(str3.size() > k){
        str3.pop_back();
    }

    print(str1);
    print(str2);
    print(str3);


    int ans = INT_MAX;

    vector<vector<int> > dp(n+5, vector<int> (3, 0));


    int i1 = 0; 
    int j1 = k;
    int cnt1 = 0;


    for(int a= 0; a<j1; a++){
        if(str[a] != str1[a]){
            cnt1++;
        }
    }

    dp[0][0] = cnt1;


    int i2 = 0; 
    int j2 = k;
    int cnt2 = 0;


    for(int a= 0; a<j2; a++){
        if(str[a] != str2[a]){
            cnt2++;
        }
    }

    dp[0][1] = cnt2;

    int i3 = 0; 
    int j3 = k;
    int cnt3 = 0;


    for(int a= 0; a<j3; a++){
        if(str[a] != str3[a]){
            cnt3++;
        }
    }

    dp[0][2] = cnt3;


    for(int i = 1; i<=n-k; i++){
        for(int j = 0; j<3; j++){
            if(j==0){
                int changes = dp[i-1][2];
                if(str[i-1] != 'B'){
                    changes--;
                }
                if(str[i+k-1] != str1.back()){
                    changes++;
                }
                dp[i][j] = changes;
            }

            if(j==1){
                int changes = dp[i-1][0];
                if(str[i-1] != 'R'){
                    changes--;
                }
                if(str[i+k-1] != str2.back()){
                    changes++;
                }
                dp[i][j] = changes;
            }

            if(j==2){
                int changes = dp[i-1][1];
                if(str[i-1] != 'G'){
                    changes--;
                }
                if(str[i+k-1] != str3.back()){
                    changes++;
                }
                dp[i][j] = changes;
            }
        }
    }

    print(dp[0]);
    print(dp[1]);
    print(dp[2]);

 
    for(int i = 0; i<=n-k; i++){
        for(int j = 0; j<3; j++){
            ans = min(ans , dp[i][j]);
        }
    }

    cout<<ans<<endl;






    
    


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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

