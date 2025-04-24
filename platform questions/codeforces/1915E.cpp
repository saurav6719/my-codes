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

    vector<int> odd_sum;
    vector<int> even_sum;
    odd_sum.push_back(input[0]);
    even_sum.push_back(input[1]);
    for(int i = 2;i<n; i++){
        if(i&1){
            even_sum.push_back(even_sum.back() + input[i]);
        }
        else{
            odd_sum.push_back(odd_sum.back() + input[i]);
        }
    }

    print(odd_sum);
    print(even_sum);

    map<int,int> mp;
    vector<int> diff;
    diff.push_back(odd_sum[0]);

    int i = 0;
    int j = 0;
    bool check = false;
    while(i<odd_sum.size() and j<even_sum.size()){
        diff.push_back(odd_sum[i] - even_sum[j]);
        if(! check) {
            check  =true;
            i++;
            continue;
        }
        else{
            check = false;
            j++;
            continue;
        }
    }

    print(diff);


    for(auto ele : diff){
        mp[ele]++;
    }

    for(auto ele : mp){
        if(ele.second >= 2){
            cout<<"YES"<<endl;
            return;
        }
        if(ele.first == 0){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

