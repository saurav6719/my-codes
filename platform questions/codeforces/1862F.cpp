/**
 *    author: Saurav
 *    created: 2024.10.15 22:36:40
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
// writing a bitset query code to find alll possible subsets of input array

void fun(vector<int> &input, bitset<1000001> &b){
    int n = input.size();
    b.reset();
    b[0] = 1;

    for(int i = 0; i<n; i++){
        b |= (b << input[i]); 
    }

    return;
}

bool cando (int time , int w, int f, int total, vector<int> &poss){
    int k1 = w * time;
    int k2 = f * time;

    if(k1 < k2) swap(k1,k2);

    int maxi = k1;
    int mini = total - k2;

    if(mini > maxi) return false;

    int xx = lower_bound(poss.begin(), poss.end(), mini) - poss.begin();
    if(xx == poss.size()) return false;
    int curr = poss[xx];

    if(curr <= maxi) return true;
    return false;
}
void solve(){
    int w,f;

    cin>>w>>f;
    int n;
    cin>>n;
    vector<int> input(n);

    int total = 0;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        total += input[i];
    }
    bitset<1000001> b;
    fun(input,b);

    vector<int> poss;
    for(int i = 0; i<=1000000; i++){
        if(b[i]){
            poss.push_back(i);
        }
    }

    sort(poss.begin(), poss.end());

    int lo = 0;
    int hi = 1e6;
    int res = -1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;

        if(cando(mid, w, f ,total , poss)){
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

