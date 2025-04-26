/**
 *    author: Saurav
 *    created: 2025.04.26 20:26:35
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
int processResult(int N, const vector<int>& maleHeights, const vector<int>& femaleHeights) {
    multiset<int> malepositive;
    multiset<int> malenegative;
    multiset<int> femalepositive;
    multiset<int> femalenegative;

    for(auto ele: maleHeights){
        if(ele>0){
            malepositive.insert(ele);
        }
        else{
            malenegative.insert(abs(ele));
        }
    }
    for(auto ele: femaleHeights){
        if(ele>0){
            femalepositive.insert(ele);
        }
        else{
            femalenegative.insert(abs(ele));
        }
    }

    int ans =0 ;


    for(int i = 0; i<maleHeights.size(); i++){
        int curr = maleHeights[i];
        if(curr > 0){
            // inko apne se bada chahiye female negative me 
            auto it = femalenegative.upper_bound(curr);
            if(it != femalenegative.end()){
                ans++;
                femalenegative.erase(it);
            }
        }
        else{
            // inko apne se chhota chahiye female positive me 
            auto it = femalepositive.lower_bound(abs(curr));
            if(it != femalepositive.begin()){
                it--;
                ans++;
                femalepositive.erase(it);
            }
        }
    }

    return ans;
}
    
void solve(){
    int N;
    cin>>N;
    vector<int> maleHeights(N);
    vector<int> femaleHeights(N);
    for(int i=0;i<N;i++){
        cin>>maleHeights[i];
    }
    for(int i=0;i<N;i++){
        cin>>femaleHeights[i];
    }

    cout<<processResult(N, maleHeights, femaleHeights)<<endl;
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

