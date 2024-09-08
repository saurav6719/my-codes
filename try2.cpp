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
    int n;
    cin>>n;
    vector<int> input(n);
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        maxi = max(maxi , input[i]);
    }

    vector<int> newv(n);
    bool done = false;
    for(int i = 0; i<n; i++){
        if(input[i] == maxi and done ){
            newv[i] = maxi;
            done = true;
        }
        else{
            newv[i] = input[i];
        }
    }

    int currodd = 1;
    int curreven = 2;

    for(int i = 0; i<n; i++){
        if(input[i] % 2 != maxi % 2){
            input[i]++;
            currodd += 2;
        }
    }

    debug(currodd);

    for(int i = 0; i<n; i++){
        int diff = maxi - input[i];
        debug(diff);
        int daysreq = diff /2;
        curreven += (daysreq * 2);
    }

    int lasteven = curreven - 2;
    debug(lasteven);

    while(currodd + 2 < lasteven){
        currodd += 4;
        lasteven -= 2;
    }


    

    int ans1 = max(currodd-2, lasteven);





    int currodd2 = 3;
    int curreven2 = 2;
    int newmaxi = maxi+1;

    for(int i =0; i<n; i++){
        if(newv[i] == maxi){
            newv[i] = newmaxi;
            break;
        }
    }

    for(int i = 0; i<n; i++){
        if(newv[i] % 2 != newmaxi % 2){
            newv[i]++;
            currodd2 += 2;
        }
    }

    // debug(currodd);

    for(int i = 0; i<n; i++){
        int diff = newmaxi - newv[i];
        // debug(diff);
        int daysreq = diff / 2;
        curreven2 += (daysreq * 2);
    }

    int lasteven2 = curreven2 - 2;
    // debug(lasteven);

    debug(lasteven2);

    while(currodd2 + 2 < lasteven2){
        debug(currodd2);
        debug(lasteven2);
        currodd2 += 4;
        lasteven2 -= 2;
    }

    int ans2 = max(currodd2-2, lasteven2);
    debug(ans1);
    debug(ans2);

    cout<<min(ans1, ans2)<<endl;




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

