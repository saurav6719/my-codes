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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

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

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


/* write core logic here */

struct type{
    int left;
    int right;
    int index;
};

bool cmp(type x1, type x2) {
    if (x1.left == x2.left) {
        return x1.right > x2.right;
    }
    return x1.left < x2.left;
}


void solve(){
    int n;
    cin>>n;
    vector<type> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].left>>input[i].right;
        input[i].index = i+1;
    }
    sort(input.begin(), input.end(), cmp);

    ordered_multiset<int> st;
    ordered_multiset<int> st1;


    // for(int i = 0; i<input.size(); i++){
    //     cout<<input[i].left<<" "<<input[i].right<<" "<<input[i].index<<endl;
    // }
    vector<int> contained(n+5,0);
    vector<int> contains(n+5,0);
    for(int i = 0; i<n; i++){
        int r = input[i].right;
        int kam = st.order_of_key(r);
        int ans = st.size()- kam;
        contained[input[i].index] = ans;
        st.insert(input[i].right);
    }

    for(int i = n-1; i>=0; i--){
        int r = input[i].right;
        int ans = st1.order_of_key(r+1);
        contains[input[i].index] = ans;
        st1.insert(input[i].right);
    }

    

    for(int i = 1; i<=n; i++){
        cout<<contains[i]<<" ";
    }


    cout<<endl;

    for(int i = 1; i<=n; i++){
        cout<<contained[i]<<" ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

