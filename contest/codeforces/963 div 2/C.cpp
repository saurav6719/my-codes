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
int largestNumberSmallerThanOrEqualToY(int x, int y, int cd) {
    // Calculate the maximum number of times cd can be added to x without exceeding y
    int maxIncrements = (y - x) / cd;

    // Calculate the result by adding cd maxIncrements times to x
    int result = x + maxIncrements * cd;

    return result;
}

bool f(int l1, int r1, int l2, int r2){
    return max(l1, l2) <= min(r1, r2);
}
void solve(){
    int n;
    cin>>n;
    int k; cin>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end());

    int y = input.back();

    vector<pp> v;

    for(int i = 0; i<n; i++){
        input[i] = largestNumberSmallerThanOrEqualToY(input[i], y, 2*k);
        v.push_back({input[i] , input[i] + 2*k});
    }

    print(input);


    // for(int i = 0; i<n; i++){
    //     cout<<v[i].first<<" "<< v[i].second<<endl;
    // }


    int l1 = v[0].first;
    int r1 = v[0].first + k - 1;

    int xx = v[0].first;
    int yy =v[0].second;
    if(abs(yy- y) < abs(xx-y)){
        l1 = v[0].second;
        r1 = v[0].second + k -1;
    }

    for(int i = 1; i<n; i++){
        int xx = v[i].first;
        int xx2 = v[i].first + k- 1;
        int yy = v[i].second;
        int yy2 = v[i].second + k -1;

        if(f(l1, r1, xx, xx2)){
            l1 = max(l1, xx);
            r1 = min(r1, xx2);
        }
        else{
            l1 = max(l1, yy);
            r1 = min(r1, yy2);
        }
    }

    if(l1<=r1){
        cout<<l1<<endl;
        return;
    }

    cout<<-1<<endl;
    return;




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
    // t = /1;
    while(t--){
        solve();
    }
return 0;
}

