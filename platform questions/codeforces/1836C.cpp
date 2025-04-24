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
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    vector<int> nums(8, 0);
    int curr = 1;
    for(int i = 1; i<8; i++){
        nums[i] = curr;
        curr *= 10;
    }

    print(nums);

    vector<int> largest(7, 0);
    for(int i = 1; i<7; i++){
        largest[i] = nums[i+1]-1;
    }

    print(largest);

    int asmallest = nums[a];
    int alargest = largest[a];

    int bsmallest = nums[b];
    int blargest = largest[b];

    int csmallest = nums[c];
    int clargest = largest[c];

    
    int ans1 = -1;
    int ans2 = -1;
    for(int i = asmallest ; i<=alargest; i++){
        int mini = csmallest - i;
        if(mini < bsmallest) mini = bsmallest;
        if(mini > blargest) continue;

        int maxi = clargest - i;
        if(maxi > blargest) maxi = blargest;
        if(maxi < bsmallest) continue;
        int curr = maxi - mini + 1;
        if(curr < k){
            k-= curr;
            continue;
        }
        else{
            ans1 = i;
            ans2 = mini + k-1;
            break;
        }
    }   

    if(ans1==-1 or ans2==-1){
        cout<<-1<<endl;
        return;
    }

    cout<<to_string(ans1)<<" "<<'+'<<" "<<to_string(ans2)<<" "<<'='<<" "<<to_string(ans1+ans2)<<endl;
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

