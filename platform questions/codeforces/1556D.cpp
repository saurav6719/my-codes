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
    int k;
    cin>>k;

    vector<int> arr;

    cout<<"or "<<1<<" "<<2<<endl;
    cout<<flush;
    int aorb;
    cin>>aorb;

    cout<<endl;

    cout<<"and "<<1<<" "<<2<<endl;
    cout<<flush;

    int aandb;
    cin>>aandb;


    int aplusb = aorb + aandb;

    cout<<"or "<<1<<" "<<3<<endl;
    cout<<flush;

    int aorc;
    cin>>aorc;

    cout<<"and "<<1<<" "<<3<<endl;
    cout<<flush;

    int aandc;
    cin>>aandc;

    int aplusc = aorc + aandc;

    cout<<"or "<<2<<" "<<3<<endl;
    cout<<flush;

    int borc;
    cin>>borc;


    cout<<"and "<<2<<" "<<3<<endl;
    cout<<flush;

    int bandc;
    cin>>bandc;

    int bplusc = borc + bandc;

    int bminusc = aplusb - aplusc;

    int b = (bminusc + bplusc)/2;
    int c = bplusc - b;
    int a = aplusb - b;

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    for(int i = 4; i<=n; i++){
        cout<<"and "<<1<<" "<<i<<endl;
        cout<<flush;

        int aandd;
        cin>>aandd;
        cout<<"or "<<1<<" "<<i<<endl;
        cout<<flush;

        int aord;
        cin>>aord;

        int aplusd = aandd + aord;

        int d = aplusd - a;
        arr.push_back(d);
    }

    sort(arr.begin(), arr.end());

    int ans = arr[k-1];


    cout<<"finish "<<ans<<endl;
    cout<<flush;

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

