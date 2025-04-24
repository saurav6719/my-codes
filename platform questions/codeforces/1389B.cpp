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
    int k;
    cin>>k;
    int z;
    cin>>z;
    vector<int> input(n);
    for(int i =0; i<n; i++){
        cin>>input[i];
    }
    vector<int> prf(n);
    prf[0] = input[0];

    for(int i = 1; i<n; i++){
        prf[i] = prf[i-1] + input[i];
    }

   //print(prf);

    vector<int> ans;

    vector<int> two;

    for(int i = 1; i<n; i++){
        two.push_back(input[i] + input[i-1]);
    }
    //print(two);

    if(z==0){
        cout<<prf[k]<<endl;
        return;
    }

    for(int i = 0; i<two.size(); i++){
        int curr = 0;
        int a = i;
        int start =i+1;
        if(i+1 > k){
            break;
        }

        curr+= prf[start];
        int left = k-a-1;
        int times = min(left/2, z);
        curr += (times * two[i]);
        left -= (times*2);
        int z_copy = z;
        z_copy -= times;
        //debug(curr);
        if(left > 0){
            if(z_copy > 0){
                // debug(input[i]);
                // debug(input[i+2]);
                curr += max(input[i] , ((i+2<n) ? input[i+2] : 0));
                //debug(curr);
                ans.push_back(curr);
                continue;
            }
            else{
                if(i+1+left < n){
                    curr += prf[i+1+left] - prf[i+1];
                    ans.push_back(curr);
                    continue;
                }
            }
        }
        ans.push_back(curr);
    }
    print(ans);

    int curr2 = INT_MIN;

    for(auto ele : ans){
        curr2 = max(ele, curr2);
    }

    cout<<curr2<<endl;

    
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

