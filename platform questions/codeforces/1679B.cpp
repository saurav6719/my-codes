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
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> input(n);
    int t_sum = 0;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        t_sum += input[i];
    }
    int allval =-1;
    set<int>st;
    while(q--){
        int check;
        cin>>check;
        if(allval == -1){
            if(check==1){
                int idx;
                cin>>idx;
                int val;
                cin>>val;
                t_sum -= input[idx-1];
                t_sum+= val;
                input[idx-1] = val;
                st.insert(idx);
            }
            else{
                int val ;
                cin>>val;
                allval = val;
                st.clear();
                t_sum = val * n;
            }
            cout<<t_sum<<endl;
            continue;
        }
        else{
            if(check == 1){
                int idx;
                cin>>idx;
                int val;
                cin>>val;
                if(st.count(idx)){
                    t_sum -= input[idx-1];
                    t_sum += val;
                    input[idx-1] = val;
                }
                else{
                    t_sum -= allval;
                    t_sum += val;
                    input[idx-1] = val;
                }
                st.insert(idx);
            }
            else{
                int val;
                cin>>val;
                allval = val;
                t_sum = val * n;
                st.clear();
            }
            cout<<t_sum<<endl;
            continue;
        }
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

