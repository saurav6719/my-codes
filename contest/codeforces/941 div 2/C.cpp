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
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    set<int> st;
    for(auto ele : input){
        st.insert(ele);
    }

    if(st.size() == 1){
        cout<<"Alice"<<endl;
        return;
    }

    vector<int> newinput;

    for(auto ele: st){
        newinput.push_back(ele);
    }
    //print(newinput);
    vector<int> diff;
    diff.push_back(newinput[0]);

    for(int i = 1; i<newinput.size(); i++){
        diff.push_back(newinput[i] - newinput[i-1]);
    }
    int m = newinput.size();

    //print(diff);

    bool check = false;

    for(auto ele : diff){
        if(ele != 1) {
            check = true;
            break;
        }
    }

    if(!check){
        if(m&1){
            cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;
        return;
    }

    int cnt =0;
    for(int i = 0 ; i<diff.size(); i++){
        if(diff[i] == 1) cnt++;
        else break;
    }

    if(cnt & 1){
        cout<<"Bob"<<endl;
        return;
    }
    else{
        cout<<"Alice"<<endl;
        return;
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

