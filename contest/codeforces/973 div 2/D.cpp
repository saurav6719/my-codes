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

bool poss(int mid, vector<int> &input_copy){

    debug(mid);
    
    int n = input_copy.size();
    vector<int> input = input_copy;

    int rangel = input[0];
    int ranger = input[0] + mid;

    debug(rangel);
    debug(ranger);
    int curr = 0;
    for(int i = 0;i<n; i++){
        if(input[i] < rangel){
            curr += rangel-input[i];
            input[i] = rangel;
        }
        else if(input[i] > ranger){
            curr -= input[i] - ranger;
            input[i] = ranger;
        }
    }

    debug(curr);

    int req = -curr;

    debug(req);


    if(req == 0) return true;
    if(req < 0){
        if(mid >= 1) return true;
        if(mid == 0 and (abs(req) % n) == 0) return true;
        return false;
    }

    else{
        if(mid == 2) print(input);
        for(int i = 2; i<n; i++){
            int xx = input[i];
            if(xx < ranger){
                debug(xx);
                req -= min(ranger - xx , req);
            }
            if(req == 0) return true;
        }
    }



    return false;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int lo = 0;
    int hi = 1e15;
    int res = -1;
    while(lo <= hi){
        int mid = (lo + (hi - lo )/ 2);

        if(poss(mid, input)){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    // debug(poss(4, input));


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

