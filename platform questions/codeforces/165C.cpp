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
    int k;
    cin>>k;
    string str;
    cin>>str;
    int n = str.size();
    vector<int> zerocount(n);

    vector<int> pichlaone;
    vector<int> aglaone;

    bool stillzero = true;

    for(int i =0; i<n; i++){
        if(str[i] == '0'){
            zerocount[i] = zerocount[i-1] +1 ;
        }
        if(str[i] == '1'){
            zerocount[i]  = zerocount[i-1];
        }
    }

    for(int i = 0; i<n; i++){
        if(str[i] == '1'){
            pichlaone.push_back(i);
        }
    }

    if(pichlaone.size() < k){
        cout<<0<<endl;
        return;
    }


    vector<int> consecutivezerolength;
    int curr = 0;
    for(int i = 0; i<n; i++){
        if(str[i] == '0') curr++;
        else{
            consecutivezerolength.push_back(curr);
            curr = 0;
        }
    }

    if(curr > 0) consecutivezerolength.push_back(curr);

    print(consecutivezerolength);
    int kzeroans = 0;
    if(k==0){
        for(int i = 0; i<consecutivezerolength.size(); i++){
            int xx = consecutivezerolength[i];
            kzeroans += ((xx * (xx + 1))/ 2);
        }

        cout<<kzeroans<<endl;
        return;
    }





    int i = 0;
    int j = k-1;
    int ans = 0;

    print(pichlaone);
    while(j<pichlaone.size()){
        int xx = lower_bound(pichlaone.begin(), pichlaone.end() , pichlaone[i]) - pichlaone.begin();
        xx--;
        int left;
        if(xx>=0){
            int pichla = pichlaone[xx];
            left = pichlaone[i] - pichla - 1;
        }
        else left = pichlaone[i];

        int yy = lower_bound(pichlaone.begin(), pichlaone.end() , pichlaone[j]) - pichlaone.begin();
        yy++;
        int right ;
        if(yy < pichlaone.size()){
            int agla = pichlaone[yy];
            right = agla - pichlaone[j] - 1;
        }
        else right = n - 1 - pichlaone[j];

        // debug(i);
        // debug(j);
        // debug(left);
        // debug(right);

        ans += left;
        ans += right;
        ans += (left * right);
        ans ++;

        j++;
        i++;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

