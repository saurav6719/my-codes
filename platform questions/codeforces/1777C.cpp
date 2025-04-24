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
void oslve(){
     int n,m;
    cin>>n>>m;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    cout<<"..";

    cout<<m<<"..";
    for(auto ele : input){
        cout<<ele<<"..";
    }
    cout<<endl;
}
vector<int> divisors(int n){
    vector<int> x;
    for(int i = 1; i*i<=n; i++){
        if(n%i == 0){
            x.push_back(i);
            x.push_back(n/i);
            if(i*i == n) x.pop_back();
        }
    }
    sort(x.begin(), x.end());
    return x;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    vector<int> frequency(m+1, 0);
    int cnt = 0;
    int j = 0;
    int ans = INT_MAX;

    for(int i = 0; i<n; i++){
        for(auto ele : divisors(input[i])){
            if(ele>m) break;
            if(frequency[ele] == 0) {
                cnt++;
                
            }
            frequency[ele]++;
        }

        while(cnt == m){
            int currans = input[i] - input[j];
            ans = min(ans, currans);
            for(auto ele : divisors(input[j])){
                if(ele>m) break;
                frequency[ele]--;
                if(frequency[ele] == 0){
                    cnt--;
                }
            }
            debug(i);
            debug(j);
            debug(cnt);
            j++;
        }
    }
    if(ans > 1e9) ans = -1;
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
    for(int i = 1; i<=t; i++){
        solve();
    }
return 0;
}

