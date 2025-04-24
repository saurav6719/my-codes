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
struct triple{
    int a;
    int b;
    int c;
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > input(n, vector<int> (m));
    int totalonecnt =0;
    vector<int> sum(n, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
            if(input[i][j] == 1) {
                totalonecnt++;
                sum[i]++;
            }
        }
    }
    set<pp> visited;



    if(totalonecnt % n != 0) {
        cout<<-1<<endl;
        return;
    }

    int reqonecnt = totalonecnt / n;
    debug(reqonecnt);


    vector<char> plusorminus(n);

    for(int i = 0; i<n; i++){
        if(sum[i] < reqonecnt) plusorminus[i] = '+';
        else if(sum[i] > reqonecnt) plusorminus[i] = '-';
        else plusorminus[i] = '0';
    }

    print(plusorminus);

    set<int> plus;
    set<int> minus;

    for(int i = 0; i<n; i++){
        if(plusorminus[i] == '0') continue;
        if(plusorminus[i] == '-') minus.insert(i);
        else plus.insert(i);
    }


    map<int, set<int> > onesandminus;
    map<int, set<int> > onesandplus;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 1 and minus.count(i)){
                onesandminus[j].insert(i);
            }
            if(input[i][j] == 1 and plus.count(i)){
                onesandplus[j].insert(i);
            }
        }
    }

    map<int, set<int> > zerosandminus;
    map<int, set<int> > zerosandplus;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 0 and minus.count(i)){
                zerosandminus[j].insert(i);
            }
            if(input[i][j] == 0 and plus.count(i)){
                zerosandplus[j].insert(i);
            }
        }
    }

    vector<int> to_change(n);

    for(int i = 0; i<n; i++){
        to_change[i] = abs(sum[i] - reqonecnt);
    }

    vector<triple> res;


    for(int j =0; j<m; j++){
        vector<int> vg;
        vector<int> vl;
        for(int i =0; i<n; i++){
            if(sum[i] > reqonecnt and input[i][j] == 1){
                vg.push_back(i);
            }
            if(sum[i] < reqonecnt and input[i][j] == 0){
                vl.push_back(i);
            }
        }
        for(int i = 0; i<min(vg.size(), vl.size()); i++){
            sum[vg[i]]--;
            sum[vl[i]]++;
            res.push_back({vg[i]+1, vl[i]+1, j+1});
        }
    }
    cout<<res.size()<<endl;

    for(auto ele : res){
        cout<<ele.a<<" "<<ele.b<<" "<<ele.c<<endl;
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

