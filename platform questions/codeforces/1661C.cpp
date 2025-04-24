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


    int lastodd = currodd - 2;

    int lasteven_copy = lasteven;
    int lastodd_copy = lastodd;
    debug(lastodd);
    int diff = lasteven - lastodd;

    bool notasn1 = false;

    if(diff < -1){
        notasn1 = true;
    }

    int times = diff / 6;

    lastodd += (times * 4);
    lasteven -= (times * 2);

    if(lasteven - lastodd == 5){
        lastodd += 4;
        lasteven -= 2;
    }


    

    int ans1 = max(lastodd, lasteven);
    if(notasn1) {
        ans1 = max(lasteven_copy, lastodd_copy);
    }





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
    bool notasn2 = false;

    int lastodd2 = currodd2 - 2;

    int lasteven_copy2 = lasteven2;
    int lastodd_copy2 = lastodd2;


    int diff2 = lasteven2 - lastodd2;

    if(diff2 < -1){
        notasn2 = true;
    }

    int times2 = diff2 / 6;

    lastodd2 += (times2 * 4);
    lasteven2 -= (times2 * 2);

    if(lasteven2 - lastodd2 == 5){
        lastodd2 += 4;
        lasteven2 -= 2;
    }

    

    int ans2 = max(lastodd2, lasteven2);
    debug(ans1);
    debug(ans2);
 
    if(notasn2) {
        ans2 = max(lasteven2, lastodd2);
    }

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

