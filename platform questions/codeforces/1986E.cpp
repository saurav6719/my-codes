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
vector<int> merge(vector<int> &v1, vector<int> &v2){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> v;
    int i = 0; int j =0;
    while(i<v1.size() and j<v2.size()){
        if(v1[i] <= v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j]);
            j++;
        }
    }

    while(i<v1.size()){
        v.push_back(v1[i]);
        i++;
    }

    while(j<v2.size()){
        v.push_back(v2[j]);
        j++;
    }

    return v;

}

bool cmp(pp &a, pp&b){
    return a.first > b.first;
}

int f(vector<int> &arr){
    if(arr.size() == 0) return 0;
    int n = arr.size();
    vector<vector<int> > dp(n+5, vector<int> (2, 0));

    dp[n-1][0] = arr[n-1];
    dp[n-1][1] = arr[n-1];

    dp[n-2][0] = arr[n-2];
    dp[n-2][1] = arr[n-2];

    for(int i = n-3; i>=0; i--){
        dp[i][0] = arr[i] + min(dp[i+2][0] , dp[i+3][1]);
        dp[i][1] = arr[i] + dp[i+2][1];
    }

    // for(int i =0; i<n; i++){
    //     cout<<dp[i][0]<<" ";
    // }

    // cout<<endl;


    // for(int i =0; i<n; i++){
    //     cout<<dp[i][1]<<" ";
    // }

    // cout<<endl;


    return min(min(dp[0][0], dp[0][1]), ( dp[1][1]));

}
void solve(){
    int n;
    cin>>n;
    int k;cin>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    if(n == 1){
        cout<<0<<endl;
        return;
    }

    set<int> st;

    for(int i = 0; i<n; i++){
        if(st.count(input[i])){
            st.erase(input[i]);
        }

        else st.insert(input[i]);
    }

    vector<int> unique;
    for(auto ele : st){
        unique.push_back(ele);
    }

    print(unique);

    if(unique.size() == 0){
        cout<<0<<endl;
        return;
    }

    map<int,vector<int> >mp;

    debug(k);

    for(int i = 0; i<unique.size(); i++){
        mp[(unique[i] % k)].push_back(unique[i]);
    }

    int ans = 0;

    bool oneodd = false;


    set<int> visited;

    // for(auto ele : mp){
    //     cout<<ele.first<<"- >";
    //     for(auto ele2 : ele.second){
    //         cout<<ele2<<" ";
    //     }

    //     cout<<endl;
    // }

    vector<int> odds;
    for(auto ele : mp){
        if(ele.second.size() & 1){
            odds.push_back(ele.first);
        }
    }

    if(odds.size() > 1){
        cout<<-1<<endl;
        return;
    }


    for(auto ele : mp){
        vector<int> v = ele.second;
        sort(v.begin(), v.end());
        if(odds.size() == 1 and odds[0] == ele.first){
            vector<int> diff;
            for(int i = 1; i<v.size(); i++){
                diff.push_back((v[i] - v[i-1]));
            }

            ans += (f(diff) / k);
            debug(ans);
            continue;

        }


        int i = 0;
        int j = 1;

        while(j<v.size()){
            ans += ((v[j] - v[i]) / k);
            i+=2;
            j+=2;
        }
        debug(ans);
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

