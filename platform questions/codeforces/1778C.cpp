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

int f2(string & stroriginal, set<char> tochange, string & to_make){
    int n = stroriginal.size();

    int last = -1;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(stroriginal[i] == to_make[i]) continue;
        if(tochange.count(stroriginal[i])) continue;

        int curr = i-last-1;

        last = i;
        ans += (curr * (curr+1)) / 2;
    }

    if(last != n-1){
        int curr = n-last-1;

        last = n-1;
        ans += (curr * (curr+1)) / 2;
    }

    return ans;
}

void f(vector<string> &v, string str, string &s1, int k, int n, int i){
    
    if(k==0){
        v.push_back(str);
        return;
    }

    if(i==s1.size()){
        return;
    }

    for(int j = i; j<s1.size(); j++){
        str += s1[j];
        f(v, str, s1, k-1, n, j+1);
        str.pop_back();
    }

}

void solve(){
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    string b;
    cin>>b;

    set<char> st1;
    for(auto ele : a){
        st1.insert(ele);
    }

    int n2 = st1.size();
    debug(n2);
    k = min(k , n2);

    vector<string> v;
    string s1 = "";
    for(auto ele : st1){
        s1 += ele;
    }

    print(s1);
    f(v,"", s1, k, n, 0);
    // int cnt = 0;
    // for(auto ele : v){
    //     cout<<ele<<endl;
    //     cnt++;
    // }
    // debug(cnt);

    int ans   =INT_MIN;

    for(auto ele : v){
        set<char> ss;
        for(auto ele2 : ele){
            ss.insert(ele2);
        }

        ans = max(ans, f2(a, ss, b));
        debug(f2(a, ss, b));
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

