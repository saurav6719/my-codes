/**
 *    author: Saurav
 *    created: 2025.07.03 23:28:34
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
#define printpp(v)
#define printset(s)
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
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> v;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.push_back(1e9+1);
    set<int> curr;
    for(auto ele : v){
        curr.insert(ele);
    }
    sort(v.begin(), v.end());
    map<int,int> mp;
    for(int i = 1; i<v.size()-1; i++){
        int x = v[i];
        int next = upper_bound(v.begin(), v.end(), x) - v.begin();
        if(v[next] == 1e9+1){
            mp[x] = 1e9+1;
        }
        else{
            mp[x] = x + (1e9+1 - v[next]);
        }
    }
    printmap(mp);
    multiset<int> ms;
    for(auto ele : mp){
        ms.insert(ele.second);
    }
    {
        auto mini = curr.begin();
        mini++;
        int mini_val = *mini;
        auto maxi = curr.rbegin();
        maxi++;
        int maxi_val = *maxi;
        debug(mini_val);
        debug(maxi_val);
        int tosub = 1e9+1 - maxi_val + mini_val;
        debug(tosub);
        debug(mini_val);
        int minimumvalue = *ms.begin();
        cout<<minimumvalue - tosub<<endl;
    }
    while(q--){
        int type;
        cin>>type;
        if(type == 0){
            // hatana hai 
            int x;
            cin>>x;
            auto piche = curr.lower_bound(x);
            piche--;
            int piche_val = *piche;
            auto aage = curr.upper_bound(x);
            int aage_val = *aage;
            ms.erase(ms.find(mp[x]));
            mp.erase(x);
            curr.erase(x);

            // piche ko update kro 

            if(piche_val != 0){
                if(aage_val == 1e9+1){
                    int old = mp[piche_val];
                    int now =1e9+1;
                    ms.erase(ms.find(old));
                    ms.insert(now);

                    mp[piche_val] = now;

                }
                else{
                    int old = mp[piche_val];
                    int now = piche_val + (1e9+1 - aage_val);
                    ms.erase(ms.find(old));
                    ms.insert(now);
                    mp[piche_val] = now;
                }
            }   
        }
        else{
            // add krna hai 
            int x;
            cin>>x;
            auto piche = curr.lower_bound(x);
            piche--;
            int piche_val = *piche;
            auto aage = curr.upper_bound(x);
            int aage_val = *aage;
            curr.insert(x);
            if(piche_val != 0){
                // update piche wala 
                int old = mp[piche_val];
                ms.erase(ms.find(old));
                int now = piche_val + (1e9+1 - x);
                ms.insert(now);
                mp[piche_val] = now;

            }
            {
                // update this 
                if(aage_val == 1e9+1){
                    mp[x] = 1e9+1;
                    ms.insert(1e9+1);
                }
                else{
                    int now = x + (1e9+1 - aage_val);
                    mp[x] = now;
                    ms.insert(now);
                }
            }
            
        }
        {
            // output ans
            if(curr.size() <= 4){
                cout<<0<<endl;
            }
            else{
                auto mini = curr.begin();
                mini++;
                int mini_val = *mini;
                auto maxi = curr.rbegin();
                maxi++;
                int maxi_val = *maxi;
                debug(mini_val);
                debug(maxi_val);
                int tosub = 1e9+1 - maxi_val + mini_val;
                debug(tosub);
                debug(mini_val);
                int minimumvalue = *ms.begin();
                cout<<minimumvalue - tosub<<endl;
            }
        }
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

