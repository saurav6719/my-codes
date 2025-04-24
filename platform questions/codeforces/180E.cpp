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

bool poss(int mid, vector<vector<int> > &coloursindex, int k){
    // return true;
    for(int l = 1; l<coloursindex.size(); l++){
        int cnt =0 ;
        int currskip = 0;
        int i= 0;
        int j= 0;

        

        debug(l);

        while(j<coloursindex[l].size() and i<coloursindex[l].size()){
            while(j+1 < coloursindex[l].size() and currskip + coloursindex[l][j+1] - coloursindex[l][j] -1 <= k){
                j++;
                if(j>=coloursindex[l].size()) break;
                currskip += coloursindex[l][j] - coloursindex[l][j-1] -1;
                // cnt2++;
            }
            // cnt2++;

            cnt = max(cnt , j-i+1);
            i++;
            if(i>=coloursindex[l].size()) break;
            currskip -= coloursindex[l][i] - coloursindex[l][i-1] -1;
        }

        if(cnt >= mid){
            return true;
        }
    }
    return false;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> input(n+1);
    for(int i=1;i<=n;i++){
        cin>>input[i];
    }

    vector<vector<int> > coloursindex(m+1, vector<int> ());
    for(int i=1;i<=n;i++){
        coloursindex[input[i]].push_back(i);
    }

    print2d(coloursindex);

    int lo = 0;
    int hi = n;

    int res = -1;
    while(lo <= hi){

        int mid = lo + (hi-lo)/2;

        if(poss(mid, coloursindex, k)){
            res = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
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

