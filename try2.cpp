
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

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first > b.first;
}
void solve(){

    vector<int> a;
    int n ;
    cin>>n;
    a.resize(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }

    stack<pair<int,int> > st;

    stack<pair<int,int> > st2;


    vector<int> next(n);
    vector<int> prev(n);

    

    for(int i = 0; i<n; i++){
        int curr = a[i];
        if(st.empty()){
            st.push({a[i] , 1});
            prev[i] = 1;
            continue;
        }
        int cnt = 1;
        while(!st.empty() and st.top().first >= curr){
            cnt += st.top().second;
            st.pop();
        }
        st.push({curr, cnt});
        prev[i] = cnt;
    }

 

    for(int i = n-1; i>=0; i--){
        int curr = a[i];
        if(st2.empty()){
            st2.push({a[i] , 1});
            next[i] = 1;
            continue;
        }
        int cnt = 1;
        while(!st2.empty() and st2.top().first >= curr){
            cnt += st2.top().second;
            st2.pop();
        }
        st2.push({curr, cnt});
        next[i] = cnt;
    }

    print(prev);
    print(next);
    
    map<int, int> st3;

    vector<pair<int,int> > input;

    for(int i = 0; i<n; i++){
        input.push_back({a[i], i});
    }

    sort(input.begin(), input.end(), cmp);
    int curr = 1;
    for(int i = 0; i<n; i++){
        int aa = input[i].first;
        int bb = input[i].second;
        int xx = prev[bb] + next[bb] - 1;

        if(st3.count(xx)){
            continue;
        }

        while(curr <= xx){
            st3[curr] = aa;
            curr++;
        }
    }

    vector<int> final(n+1);
    for(auto ele: st3){
        final[ele.first] = ele.second;
    }

    print(final);


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

