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

int sumAbsoluteDifferences(const vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int prev = nums[0]; // Previous element

    for (int i = 1; i < n; ++i) {
        int diff = abs(nums[i] - prev);
        sum += diff * i * (n - i); // Update sum with the absolute difference multiplied by the counts of previous and next elements
        prev = nums[i]; // Update previous element
    }

    return sum;
}


void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int> > input(n,vector<int> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
        }
    }

    vector<vector<int > >transpose(m, vector<int> (n));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            transpose[j][i] = input[i][j];
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = 0;
    for(int i = 0; i<m; i++){
        //sort(transpose[i].begin(), transpose[i].end());
        print(transpose[i]);
        ans += sumAbsoluteDifferences(transpose[i]);
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

