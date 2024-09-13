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
#define mod 11
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void enq(stack<pp> &front, stack<pp> &back, int value){
    if(back.empty()){
        back.push({value, value % mod});
        return;
    }

    int currmod;
    currmod = back.top().second;
    back.push({value, (value%mod * currmod%mod)%mod});
}

void deq(stack<pp> &front, stack<pp> &back) {
    if (front.empty()) {
        int currmod = 1;
        while (!back.empty()) {
            auto ele = back.top();
            back.pop();
            // Recalculate product mod while pushing into the front stack
            front.push({ele.first, ((currmod % mod) *( ele.first%mod)) %mod});
            currmod = (currmod % mod) *( ele.first%mod) %mod;
        }
    }
    front.pop();  // Remove the front element
}

int getans(stack<pp> &front, stack<pp> &back){
    if(front.empty()){
        return back.top().second;
    }
    if(back.empty()){
        return front.top().second;
    }
    else{
        return (front.top().second%mod * back.top().second%mod)%mod;
    }
}

void solve(){
    int n;
    cin>>n;
    int k;cin>>k; // size of window
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    stack<pp> front;
    stack<pp> back;

    vector<int> ans;
    int currans = 1;
    for(int i = 0; i<k; i++){ // first window
        enq(front, back, arr[i]);
    }



    ans.push_back(getans(front,back));
    for(int i = k; i<n; i++){
        deq(front,back);
        enq(front,back,arr[i]);
        ans.push_back(getans(front, back));
    }

    for(auto ele : ans){
        cout<<ele<<" ";
    }


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

