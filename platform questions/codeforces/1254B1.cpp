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
int f(int n){
    if(n&1){
        int x = n/2;
        //sum of first x even numbers
        return x*(x+1);
    }
    else{
        int x = (n/2)-1;
        return x*(x+1) + x+1;

    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    if(sum==1){
        cout<<-1<<endl;
        return;
    }
    vector<int> factors;
    for(int i=1;i*i<=sum;i++){
        if(sum%i==0){
            if(i!=1) factors.push_back(i);
            if(i!=sum/i){
                if(sum/i != 1) factors.push_back(sum/i);
            }
        }
    }

    sort(factors.begin(),factors.end());
    print(factors);

    vector<int> ones;
    for(int i = 0; i<n; i++){
        if(a[i] == 1)ones.push_back(i);
    }

    print(ones);


    int ans = 1e15;
    for(auto ele : factors){
        int curr =0 ;
        int tomake = ele;
        int start = tomake/2;

        debug(start);

        while(start < ones.size()){
            if(ele & 1){
                for(int i = 1; i<=ele/2; i++){
                    int currenltypresent = ones[start-i];
                    int requiredtopresent = ones[start] - i;
                    curr += abs(currenltypresent - requiredtopresent);
                }
                for(int i = 1; i<=ele/2; i++){
                    int currenltypresent = ones[start+i];
                    int requiredtopresent = ones[start] + i;
                    curr += abs(currenltypresent - requiredtopresent);
                }
            }
            else{
                for(int i = 1; i<=ele/2; i++){
                    int currenltypresent = ones[start-i];
                    debug(currenltypresent);
                    int requiredtopresent = ones[start] - i;
                    debug(requiredtopresent);
                    curr += abs(currenltypresent - requiredtopresent);
                }
                for(int i = 1; i<ele/2; i++){
                    int currenltypresent = ones[start+i];
                    int requiredtopresent = ones[start] + i;
                    curr += abs(currenltypresent - requiredtopresent);
                }
            }

            curr += f(ele);
            start += tomake;
        }

        ans = min(ans,curr);

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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

