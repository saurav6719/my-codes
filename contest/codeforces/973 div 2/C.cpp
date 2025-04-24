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
    string curr = "0";
    int puch = 0;
    while(curr.size() <= n){
        cout<<"? "<<curr<<endl;
        cout<<flush;

        puch++;

        

        int k;
        cin>>k;

        if(puch == 2*n and k == 0){
            if(curr.back() == '0'){
                string newcurr = curr;
                newcurr.pop_back();
                newcurr += '1';
                cout<<"! "<<newcurr<<endl;
                cout<<flush;
                return;
            }
        }

        if(k){
            if(curr.size() == n) {
                cout<<"! "<<curr<<endl;
                cout<<flush;
                return;
            }
            curr = '0' + curr;
            continue;
        }

        else{
            string newcurr = "";
            for(int j = 1; j<curr.size(); j++){
                newcurr += curr[j];
            }
            curr = newcurr;
            curr = '1' + curr;
        }

        cout<<"? "<<curr<<endl;
        cout<<flush;

        puch++;

        int k2; cin>>k2;

        if(puch == 2*n and k2 == 0){
            if(curr.back() == '0'){
                string newcurr = curr;
                newcurr.pop_back();
                newcurr += '1';
                cout<<"! "<<newcurr<<endl;
                cout<<flush;
                return;
            }
        }

        if(k2){
            if(curr.size() == n){
                cout<<"! "<<curr<<endl;
                cout<<flush;
                return;
            }
            curr = '0' + curr;
            continue;
        }

        else{
            string newcurr = "";
            for(int j = 1; j<curr.size(); j++){
                newcurr += curr[j];
            }
            curr = newcurr;
            break;
        }
    }



    if(curr.size() < n) curr+= '0';
    while(curr.size() <= n){
        // curr += '0';

        cout<<"? "<<curr<<endl;
        cout<<flush;

        puch++;

        int k;
        cin>>k;

        if(puch == 2*n and k == 0){
            if(curr.back() == '0'){
                string newcurr = curr;
                newcurr.pop_back();
                newcurr += '1';
                cout<<"! "<<newcurr<<endl;
                cout<<flush;
                return;
            }
        }

        if(k){
            if(curr.size() == n) {
                cout<<"! "<<curr<<endl;
                cout<<flush;
                return;         
            }
            curr = curr + '0';
            continue;
        }

        else{
            string newcurr = "";
            for(int j = 0; j<curr.size()-1; j++){
                newcurr += curr[j];
            }
            curr = newcurr;
            curr = curr + '1';
        }

        cout<<"? "<<curr<<endl;
        cout<<flush;
        puch++;



        int k2; cin>>k2;

        if(puch == 2*n and k2 == 0){
            if(curr.back() == '0'){
                string newcurr = curr;
                newcurr.pop_back();
                newcurr += '1';
                cout<<"! "<<newcurr<<endl;
                cout<<flush;
                return;
            }
        }

        if(k2){
            if(curr.size() == n) {
                cout<<"! "<<curr<<endl;
                cout<<flush;
                return; 
            }
            curr = curr + '0';
            continue;
        }
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

