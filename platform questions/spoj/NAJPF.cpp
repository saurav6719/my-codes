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

void rabin_karp(string &text, string &pattern ,vector<int> &result){
    int n = text.size(); 
    int m = pattern.size();
    vector<int> powers(max(n,m)+5);
    int p = 31;
    int md = 1e9+9;
    powers[0] = 1;
    for(int i = 1; i<powers.size(); i++){
        powers[i] = (powers[i-1] * p ) % md;
    }

    vector<int> hash_of_text(n+1 ,0);

    for(int i = 0; i<n; i++){
        hash_of_text[i+1] = hash_of_text[i] +((text[i] - 'a' + 1) * powers[i] )%md;
    }

    int pattern_hash = 0;
    for(int i = 0; i<m; i++){
        pattern_hash = (pattern_hash + (pattern[i] - 'a' +1) * powers[i]) %m;
    }


    for(int i = 0; i + m - 1 < n ; i++){
        int text_hash = (hash_of_text[i+m] + md - hash_of_text[i]) % md;
        pattern_hash = (pattern_hash * powers[i]);
        pattern_hash %= md;

        if(text_hash == pattern_hash){
            result.push_back(i); 
        }
    }
}

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}



void solve(){
    string text;
    cin>>text;
    string pattern;
    cin>>pattern;

    vector<int> result = rabin_karp(pattern , text);
    // cout<<result.size()<<endl;

    if(result.empty()){
        cout<<"Not Found"<<endl;
        return;
    }

    cout<<result.size()<<endl;
    for(auto ele : result){
        cout<<ele+1<<" ";
    }
    cout<<endl;

    // rabin_karp(text, pattern, result);

    // print(result);


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

