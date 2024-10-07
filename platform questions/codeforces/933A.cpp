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

int lis(vector<int> &arr , int start, int end){
    if(end < start) return 0;

    vector<int> v;
    for(int i = start; i<=end; i++){
        if(v.empty()){
            v.push_back(arr[i]);
            continue;
        }
        if(arr[i] >= v.back()){
            v.push_back(arr[i]);
            continue;
        }
        int xx = lower_bound(v.begin(), v.end() , arr[i]) - v.begin();
        v[xx] = arr[i];
    }

    return v.size();
}

int lds(vector<int> &arr, int start, int end){
    if(end < start) return 0;
    vector<int> reversed_arr(arr.begin() + start, arr.begin() + end + 1);
    reverse(reversed_arr.begin(), reversed_arr.end());

    vector<int> v;
    for(auto num : reversed_arr){
        if(v.empty() || num >= v.back()){
            v.push_back(num);
        }
        else{
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
        }
    }
    return v.size();
}

void solve(){
    int n;
    cin>>n;
    vector<int> input(n+1);
    for(int i =0; i<n; i++){
        cin>>input[i];
    }

    int ans=0;

    for(int i = 0; i<=n; i++){
        //partition at i

        int ans1 =0 ;
        int sum = 0;
        for(int j = 0; j<i-1; j++){
            if(input[j] == 1) sum++;
        }
        ans1 = max(ans1, sum);

        for(int j= i-1; j>=0; j--){
            if(input[j] == 2) sum++;
            else sum--;

            ans1 = max(ans1, sum);
        }

        sum = 0;
        int ans2 =0 ;

        for(int j = i; j<n; j++){
            if(input[j] == 1) sum++;
        }
        ans2 = max(ans2, sum);

        for(int j = n-1; j>=i; j--){
            if(input[j] == 2) sum++;
            else sum--;
            ans2 = max(ans2, sum);
        }
        debug(i);
        debug(ans1);
        debug(ans2);

        ans = max(ans , ans1+ans2);
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

