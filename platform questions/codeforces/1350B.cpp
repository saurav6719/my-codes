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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

std::vector<int> findFactors(int n) {
    std::vector<int> factors;
    
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) { // If not a perfect square, add the other factor
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int > > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first;
        input[i].second = i+1;
    }
    sort(input.begin(), input.end());

    // for(int i = 0; i<n ; i++){
    //     cout<<input[i].first<<" "<<input[i].second<<endl;
    // }

    vector<int> values;
    values.push_back(input[0].first);
    for(int i = 1; i<n; i++){
        if(input[i].first == input[i-1].first) continue;
        values.push_back(input[i].first);
    }

    vector<vector<int> > indexes(values.size());
    indexes[0].push_back(input[0].second);
    int curr =0;
    for(int i = 1; i<n; i++){
        if(input[i].first == input[i-1].first){
            indexes[curr].push_back(input[i].second);
            continue;
        }
        curr++;
        indexes[curr].push_back(input[i].second);
    }
    // print(values);
    // for(int i = 0; i<values.size(); i++){
    //     for(int j = 0; j<indexes[i].size(); j++){
    //         cout<<indexes[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }

    vector<int> ans(n+5,0);

    for(int i = 0; i<values.size(); i++){
        set<int> st;
        for(int j = 0; j<indexes[i].size(); j++){
            st.insert(indexes[i][j]);
        }
        //debug(st.size());
        for(int j = 0; j<indexes[i].size(); j++){
            int curidx = indexes[i][j];
            vector<int> factors = findFactors(curidx);
            //debug(factors.size());
            int cnt = 0;
            for(int k = 0; k<factors.size(); k++){
                if(st.count(factors[k])) continue;
                cnt = max(cnt, ans[factors[k]]);
                //if(factors[k] == 3) debug(ans[factors[k]]);
            }
            ans[curidx] = cnt+1;
            // debug(curidx);
            // debug(ans[curidx]);
        }
    }

    //print(ans);

    int res = INT_MIN;
    for(int i = 0; i<n+5; i++){
        res = max(res, ans[i]);
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

