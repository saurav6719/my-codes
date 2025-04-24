/**
 *    author: Saurav
 *    created: 2024.10.28 20:02:38
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

bool poss(int mid , vector<int> &input){
    int n = input.size();

    if(n % 2 == 0){
        for(int i = 1; i<n; i+=2){
            if(input[i] - input[i-1] > mid){
                return false ;
            }
        }
        return true ;
    }
    
    for(int i = 0; i<n; i++){
        // leaving this index
        vector<int> v;
        bool ok = true;
        for(int j = 0; j<n; j++){
            if(i == j) continue ;
            v.push_back(input[j]);
        }
        for(int j = 1; j<v.size(); j+=2){
            if(v[j] - v[j-1] > mid){
                ok = false;
                break ;
            }
        }
        if(ok) return true ;
    }
    return false ;
    
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(auto &x : input){
        cin>>x;
    }

    sort(input.begin(),input.end());

    int lo = 1;
    int hi = 1e18;
    int res = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/ 2;

        if(poss(mid,input)){
            res = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

