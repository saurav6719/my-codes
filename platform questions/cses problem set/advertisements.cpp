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
void solve(){
    int n;
    cin>>n;
    vector<int> input(n+1);
    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }

    vector<int> prevsmaller(n+1);
    vector<int> nextsmaller(n+1);

    prevsmaller[1] = 0;
    stack<pp> st;
    st.push({input[1], 1});

    for(int i = 2; i<=n; i++){
        while(!st.empty() and st.top().first >= input[i]) st.pop();
        if(st.empty()){
            prevsmaller[i] = 0;
        }
        else prevsmaller[i] = st.top().second;

        st.push({input[i], i});
    }

    print(prevsmaller);

    nextsmaller[n] = n+1;
    stack<pp> st2;
    st2.push({input[n], n});

    for(int i = n-1; i>=1; i--){
        while(!st2.empty() and st2.top().first >= input[i]) st2.pop();
        if(st2.empty()){
            nextsmaller[i] = n+1;
        }
        else nextsmaller[i] = st2.top().second;

        st2.push({input[i], i});
    }

    print(nextsmaller);

    int ans = 0;

    for(int i = 1; i<=n; i++){
        int left = i-prevsmaller[i]-1;
        int right = nextsmaller[i]-i-1;
        debug(i);
        debug(left);    
        debug(right);

        int curr = (left + right +1 ) * input[i];

        ans = max(ans, curr);

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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

