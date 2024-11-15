/**
 *    author: Saurav
 *    created: 2024.11.15 15:01:56
 **/

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
// YES
// abcaeebcabcafbggcabcabciiaklbcmmabcabpcabcabrrcttttabcabvvv

int f(string &str){
    //finding number of unique palindroms in this string

    set<string> unique_palindroms;
    int n = str.size();

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            string temp = str.substr(i,j-i+1);
            string rev = temp;
            reverse(rev.begin(),rev.end());
            if(temp == rev){
                unique_palindroms.insert(temp);
            }
        }
    }

    return unique_palindroms.size();

}
void solve(){
    string str;
    cin>>str;

    vector<int> ans(str.size()+5);

    for(int i = 3; i<=str.size(); i++){
        string temp = str.substr(0,i);
        ans[i] = f(temp);
    }

    debug(ans[37]);
    debug(ans[43]);
    debug(ans[44]);
    debug(ans[46]);
    debug(ans[47]);
    debug(ans[54]);
    debug(ans[56]);
    debug(ans[59]);
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

