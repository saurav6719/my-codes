/**
 *    author: Saurav
 *    created: 2025.07.02 21:25:14
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#define printpp(v)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
bool cmp(pp & a, pp & b){
    if(a.first > b.first){
        return true;
    }
    if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
        return false;
    }
    return false;
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i =0 ; i<n; i++){
        cin>>v[i];
    }
    string str;
    cin>>str;

    if(str.back() == '1'){
        string newstr = "";
        for(auto ele : str){
            if(ele == '0') newstr += '1';
            else newstr += '0';
        }
        reverse(v.begin(), v.end());
        str = newstr;
    }
    int last = 1;
    for(int i = k-2; i>=0; i--){
        if(str[i] == str[i+1]){
            last++;
        }
        else break;
    }
    if(last == k){
        int start = last;
        multiset<int> ms;
        int currsum = 0;
        for(int i = 0; i<start; i++){
            ms.insert(v[i]);
            currsum += v[i];
            currsum %= MOD;
        }
        int ans = 0 ;
        for(int i = start; i<n; i++){
            // leaving this i 
            ans = max(ans, currsum);
            int smallest = *ms.begin();
            if(smallest < v[i]){
                ms.erase(ms.find(smallest));
                currsum -= smallest;
                currsum += v[i];
                while(currsum < 0){
                    currsum += MOD;
                }
                if(currsum >= MOD){
                    currsum %= MOD;
                }
                ms.insert(v[i]);
            }
        }

        cout<<ans<<endl;
        return;
    }

    

    vector<pp> v2(n);
    for(int i = 0; i<n; i++){
        v2[i] = {v[i], i};
    }

    sort(v2.begin(), v2.end(), cmp);
    vector<int> indexes;
    for(int i = 0; i<k; i++){
        indexes.push_back(v2[i].second);
    }
    sort(indexes.begin(), indexes.end());
    set<int> indexesset;
    for(auto ele : indexes){
        indexesset.insert(ele);
    }
    int start = indexes[last-1]+1;
    for(int i = start; i<n; i++){
        if(indexesset.count(i) == 0){
            int ans = 0;
            for(auto ele : indexesset){
                ans += v[ele];
                ans %= MOD;
            }
            cout<<ans<<endl;
            return;
        }
    }

    // ab indexes se koi ek hatana pdega 
    int ans = 0;
    for(auto ele : indexes){
        ans += v[ele];
        ans %= MOD;
    }
    int maxnottaken = 0;
    int i = 0;
    int sum = ans;
    ans = 0;
    for(auto ele : indexes){
        while(i < ele){
            if(indexesset.count(i) == 0){
                maxnottaken = max(maxnottaken, v[i]);  
            }
            i++;
        }
        if(ele < last) continue;
        int currans = sum;
        currans += maxnottaken;
        currans -= v[ele];
        while(currans < 0){
            currans += MOD;
        }
        if(currans >= MOD){
            currans %= MOD;
        }
        ans = max(ans, currans);
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

