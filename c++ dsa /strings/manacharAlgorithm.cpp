/**
 *    author: Saurav
 *    created: 2024.10.20 18:37:52
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
class manachar{
    public: 
    vector<int> p;
    void run(string s){
        int n = s.size();
        p.assign(n, 1);
        int l = 1;
        int r = 1;

        for(int i = 1; i<n; i++){
            p[i] = max(0ll, min(r-i, p[l+r-i]));
            while(i-p[i] >= 0 && i+p[i] < n && s[i-p[i]] == s[i+p[i]]){
                p[i]++;
            }
            if(i+p[i] > r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }

    void build(string s){
        string t;
        for(auto v:s){
            t += string("#") + v;
        }
        t += "#";
        run(t);
    }

    int getlongestAtaCenter(int center , bool odd){
        int posinp = 2*center + 1 + (!odd);
        return p[posinp] - 1;
    }

    bool check (int l , int r){
        int center = (l+r)/2;
        bool odd = true;
        if(r%2 != l%2){
            odd = false;
        }
        int longest = getlongestAtaCenter(center, odd);

        return longest >= (r - l + 1);
    }

};
void solve(){
    string str;
    cin>>str;

    int idx = -1;
    int ans = 0;
    int n = str.size();
    manachar m;
    m.build(str);
    for(int i = 0; i<n; i++){
        //centre at i 
        int longest1 = m.getlongestAtaCenter(i, true);

        if(longest1 > ans){
            ans = longest1;
            idx = i;
        }

        int longest2 = m.getlongestAtaCenter(i, false);
        if(longest2 > ans){
            ans = longest2;
            idx = i;
        }
    }

    string res = "";
    if(ans & 1){
        for(int i = idx - (ans/2); i<=idx + (ans/2); i++){
            res += str[i];
        }
    }
    else{
        for(int i = idx - (ans/2)+1; i<=idx + (ans/2); i++){
            res += str[i];
        }
    }

    cout<<res<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

