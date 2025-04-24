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
    int n;cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int cntsq = 0;
    for(int i = 0; i<n; i++){
        int ele = input[i];
        int xx = sqrt(ele);
        if(xx * xx == ele) cntsq++;
    }

    vector<int> sq(n);
    vector<int> notsq(n);

    for(int i =0; i<n; i++){
        int ele = input[i];
        int xx = sqrt(ele);
        if(xx * xx == ele){
            sq[i] = 0;
            if(ele == 0){
                notsq[i] = 2;
            }
            else notsq[i] = 1;
        }
        else {
            notsq[i] = 0;
            int a = xx * xx;
            int b = (xx+1) * (xx+1);
            sq[i] = min(abs(a-ele), abs(b-ele));
        }
    }
    print(sq);
    print(notsq);

    sort(sq.begin(), sq.end());
    sort(notsq.begin(), notsq.end());



    int notcntsq = n - cntsq;
    if(cntsq == notcntsq){
        cout<<0<<endl;
        return;
    }



    if(cntsq > notcntsq){
        int diff = cntsq - notcntsq;
        int tochange = diff/2;
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(cnt == tochange) break;
            if(notsq[i] == 0) continue;
            ans += notsq[i];
            cnt++;
        }
        cout<<ans<<endl;
        return;
    }

    else{
        int diff = notcntsq - cntsq;
        int tochange = diff/2;
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(cnt == tochange) break;
            if(sq[i] == 0) continue;
            ans += sq[i];
            cnt++;
        }
        cout<<ans<<endl;
        return;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

