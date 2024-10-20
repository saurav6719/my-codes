/**
 *    author: Saurav
 *    created: 2024.10.20 21:11:49
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
        if(l > r){
            return false;
        }
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

    int n = str.size();

    int ans = 0;

    manachar m;

    m.build(str);

    string final ="";

    // case 1 start se kuch nhi liya 

    for(int i = 0; i<n; i++){
        if(m.check(i, n-1)){
            ans = n - i;
            final = str.substr(i);
            break ;
        }
    }

    debug(ans);

    // case 2 end se kuch nhi liya

    for(int i = n-1; i>=0; i--){
        if(m.check(0, i)){
            if(i+1 > ans){
                ans = i+1;
                final = str.substr(0, i+1);
            }
        }
    }

    // case 3 start se kuch liya end se kuch liya

    int start1 = -1;
    int end1 = -1000000000;
    int start2 = -1;
    int end2 = -1000000000;
    

    string str2 = str;
    reverse(str2.begin(), str2.end());

    int idx = -1;

    for(int i = 0; i<n; i++){
        if(str[i] != str2[i]){
            idx = i-1;
            break ;
        }
    }

    if((idx+1) * 2 > ans){
        ans = (idx+1) * 2;
        final = str.substr(0, idx+1) + str.substr(n-idx-1);
    }

    debug(idx);

    if(idx != -1){
        for(int i = idx+1; i< n-idx-1; i++){
            if(m.check(idx+1, i)){
                start1 = idx+1;
                end1 = i;
            }
        }

        int len = (idx+1) * 2 + (end1 - start1 + 1);
        if(len > ans){
            ans = len;
            final = str.substr(0, idx+1) + str.substr(start1, end1-start1+1) + str.substr(n-idx-1);
        }

        print(final);
        

        for(int i = n-idx-3; i>=idx+1; i--){
            if(m.check(i, n-idx-2)){
                start2 = i;
                end2 = n-idx-2;
            }
        }

        int len2= (idx+1) * 2 + (end2 - start2 + 1);

        if(len2 > ans){
            ans = len2;
            final = str.substr(0, idx+1) + str.substr(start2, end2-start2+1) + str.substr(n-idx-1);
        }
        print(final);
    }

    cout<<final<<endl;
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

