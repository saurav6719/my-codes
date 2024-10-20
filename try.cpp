/**
 *    author: Saurav
 *    created: 2024.10.20 15:06:56
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
struct pair_hash {
    size_t operator()(const pp& p) const {
        // A common way to combine hashes of two integers
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
void solve(){
    int n;
    cin>>n;
    multiset<int> ms;
    unordered_map<int, vector<pp> > mp;
    unordered_set<int> reaminingindex;
    unordered_map<pp,int, pair_hash> stl;

    for(int i = 0; i<n; i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back({b,i}) ;
        mp[b].push_back({a,i}) ;
        stl[{a,b}]++;
        ms.insert(a) ;
        ms.insert(b) ;
        reaminingindex.insert(i) ;
    }

    for(auto ele : mp){
        debug(ele.first);
        for(auto x : ele.second){
            debug(x.first);
            debug(x.second);
        }
    }

    for(auto & ele : mp){
        sort(ele.second.begin(),ele.second.end()) ;
    }

    vector<int> ans;
    while(reaminingindex.size() > 0){
        int mini = *ms.begin() ;
        debug(mini);
        // ms.erase(ms.begin()) ;
        for(auto ele : mp[mini]){
            int idx = ele.second ;
            debug(ele.first);
            debug(idx);
            if(reaminingindex.count(idx)){

                if(stl.count({mini, ele.first})){
                    // cout<<"YEE"<<endl;
                    ans.push_back(mini);
                    ans.push_back(ele.first) ;
                    ms.erase(ms.find(mini)) ;
                    ms.erase(ms.find(ele.first)) ;

                    stl[{mini,ele.first}]-- ;
                    if(stl[{mini,ele.first}] == 0){
                        stl.erase(stl.find({mini,ele.first})) ;
                        
                    }
                }

                if(stl.count({ele.first, mini})){
                    // cout<<"YEA"<<endl;
                    ans.push_back(ele.first);
                    ans.push_back(mini) ;
                    ms.erase(ms.find(mini)) ;
                    ms.erase(ms.find(ele.first)) ;
                    stl[{ele.first,mini}]-- ;
                    if(stl[{ele.first,mini}] == 0){
                        stl.erase(stl.find({ele.first,mini})) ;
                        
                    }
                }
                
                reaminingindex.erase(idx) ;

            }

        }
        
    }
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;


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

